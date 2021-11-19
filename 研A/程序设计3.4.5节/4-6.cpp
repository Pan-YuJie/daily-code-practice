#include<stdio.h>
int main()
{
	int a[4]={0};
	
	printf("请输入四个整数");
	for(int i=0;i<4;i++)
	{
		scanf("%d",&a[i]);
	 } 
	 for(int j=0;j<4;j++)
	 {
	 	for(int m=j;m<4;m++)
	 	{
	 		if(a[j]>a[m])
	 		{
	 			int temp;
	 			temp=a[j];
	 			a[j]=a[m];
	 			a[m]=temp;
			 }
		 }
	 }
	 for(int i=0;i<4;i++)
	 {
	 	printf("%d",a[i]);
	 }
	 return 0;
 } 
