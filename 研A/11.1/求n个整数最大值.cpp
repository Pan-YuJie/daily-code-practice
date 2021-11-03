#include <stdio.h>

int Max(int* p,int n)
{

	int max=*(p); 
	for(int i=1;i<n;i++)
	{
		if(max<*(p+i))
		{
			max=*(p+i);
		}
		
	}
	return max;
}


int main()
{
	
	int n=0; 
	scanf("%d",&n);
	
	int p[n]={0};
	
	for(int i=0;i<n;i++)
	scanf("%d",&p[i]);
	
	int max=Max(p,n);
	
	printf("%d\n",max);
	
	return 0;
} 
