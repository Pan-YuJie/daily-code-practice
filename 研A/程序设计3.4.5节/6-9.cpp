#include<stdio.h>
int main()
{
	char str[100];
	gets(str);
	int y=0;
	for(int i=0;str[i]!='\0';i++)
	{
		y=y*10+str[i]-'0';
	}
	printf("%d",y);
	return 0;
}
