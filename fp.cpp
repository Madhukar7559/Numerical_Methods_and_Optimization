#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double eq(double);
double val(double, double);
double mod(double);
double check(double, double, double);
int main(void)
{
	double a,b,c,t;
	cout << "Enter the value of a : ";
	cin >> a;
	cout << "Enter the value of b : ";
	cin >> b;
    int i=0;
	do
	{
		c = val(a,b);
        if(eq(a) != 0 && eq(b) != 0 && eq(c) != 0)
        {
            if(eq(a) * eq(c) < 0)
            {
                b=c;
            }
            else
            {
                a=c;
            }
        }
        else
        {
        	if(eq(a) == 0)
            {
                    c=a;
                    break;
            }
            else if(eq(b) == 0)
            {
                    c=b;
                    break;
            }
            else
            {
                break;
            }
        }
        i++;
        cout << setprecision(9) << c << endl;
	} while(mod(eq(c)) > 0.001);
    cout << "Root : " << setprecision(3) << c << endl;
    cout << "Number of iterations : " << i << endl;
}
inline double eq(double x)
{
    return ;
}
inline double val(double a, double b)
{
	return (b - eq(b) * ( (b - a) / (eq(b) - eq(a)) ));
}
double mod(double x)
{
	if(x < 0)
	{
		return -x;
	}
	else
	{
		return x;
	}
}