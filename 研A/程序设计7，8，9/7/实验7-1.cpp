#include<stdio.h>
int main()
{
	int i,j;
	for(i=1;i<=9;i++)
	{
		for(j=1;j<=i;j++)
		{
			int t=i*j;
			printf("%d*%d=%-2d ",j,i,t);
		}
		printf("\n");
	}
	return 0;
 } 
