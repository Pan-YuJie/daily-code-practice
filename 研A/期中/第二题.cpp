#include <stdio.h>

int Max(int* arr,int n)
{
	
	int max=arr[0];
	
	for(int i=0;i<n;i++)
	{
		if(arr[i]<0)
		{
			arr[i]=-arr[i];
		
		}
		
		if(max<arr[i])
		{
			max=arr[i];
		}
	}
	
	return max;
	
}

int main()
{
	int n=0;
	
	scanf("%d",&n);
	
	int arr[n]={0};	
	
	for(int i=0;i<n;i++)
	{
	scanf("%d",&arr[i]);
	} 
	
	
	int a=Max(arr,n);
	
	
	printf("整数中绝对值最大值是%d",a);
	
} 
