#include <stdio.h>
int main()
{
	char pp;
	printf("输入一个字符");
	pp=getchar();
	if(pp>='A'&&pp<='Z')
	printf("大写字母"); 
	else if(pp<='9'&&pp>='0')
	printf("数字");
	else if(pp>='a'&&pp<='z')
	printf("小写字母");
	else
	printf("其他"); 
 
 } 
