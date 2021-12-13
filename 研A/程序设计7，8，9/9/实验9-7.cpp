#include<stdio.h>
int main()
{
	int A[100][100];
	int B[100][100];
	int C[100][100];
	int i,j,k,m,n;
	printf("请输入m,k的值\n");
	scanf("%d%d",&m,&k);
	printf("请输入m行k列的A矩阵\n");
	for( i=0;i<m;i++)
	{
		for( j=0;j<k;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
		printf("请输入k,n的值\n");
	scanf("%d%d",&k,&n);
	printf("请输入k行n列的B矩阵\n");
	for(i=0;i<k;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d",&B[i][j]);
		}
	}
	int t;
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			C[i][j]=0;
			for(t=0;t<k;t++)
			{
				C[i][j]+=A[i][t]*B[t][i];
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d",C[i][j]);
		}
		printf("\n");
	}
	return 0;
	
}
