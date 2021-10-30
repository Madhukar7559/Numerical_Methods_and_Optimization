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
    cout << "Enter initial guess and increment" << endl; 
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
    y = x + (twos(k)*del);
    while(eq(y) < eq(x))
    {
        k++;
        w=x;
        x=y;
        y = x + (twos(k)*del);
    }
    cout << w << "\t" << y << endl;
}
inline double mod(double x)
{
    return x>0 ? x:-x;
}
inline double eq(double x)
{
	return pow(x,2) + (54/x);
}
inline double twos(double x)
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