#include<stdio.h>
#include<string.h>
int main()
{
	char a[100];
	gets(a);
	int n;
	n=strlen(a);
	char t;
	if(n%2==0)
	{
		for(int i=0;i<n/2;i++)
		{
		t=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=t;
		}
	}
	if(n%2!=0)
	{
		int m=(n+1)/2;
		for(int i=0;i<m;i++)
		{
		t=a[i];
		a[i]=a[n-1-i];
		a[n-1-i]=t;
		}
	}
	puts(a);
	
}
