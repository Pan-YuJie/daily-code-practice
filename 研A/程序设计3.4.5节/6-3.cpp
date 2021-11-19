#include<stdio.h>
int main()
{
	int x=1;
	printf("ºÏÊıÓĞ£»\n");
	for(x=1;x<=1000;x++)
	{
		int t=0;
		for(int i=1;i<x;i++)
		{
			if(x%i==0)
			{
				t=t+i;
			}
		}
		
		if(t==x)
			printf("%d",x);
	}
	return 0;
}
