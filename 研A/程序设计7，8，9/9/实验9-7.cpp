#include<stdio.h>
int main()
{
	int A[100][100];
	int B[100][100];
	int C[100][100];
	int i,j,k,m,n;
	printf("������m,k��ֵ\n");
	scanf("%d%d",&m,&k);
	printf("������m��k�е�A����\n");
	for( i=0;i<m;i++)
	{
		for( j=0;j<k;j++)
		{
			scanf("%d",&A[i][j]);
		}
	}
		printf("������k,n��ֵ\n");
	scanf("%d%d",&k,&n);
	printf("������k��n�е�B����\n");
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
