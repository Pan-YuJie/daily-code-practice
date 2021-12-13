#include<stdio.h>
int main()
{
	int jz[5][5];
	printf("ÇëÊäÈëÒ»¸ö¾ØÕó\n");
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
			{
				scanf("%d",&jz[i][j]);
			}
	}
	int sum1=0;
	for(int i=0,j=0;i<5,j<5;i++,j++)
	{
		sum1=sum1+jz[i][j];
	}
	int sum2=0;
	for(int i=4,j=4;i>=0,j>=0;i--,j--)
	{
		sum2=sum2+jz[i][j];
	}
	printf("sum1=%d,sum2=%d",sum1,sum2);
	return 0;
}
