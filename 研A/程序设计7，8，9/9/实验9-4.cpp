#include<stdio.h>
int main()
{
	int yh[10][10];
	for(int i=0,j=0;i<10,j<10;i++,j++)
	{
		yh[i][j]=1;
		yh[i][0]=1;
	}
	for(int i=2;i<=10;i++)
	{
		for(int j=1;j<i;j++)
		{
			yh[i][j]=yh[i-1][j]+yh[i-1][j-1];
		}
	}
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<=i;j++)
		{
			printf("%d",yh[i][j]);
		}
		printf("\n");
	}
	return 0;
}
