#include<stdio.h>
#include<string.h> 
int main()
{
	char name[100][100];
	char tname[100];
	int n;
	printf("������n��ֵ\n");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%s",name[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(strcmp(name[i],name[j])>0)
			{
			/*	tname=name[i];
				name[i]=name[j];
				name[j]=tname;������ʽ 
				ע�⣡�ַ�������ֱ�Ӹ�����������*/
				strcpy(tname,name[i]);
				strcpy(name[i],name[j]);
				strcpy(name[j],tname);
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%s",name[i]);
	}
	return 0;
}

