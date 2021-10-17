 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 100
int main()
{
	char str1[MAX] ;

	gets_s(str1);

	char* p = str1;
	
	int cnt = 1;

	while (*p)
	{
		if (*p == ' ')
		{
			cnt =cnt+1;
		}

		p++;
	}

	printf("ÓÐ%dµ¥´Ê", cnt);

	return 0;
}