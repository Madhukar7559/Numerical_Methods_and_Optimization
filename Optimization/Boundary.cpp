#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;
double mod(double);
double eq(double);
double twos(double);
static int k=0;
int main(void)
{
    double x, del, y=0, w=0;// w == f(x-1), y == f(x+1), x == f(x)
    cout << "Enter initial guess and increment : "; 
    cin >> x >> del;
    if( (eq(x - mod(del)) > eq(x) || eq(x - mod(del)) == eq(x)) && ( eq(x) > eq(x + mod(del)) || eq(x) == eq(x + mod(del)) ))
    {
        // positive
    }
    else if( (eq(x - mod(del)) < eq(x) || eq(x - mod(del)) == eq(x)) && ( eq(x) < eq(x + mod(del)) || eq(x) == eq(x + mod(del)) ))
    {
        del = -del;
    }
    else
    {
        cout << "Re-enter" << endl;
        main();
    }
    cout << endl;
    cout << "(" << w << ", " << y << ")" << endl;
    y = x + (twos(k)*del);
    while(eq(y) < eq(x))
    {
        k++;
        w=x;
        x=y;
        y = x + (twos(k)*del);
        cout << "(" << w << ", " << y << ")" << endl;
    }
    cout << endl;
    cout << "The interval in which the minimum point lie : ";
    cout << "(" << w << ", " << y << ")" << endl;
    cout << endl;
}
inline double mod(double x)
{
    return x>0 ? x:-x;
}
inline double eq(double x)
{
	return 0.1*pow(pow(x,2)-(3*x)+5,2) + pow(x-3,2);
}
double twos(double x)
{
    int p=1;
    if(x != 0)
    {
        for(int i=0; i<x; i++)
        {
            p=p*2;
        }
        return p;
    }
    else
    {
        return 1;
    }
}
