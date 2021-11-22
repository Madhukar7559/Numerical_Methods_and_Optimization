#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double eq(double);
double pos(double);
int main(void)
{
    double a,b, x1, x2, xm, L, error;
    cout << "Enter Upper Boundary : ";
    cin >> a;
    cout << "Enter Lower Boundary : ";
    cin >> b;
    cout << "Enter the error : ";
    cin >> error;
    xm = (a+b) / 2;
    L = b-a;
    x1 = a + (L/4);
    x2 = b - (L/4);
    double i = 0;
    while(i < 10)
    {
        if(eq(x1) < eq(xm))
        {
            b = xm;
            xm = x1;
        }
        else if(eq(x2) < eq(xm))
        {
            a = xm;
            xm = x2;
        }
        else
        {
            a=x1;
            b=x2;
        }
        L = b - a;
        i++;
    }
    cout << a << " " << b << endl;
}
inline double eq(double x)
{
	return pow(x,2) + (54/x);
}
inline double pos(double x)
{
    return (x>0) ? x:-x;
}