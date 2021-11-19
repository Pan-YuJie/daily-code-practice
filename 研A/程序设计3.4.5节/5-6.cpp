#include<stdio.h>
#include<string.h>
int main()
{
	char str1[30];
	char str2[30];
	char str3[30];
	char str4[30];
	printf("请输入四个人名");
	gets(str1);
	gets(str2);
	gets(str3);
	gets(str4);
	if(strcmp(str1,str2)>0)
	{
		char temp[30];
		strcpy(temp,str1);
		strcpy(str1,str2);
		strcpy(str2,temp);
	}
	if(strcmp(str1,str3)>0)
	{
		char temp[30];
		strcpy(temp,str1);
		strcpy(str1,str3);
		strcpy(str3,temp);
	}
	if(strcmp(str1,str4)>0)
	{
		char temp[30];
		strcpy(temp,str1);
		strcpy(str1,str4);
		strcpy(str4,temp);
	}
	if(strcmp(str2,str3)>0)
	{
		char temp[30];
		strcpy(temp,str2);
		strcpy(str2,str3);
		strcpy(str3,temp);
	}
	if(strcmp(str2,str4)>0)
	{
		char temp[30];
		strcpy(temp,str2);
		strcpy(str2,str4);
		strcpy(str4,temp);
	}
	if(strcmp(str3,str4)>0)
	{
		char temp[30];
		strcpy(temp,str3);
		strcpy(str3,str4);
		strcpy(str4,temp);
	}
	printf("%s\n%s\n%s\n%s\n",str1,str2,str3,str4);
	 return 0;
}
