#include<stdio.h>
int main()
{
	double sum=0,pi,t;
	int n=1;
	while(n<10000000)
	{
		if(n%2==0)
			t=-1.0/(2*n-1);
		if(n%2!=0)
			t=1.0/(2*n-1);
		sum=sum+t;
		n++;
	}
	pi=4*sum;
	printf("%.7lf",pi);
	return 0;
}
