#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double eq(double);
double delta(double, double, double);
double accurary(double, double, double);
int main(void)
{
	double l1, l2;
	double n;
	static bool c=0;
	cin >> l1 >> l2 >> n;
	double x1, x2, x3;
	x1 = l1;
	n = delta(l1, l2, n);
	x2 = x1 + n;
	x3 = x2 + n;
	do
	{
		if(eq(x1) > eq(x2) && eq(x2) < eq(x3))
		{
			break;
		}
		x1 = x2;
		x2 = x3;
		x3 = x2 + n;
		if(x3 > l2)
		{
			c=1;
		}
	} while(x3 < l2 || x3 == l2);
	if(c==1)
	{
		cout << "There are no minimum points" << endl;
	}
	else
	{
		cout << setprecision(10) << x1 << "\t" << x3 << endl;
	}
}
inline double eq(double x)
{
	return pow(x,3) - 48*x;
}
inline double delta(double a, double b, double n)
{
	return (b-a)/n;
}
inline double accurary(double a, double b, double n)
{
	return 2*delta(a,b,n);
}