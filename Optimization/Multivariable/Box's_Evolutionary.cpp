#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double eq(double, double);
double magnitude(double, double);
void order(double (*)[2], double *);
int main()
{
    double x[5][2], delta[2];
    double error = 0.001;
    cout << "Enter initial guess : ";
    cin >> x[0][0] >> x[0][1];
    cout << "Enter delta value : ";
    cin >> delta[0] >> delta[1];
    while(magnitude(delta[0], delta[1]) > error)
    {
        x[1][0] = x[0][0] + (delta[0]/2); x[1][1] = x[0][1] + (delta[1]/2);
        x[2][0] = x[0][0] + (delta[0]/2); x[2][1] = x[0][1] - (delta[1]/2);6 6
        x[3][0] = x[0][0] - (delta[0]/2); x[3][1] = x[0][1] + (delta[1]/2);
        x[4][0] = x[0][0] - (delta[0]/2); x[4][1] = x[0][1] - (delta[1]/2);
        order(x,delta);
	cout << "Minimum point : " << setprecision(10) << x[0][0] << " " << x[0][1] << endl;
        cout << setprecision(10) << magnitude(delta[0], delta[1]) << endl;
    }
    cout << endl;
    cout << "Minimum point is " << setprecision(10) << x[0][0] << " " << x[0][1] << endl;
    cout << endl;
    return 0;
}
inline double eq(double x, double y)
{
	return pow(pow(x,2) + y - 11, 2) + pow(pow(y,2) + x - 7, 2);
}
inline double magnitude(double x, double y)
{
    return sqrt(pow(x,2) + pow(y,2));
}
void order(double x[5][2], double delta[])
{
    double t=eq(x[0][0], x[0][1]), xnew[2];
    for (int i = 0; i <= 4; i++)
    {
        if(t > eq(x[i][0],x[i][1]))
        {
            t = eq(x[i][0],x[i][1]);
            xnew[0] = x[i][0];
            xnew[1] = x[i][1];
        }
    }
    if(t == eq(x[0][0], x[0][1]))
    {
        for (int i = 0; i < 2; i++)
        {
            delta[i] = (delta[i]/2);
        }
    }
    else
    {
        x[0][0] = xnew[0];
        x[0][1] = xnew[1];
    }
}
