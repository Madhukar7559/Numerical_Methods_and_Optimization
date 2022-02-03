#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double double_derivative(double, double);
double single_derivative(double, double);
double eq(double);
double mod(double);
int main()
{
    double x, error, y;
    cout << endl;
    cout << "Enter intial guess value and error : "; 
    cin >> x >> error;
    int k=1;
    cout << endl;
    cout << setprecision(10) << "k = " << k << " " << " x = " << x << " " << " f'(x) = " << single_derivative(x, 0.001) << " " << " f''(x) = " << double_derivative(x, 0.001) << endl;
    do
    {
        y = x - (single_derivative(x, 0.001)/double_derivative(x, 0.001));
        x = y;
        k++;
        cout << setprecision(10) << "k = " << k << " " << " x = " << x << " " << " f'(x) = " << single_derivative(x, 0.001) << " " << " f''(x) = " << double_derivative(x, 0.001) << endl;
    } while (mod(single_derivative(y, 0.001)) > error);
    cout << endl;
    cout << "Minimum point : " << "(" << x << ", " << eq(x) << ")" << endl;
    cout << endl;
    return 0;
}
inline double eq(double x)
{
    return pow(x,2)-(10*exp(0.1*x));
}
inline double single_derivative(double x, double del)
{
    return (eq(x + del) - eq(x - del))/(2*del);
}
inline double double_derivative(double x, double del)
{
    return (eq(x + del) + eq(x - del) - (2*eq(x)))/(pow(del,2));
}
inline double mod(double x)
{
    return (x < 0) ? -x:x;
}