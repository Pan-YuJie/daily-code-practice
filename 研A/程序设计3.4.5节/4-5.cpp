#include<stdio.h>
int main()
{
	int a[4];
	printf("请输入三个整数");
	for(int i=0;i<3;i++)
	{
		scanf("%d",&a[i]);
	}
	 
	 for(int j=0;j<3;j++)
	 {
	 	for(int m=j;m<3;m++)
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
	 
	 for(int i=0;i<3;i++)
	 {
	 	printf("%d",a[i]);
	 }
	 return 0;
 } 
