#include<stdio.h>
int main()
{
	int n;
	printf("������n��ֵ");
	scanf("%d",&n); 
	int a[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	int max;
	max=a[0];
	for(int i=1;i<n;i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	printf("���ֵΪ%d\n",max);
	int min;
	min=a[0];
	for(int i=1;i<n;i++)
	{
		if(min>a[i])
		{
			min=a[i];
		}
	}
	printf("��СֵΪ%d\n",min);
	int sum=0;
	for(int i=0;i<n;i++)
	{
		sum=sum+a[i];
	}
	printf("��Ϊ%d\n",sum);
	double average;
	average=sum/n;
	printf("ƽ��ֵΪ%.2lf\n",average);
	return 0;
}
