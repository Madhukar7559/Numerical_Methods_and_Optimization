#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double eq(double);
double delta(double, double, double);
double accurary(double, double, double);
int main(void)
{
	cout << "Enter values a and b : " ;
	double l1, l2;
	double n;
	static bool c=0;
	cin >> l1 >> l2;
	cout << "Enter the value of n : ";
	cin >> n;
	double x1, x2, x3;
	x1 = l1;
	n = delta(l1, l2, n);
	x2 = x1 + n;
	x3 = x2 + n;
	cout << endl;
	cout << setprecision(10) << "(" << x1 << ", " << x3 << ")" << endl;
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
		cout << setprecision(10) << "(" << x1 << ", " << x3 << ")" << endl;
	} while(x3 < l2 || x3 == l2);
	if(c==1)
	{
		cout << endl;
		cout << "There are no minimum points in the given domain" << endl;
		cout << endl;
	}
	else
	{
		cout << endl;
		cout << "The minimum point should be in between : ";
		cout << setprecision(10) << "(" << x1 << ", " << x3 << ")" << endl;
		cout << endl;
	}
}
inline double eq(double x)
{
	return exp(x)-pow(x,3);
}
inline double delta(double a, double b, double n)
{
	return (b-a)/n;
}
inline double accurary(double a, double b, double n)
{
	return 2*delta(a,b,n);
}
