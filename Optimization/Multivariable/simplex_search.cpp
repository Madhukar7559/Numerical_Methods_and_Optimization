#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double x[3][2];
void order(void);
void assign(void);
double eq(double, double);
double approx(double*);
int main(void)
{
	double gamma, beta, error, xr[2], xc[2], xtemp[2];
	cin >> gamma >> beta;
	error = 0.0001;
	assign();
	int i=0;
	do
	{
		if((x[0][0]*(x[1][1]-x[2][1])+(x[1][0]*(x[0][1]-x[2][1]))+(x[2][0]*(x[0][1]-x[1][1])))/2 != 0) //area of triangle
		{
			xc[0] = (x[1][0] + x[2][0])/2;// x coordinates
			xc[1] = (x[1][1] + x[2][1])/2;// y coordinates
			xr[0] = (2*xc[0]) - x[0][0];// x coordinates
			xr[1] = (2*xc[1]) - x[0][1];// y coordinates
			if(eq(xr[0],xr[1]) < eq(x[2][0],x[2][1]))
			{
				xtemp[0] = ((1+gamma)*xc[0]) - (gamma*x[0][0]);
				xtemp[1] = ((1+gamma)*xc[1]) - (gamma*x[0][1]);
			}
			if((eq(xr[0],xr[1]) > eq(x[0][0],x[0][1])) || (eq(xr[0],xr[1]) == eq(x[0][0],x[0][1])))
			{
				xtemp[0] = ((1-beta)*xc[0]) + (beta*x[0][0]);
				xtemp[1] = ((1-beta)*xc[1]) + (beta*x[0][1]);				
			}
			if((eq(x[1][0], x[1][1]) < eq(xr[0], xr[1])) && (eq(xr[0], xr[1]) < eq(x[0][0],x[0][1])))
			{
				xtemp[0] = ((1+beta)*xc[0]) - (beta*x[0][0]);
				xtemp[1] = ((1+beta)*xc[1]) - (beta*x[0][1]);
			}
			x[0][0] = xtemp[0];
			x[0][1] = xtemp[1];
			cout << x[0][0] << endl;
			order();// order is going to change to x[0] - worst, x[2] - best. // some problem
		}
		else
		{
			cout << "The taken points will not form a simplex" << endl;
			main();
		}
		/*for(int i=0; i<3; i++)
		{
			cout << x[i][0] << "\t" << x[i][1] << endl;
		}*/
	}while(i<1);
}
void assign(void)
{
	for (int i = 0; i < 3; ++i)
	{
		cin >> x[i][0] >> x[i][1];
	}
}
inline double eq(double x, double y)
{
	return pow(pow(x,2) + y - 11, 2) + pow(pow(y,2) + x - 7, 2);
}
double approx(double xc[])
{
	double sum = 0;
	for(int i = 1; i<=2; i++)
	{
		sum += pow(eq(x[i][0],x[i][1]) - eq(xc[0], xc[1]), 2)/3;
	}
	return sqrt(sum);
}
void order(void)
{
	// eq(x[0] < x[1] < x[2]) is the order of worst point to best point.
	double big = eq(x[0][0], x[0][1]), small = eq(x[0][0], x[0][1]), mid;
	double b[1], s[1], m[1];
	for(int i=0; i<3; i++)
	{
		if(big < eq(x[i][0], x[i][1]))
		{
			big = eq(x[i][0], x[i][1]);
			b[0] = (x[i][0]);
			b[1] = (x[i][1]);
		}
	}
	for(int i=0; i<3; i++)
	{
		if(small > eq(x[i][0], x[i][1]))
		{
			small = eq(x[i][0], x[i][1]);
			s[0] = (x[i][0]);
			s[1] = (x[i][1]);
		}
	}
	for(int i=0; i<3; i++)
	{
		if(small != eq(x[i][0], x[i][1]) && big != eq(x[i][0], x[i][1]))
		{
			mid = eq(x[i][0], x[i][1]);
			m[0] = (x[i][0]);
			m[1] = (x[i][1]);
		}
	}
	x[0][0] = s[0]; x[0][1] = s[1];
	x[1][0] = m[0]; x[1][1] = m[1];
	x[2][0] = b[0]; x[2][1] = b[1];
}
