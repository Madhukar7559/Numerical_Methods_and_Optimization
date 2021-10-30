#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double val(double, double);
double eq(double);
double mod(double);
int main(void)
{
    double a,b,c;
	cout << "Enter the value of a : ";
	cin >> a;
	cout << "Enter the value of b : ";
	cin >> b;
    int i=0;
    if(eq(a) != eq(b))
    {
        do
        {
            c=val(a,b);
            if(i%2 != 0)
            {
                a=c;
            }
            else
            {
                b=c;
            }
            i++;
            cout << setprecision(7) << c << endl;
        } while(mod(eq(c)) > 0.00001);
    }
    else
    {
        cout << "The secant will not cross the x-axis"<< endl;
    }
    cout << "Root : " << setprecision(4) << c << endl;
    cout << "Number of iterations : " << i << endl;
}
inline double val(double x, double y)
{
    return (x - (eq(x) * (x-y) / (eq(x) - eq(y))));
}
inline double eq(double x)
{
	return exp(x)*((x*x)-5*x+6)+1;
}
double mod(double ans)
{
	if(ans < 0)
	{
		return -(ans);
	}
	else
	{
		return ans;
	}
}