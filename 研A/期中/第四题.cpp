#include <stdio.h>

int main()
{
	int n=0;
	int m=0;
	
	 
	scanf("%d%d",&n,&m);
	
	for(int i=0;i<n && i<9;i++)
	{	
		 
		for(int j=0;j<m && j<9;j++)
		{
			printf("*");
		}
		
		printf("\n");
		
		for(int k=0;k<=i;k++)
		{
			printf(" ");
		}
		
	}
	
} 
