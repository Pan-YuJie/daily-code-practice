#include<stdio.h>
int main()
{
	
	int x,cz;
	printf("请输入x的值\n");
	scanf("%d",&x);
	int a[100]={1,2,3,4,5}; 
	int n=5;
	a[n]=x;
	n++;
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	
	int p,i;
	printf("请输入想要删去的数\n");
	scanf("%d",&p);
	for(i=0;i<n;i++)
	{
		if(a[i]==p)
			break;
	}
	for(int j=i+1;j<n;j++)
	{
		a[j-1]=a[j];
	}
	n--;
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	printf("\n");
	
	int y,t,c;
	printf("请输入想插入的位置\n");
	scanf("%d",&y);
	printf("请输入插入的数字c\n");
	scanf("%d",&c); 
	t=y-1;
	for(int j=n;j>=t;j--)
	{
		a[j]=a[j-1];
	}
	a[t]=c;
	n++;
	for(int i=0;i<n;i++)
	{
		printf("%d",a[i]);
	}
	
	int g;
	 printf("请输入想要查找的数\n");
	 scanf("%d",&cz);
	 for(int j=0;j<n;j++)
	 {
	 	if(a[j]==cz)
	 	{
	 		g=j;
	 		break;
		 }
	 }
	 printf("第%d个数是%d",g+1,cz);
	 return 0;
 } 
