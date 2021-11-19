#include<stdio.h>
int main()
{
	int n,i,j,k;
	printf("ÇëÊäÈënµÄÖµ\n");
	scanf("%d",&n);
	int m=(n+1)/2;
	
	for(int i=1;i<=m;i++)
	{
		for(j=0;j<m-i;j++)
		{
			printf(" ");
		}
		for(k=0;k<2*i-1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
	
	for(int i=m-1;i>0;i--)
	{
		for(j=0;j<m-i;j++)
		{
			printf(" ");
		}
		for(k=0;k<2*i-1;k++)
		{
			printf("*");
		}
		printf("\n");
	}
 	}

