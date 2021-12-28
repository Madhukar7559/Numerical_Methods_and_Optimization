#include <iostream>
#include <math.h>
#include <iomanip>
// Still in progress
using namespace std;
double eq(double);
double pos(double);
int main(void)
{
    double a,b, x1, x2, xm, L, error;
    cout << "Enter Lower and Upper Boundary : ";
    cin >> a >> b;
    cout << "Enter the error : ";
    cin >> error;
    xm = (a+b) / 2;
    L = b-a;
    cout << endl;
    cout << "(" << a << ", " << b << ")" << endl;
    do
    {
        x1 = a + (L/4);
        x2 = b - (L/4);
        if(eq(x1) < eq(xm))
        {
            b = xm;
            xm = x1;
        }
        else
        {
            if(eq(x2) < eq(xm))
            {
                a = xm;
                xm = x2;
            }
            else
            {
                a=x1;
                b=x2;
            }
        }
        L = b - a;
        cout << "(" << a << ", " << b << ")" << endl;
    }while(pos(L) > error);
    cout << endl;
    cout << "Minimum Point should be in between : ";
    cout << "(" << a << ", " << b << ")" << endl;
    cout << endl;
}
inline double eq(double x)
{
	return (2*(x - 2)*exp(x - 2)) - pow(x + 3, 2);
}
inline double pos(double x)
{
    return (x>0) ? x:-x;
}
