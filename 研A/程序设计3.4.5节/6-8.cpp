#include<stdio.h>
int main()
{
	char str[100];
	int count;
	printf("请输入一行英文字母\n"); 
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
