#include <stdio.h>

int Sum ( int* List, int N )
{
  int sum=0;
  for(int i=0;i<N;i++)
  {
    sum+=*(List+i);
  }
  
  return sum;
}


int main()
{
	int n=0; 
	scanf("%d",&n);
	
	int List[n]={0};
	
	for(int i=0;i<n;i++)
	scanf("%d",&List[i]);
	
	int sum=Sum(List,n);
	
	printf("%d\n",sum);
	
	return 0;
 } 
