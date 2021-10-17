 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
char* my_strcat(char* dest, const char* src)
{
	assert(dest != NULL);
	assert(src != NULL);

	char* dest_start = dest;

	//1.找到目的空间中的'\0'
	while (*dest != '\0')
	{
		dest++;
	}

	//2.追加
	while (*dest++ = *src++)
	{
		;
	}

	return dest_start;
}

int main()
{
	char arr1[30];
	char arr2[30];
	gets_s(arr1);
	gets_s(arr2);

	my_strcat(arr1, arr2);

	printf("%s", arr1);
	return 0;
}