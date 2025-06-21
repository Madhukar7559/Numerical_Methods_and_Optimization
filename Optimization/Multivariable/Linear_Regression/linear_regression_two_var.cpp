#include <cmath>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

double eq(double y, double x1, double x2, double w0, double w1, double w2, 
          double x1_sq, double x2_sq, double x1x2, double y_x1, double y_x2, 
          double y_sq, int num_rows);
double partial_w0(double y, double x1, double x2, double w0, double w1, double w2, 
                  double x1_sq, double x2_sq, double x1x2, double y_x1, double y_x2, 
                  double y_sq, int num_rows);
double partial_w1(double y, double x1, double x2, double w0, double w1, double w2, 
                  double x1_sq, double x2_sq, double x1x2, double y_x1, double y_x2, 
                  double y_sq, int num_rows);
double partial_w2(double y, double x1, double x2, double w0, double w1, double w2, 
                  double x1_sq, double x2_sq, double x1x2, double y_x1, double y_x2, 
                  double y_sq, int num_rows);

const int MAX_ROWS = 400;

int main()
{
    double horsepower[MAX_ROWS];
    double weight[MAX_ROWS];
    double mpg[MAX_ROWS];
    int num_rows = 0;

    ifstream file("auto-mpg.csv");
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return 1;
    }

    string line;
    while (getline(file, line) && num_rows < MAX_ROWS) {
        sscanf(line.c_str(), "%lf,%lf,%lf", 
               &horsepower[num_rows], &weight[num_rows], &mpg[num_rows]);
        num_rows++;
    }
    file.close();

    
    cout << "Read " << num_rows << " rows:" << endl;
    for (int i = 0; i < num_rows; i++) {
        cout << "Row " << i + 1 << ": Horsepower = " << horsepower[i] 
             << ", Weight = " << weight[i] 
             << ", MPG = " << mpg[i] << endl;
    }
    
    double w0 = 0; // Initial guess
    cout << "w0 initial guess : ";
    cin >> w0;
    double w1 = 0; // Initial guess
    cout << "w1 initial guess : ";
    cin >> w1;
    double w2 = 0; // Initial guess
    cout << "w2 initial guess : ";
    cin >> w2;
    double x1 = 0;
    double x2 = 0;

    double y_sq = 0, x1_sq = 0, x2_sq = 0, x1x2 = 0, y_x1 = 0, y_x2 = 0, y = 0;

    for (int i = 0; i < num_rows; i++)
    {
        y_sq += pow(mpg[i], 2);
        x1_sq += pow(horsepower[i], 2);
        x2_sq += pow(weight[i], 2);
        x1x2 += (horsepower[i] * weight[i]);
        y_x1 += (mpg[i] * horsepower[i]);
        y_x2 += (mpg[i] * weight[i]);
        x1 += horsepower[i];
        x2 += weight[i];
        y += mpg[i];
    }
    
    // Gradient descent
    double alpha; // Learning rate
    cout << "alpha initial guess : ";
    cin >> alpha;
    
    int iter = 0;
    double w0_new = 0;
    double w1_new = 0;
    double w2_new = 0;
    double error = 0.001;

    do
    {
        iter++;
        cout << "iteration : " << iter << endl;
        w0_new = w0 - (alpha * partial_w0(y, x1, x2, w0, w1, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows));
        w1_new = w1 - (alpha * partial_w1(y, x1, x2, w0, w1, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows));
        w2_new = w2 - (alpha * partial_w2(y, x1, x2, w0, w1, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows));
        w0 = w0_new;
        w1 = w1_new;
        w2 = w2_new;
        cout << setprecision(10) << "w0 : " << w0 << endl;
        cout << setprecision(10) << "w1 : " << w1 << endl;
        cout << setprecision(10) << "w2 : " << w2 << endl;
        cout << endl;
        cout << endl;
    }
    while (sqrt(pow(partial_w0(y, x1, x2, w0, w1, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows), 2) + 
                pow(partial_w1(y, x1, x2, w0, w1, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows), 2) + 
                pow(partial_w2(y, x1, x2, w0, w1, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows), 2)) > error);
    
    cout << "optimal weights after gradient descent ==> ";
    cout << "w0 : " << w0 << " w1 : " << w1 << " w2 : " << w2 << endl;
    return 0;
}

double eq(double y, double x1, double x2, double w0, double w1, double w2, 
          double x1_sq, double x2_sq, double x1x2, double y_x1, double y_x2, 
          double y_sq, int num_rows)
{
    return y_sq + (pow(w1, 2) * x1_sq) + (pow(w2, 2) * x2_sq) + 
           (num_rows * pow(w0, 2)) + (2 * w1 * w2 * x1x2) + 
           (2 * w0 * w1 * x1) + (2 * w0 * w2 * x2) - 
           (2 * y_x1 * w1 + 2 * y_x2 * w2 + 2 * y * w0);
}

double partial_w0(double y, double x1, double x2, double w0, double w1, double w2, 
                  double x1_sq, double x2_sq, double x1x2, double y_x1, double y_x2, 
                  double y_sq, int num_rows)
{
    return (eq(y, x1, x2, w0 + 0.001, w1, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows) - 
            eq(y, x1, x2, w0 - 0.001, w1, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows)) / (2 * 0.001);
}

double partial_w1(double y, double x1, double x2, double w0, double w1, double w2, 
                  double x1_sq, double x2_sq, double x1x2, double y_x1, double y_x2, 
                  double y_sq, int num_rows)
{
    return (eq(y, x1, x2, w0, w1 + 0.001, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows) - 
            eq(y, x1, x2, w0, w1 - 0.001, w2, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows)) / (2 * 0.001);
}

double partial_w2(double y, double x1, double x2, double w0, double w1, double w2, 
                  double x1_sq, double x2_sq, double x1x2, double y_x1, double y_x2, 
                  double y_sq, int num_rows)
{
    return (eq(y, x1, x2, w0, w1, w2 + 0.001, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows) - 
            eq(y, x1, x2, w0, w1, w2 - 0.001, x1_sq, x2_sq, x1x2, y_x1, y_x2, y_sq, num_rows)) / (2 * 0.001);
}
