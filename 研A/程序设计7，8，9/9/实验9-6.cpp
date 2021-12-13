#include<stdio.h>
int main()
{
	int a[3][4];
	printf("ÇëÊäÈëÒ»¸ö¾ØÕó\n");
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<4;j++)
		{
			scanf("%d",&a[i][j]); 
		}
	}
	for(int j=0;j<4;j++)
	{
		for(int i=0;i<3;i++)
		{
			printf("%3d",a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
