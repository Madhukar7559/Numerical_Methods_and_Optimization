#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;
double check(double, double, double);
double eq(double);
double mod(double);
int main(void)
{
	double a,b,y;
	double x;
	cout << "Enter the value of a : ";
	cin >> a;
	cout << "Enter the value of b : ";
	cin >> b;
	int i=0;
	if(eq(a)*eq(b) < 0)
	{
		do
		{
			x=(a+b)/2;
			y=check(a,b,x);
			if(y==0)
			{
				b=x;
			}
			else
			{
				a=x;
			}
			if(y==2)
			{
				x=a;
				break;
			}
			if(y==3)
			{
				x=b;
				break;
			}
			if(y==4)
			{
				break;
			}
			i++;
			cout << setprecision(8) << x << endl;
		}while(mod(eq(x)) > 0.001);	
		cout << "The root is : " << setprecision(8) << x << endl;
		cout << "Number of iterations : " << i << endl;
	}
	else
	{
		cout << "The given intervel has no roots or even number of roots" << endl;
	}
}
inline double eq(double x)
{
	return pow(x,3)-pow(x,2)-x-1;
}
double check(double a, double b, double x)
{
	if(eq(a)!=0 && eq(b)!=0 && eq(x)!=0)
	{
		if(eq(a)*eq(x) < 0)
			return 0;
		else
			return 1;
	}
	else
	{
		if(eq(a)==0)
		{
			return 2;
		}
		if(eq(b)==0)
		{
			return 3;
		}
		else
		{
			return 4;
		}
	}
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
