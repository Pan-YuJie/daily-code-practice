#include<stdio.h>
int main()
{
	int a[6];
	printf("请输入六个数"); 
	for(int i=0;i<6;i++)
	{
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<6;i++)
	{
		for(int j=i+1;j<6;j++)
		{
			if(a[i]>a[j])
			{
				int t;
				t=a[i];
				a[i]=a[j];
				a[j]=t;
			}
		}
	}
	
	printf("最小值为%d，最大值为%d",a[0],a[5]);
	return 0;
}
