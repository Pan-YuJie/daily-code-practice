#include<stdio.h>
int main()
{
	
	int x,cz;
	printf("������x��ֵ\n");
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
	printf("��������Ҫɾȥ����\n");
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
	printf("������������λ��\n");
	scanf("%d",&y);
	printf("��������������c\n");
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
	 printf("��������Ҫ���ҵ���\n");
	 scanf("%d",&cz);
	 for(int j=0;j<n;j++)
	 {
	 	if(a[j]==cz)
	 	{
	 		g=j;
	 		break;
		 }
	 }
	 printf("��%d������%d",g+1,cz);
	 return 0;
 } 
