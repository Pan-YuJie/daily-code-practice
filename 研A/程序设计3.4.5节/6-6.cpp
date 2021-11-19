#include<stdio.h>
int main()
{
	int x=1;
	int k=0;
	printf("ËØÊıÓĞ£»\n");
	for(x=1;x<=1000;x++)
	{
			int count=0;
		for(int i=1;i<x;i++)
		{
			if(x%i==0)
			{
				count++;
			}
		}
		if(count==1)
		{	printf("%d",x);
			k++;
			if(k%5==0)
				printf("\n");
		}
		
	}
	return 0;
}
