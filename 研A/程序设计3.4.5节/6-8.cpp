#include<stdio.h>
int main()
{
	char str[100];
	int count;
	printf("������һ��Ӣ����ĸ\n"); 
	gets(str);
	char pre=' ',ch;
	for(int i=0;str[i]!='\0';i++)
	{
		ch=str[i];
		
		if(pre==' '&&ch!=' ')
		{
			count++;
		}
		
		pre=ch;
	}
	printf("%d",count);
	
 } 
