#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;
double eq(double, double);
double partial_x(double, double);
double partial_y(double, double);
double mod(double);

int main()
{
	double x, y, alpha;
	cout << "Enter Initial Guess x y : ";
	cin >> x >> y; // model parameters
	cout << "alpha time : ";
	cin >> alpha; //learning rate
	cout << endl;
	int i = 0;
	double xnew = 0;
	double ynew = 0;
	double error = 0.001; //stopping error critera
	double xprev;
	double yprev;
	do
	{
		xprev = x;
		yprev = y;
		i++;
		//cout << "iteration = " << i << endl;
		xnew = x - (alpha * partial_x(x, y));
		ynew = y - (alpha * partial_y(x, y));
		x = xnew;
		y = ynew;
		cout << setprecision(10) << "(" << x << ", " << y << ")" << endl;
	}
	while (mod(eq(x,y) - eq(xprev, yprev)) > error) // magnitude of gradient > error is also a stopping condition idk why? but gotta know why?
	cout << endl;
	cout << "Total Iterations : " << i << endl; 
	cout << setprecision(10) << "Final optimal = (" << x << ", " << y << ")" << endl;
	return 0;
}

double eq(double x, double y)
{
	//return pow(pow(x,2) + y - 11, 2) + pow(pow(y,2) + x - 7, 2);
	return pow(x, 2) + pow(y, 2);
}

double partial_x(double x, double y)
{
	return (eq(x + 0.001, y) - eq(x - 0.001, y))/(2*0.001); // del == h == 0.001
}

double partial_y(double x, double y)
{
	return (eq(x, y + 0.001) - eq(x, y - 0.001))/(2*0.001); // del == h == 0.001
}

double mod(double x)
{
	return (x < 0) ? -x:x;
}
