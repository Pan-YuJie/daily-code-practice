#include <stdio.h>
int main()
{
	char pp;
	printf("����һ���ַ�");
	pp=getchar();
	if(pp>='A'&&pp<='Z')
	printf("��д��ĸ"); 
	else if(pp<='9'&&pp>='0')
	printf("����");
	else if(pp>='a'&&pp<='z')
	printf("Сд��ĸ");
	else
	printf("����"); 
 
 } 
