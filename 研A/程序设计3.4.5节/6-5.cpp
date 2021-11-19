#include <stdio.h>
int main()
{
	int n,a; 
	double sum1,sum2;
	scanf("%d",&n);
	sum1=0;
	sum2=0;
	for(int i=1;i<=n;i++)
	{
		a+=i;
		sum1=1.0/a;
		
		sum2+=sum1; 
	}
	printf("%lf",sum2);
	
 } 
