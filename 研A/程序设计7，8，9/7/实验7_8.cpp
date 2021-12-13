#include<stdio.h>
#include<math.h>
int main()
{
	double x=1.5,fx=0,fx_;
	fx=3*x*x*x-9*x*x+3*x-9;
	while(fabs(fx)>0.000001)
	{
	    fx=3*x*x*x-9*x*x+3*x-9;
	    fx_=9*x*x-18*x+3;
	    x=x-fx/fx_;
	}
	printf("%lf\n",x);
	return 0;
}
