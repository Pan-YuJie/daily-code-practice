#include<stdio.h>
int main()
{
	double sum;
	int i=1,j=2,k,n;
	for(n=0;n<40;n++)
	{
		sum=(double)j/i;
		k=i;
		i=j;
		j=j+k;
	}
	printf("数列前40项的和为%lf",sum);
	return 0;
}
