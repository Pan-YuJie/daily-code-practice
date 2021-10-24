 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>

int main()
{
	int count = 0;
	char str1[30];
	gets_s(str1);

	char* p = str1;

	while (*p)
	{
		if (*p == 'a')
		{
			count++;
		}
		p++;
	}

	printf("%d", count);
	
	return 0;
}