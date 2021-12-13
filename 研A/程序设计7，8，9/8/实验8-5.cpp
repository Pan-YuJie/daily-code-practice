#include<stdio.h>
#include<string.h>
int main()
{
	char name[10][10];
	int score[10];
	char tname[10][10];
	printf("请输入人名和分数\n");
	for(int i=0;i<10;i++)
	{
		scanf("%s%d",&name[i],&score[i]);
	}
	for(int i=0;i<10;i++)
	{
		for(int j=i+1;j<10;j++)
		{
			if(score[i]<score[j])
			{
				int t;
				t=score[i];
				score[i]=score[j];
				score[j]=t;
				strcpy(tname[i],name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],tname[i]);
			}
		}
	}
	for(int i=0;i<10;i++)
	{
		printf("%s",name[i]);
		printf(" ");
		printf("%d\n",score[i]);
	}
	return 0;
}
