#include<stdio.h>
#include<math.h>
int main()
{
	double a=-10,b=10,t;
	double fa,fb,ft;
    fa=3*a*a*a-9*a*a+3*a-9;
    fb=3*b*b*b-9*b*b+3*b-9;
    if(fa*fb<0)
    {
    	while(fabs(fa)>=0.00000001)
    	{
    		t=(a+b)/2.0;
    	    ft=3*t*t*t-9*t*t+3*t-9;
    	    if(fa*ft>0)
    	    a=t;
    	    else
    	    b=t;
    	    fa=3*a*a*a-9*a*a+3*a-9;
            fb=3*b*b*b-9*b*b+3*b-9;
    	}
    	printf("¸ùÎª%lf\n",a);
    }
	return 0;
}
