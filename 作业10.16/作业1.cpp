 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 100
int main()
{
	char str1 [MAX];
	char str2 [MAX];
	
	printf("输入两个字符串:\n");
	gets_s(str1);
	gets_s(str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int ret=strcmp(str1, str2);
	if (ret > 0)
	{
		printf("str1大于str2\n");
	}
	else if (ret < 0)
	{
		printf("str1小于str2\n");
	}
	else
	{
		printf("str1等于str2\n");
	}

	printf("第一个字符串长度:%d\n", len1);
	printf("第二个字符串长度:%d\n", len2);

	strcat(str1, str2);
	printf("连接两个字符串:%s\n", str1);

	int len3 = strlen(str1);
	printf("两个字符串的追加字符串的长度:%d\n", len3);

	printf("\n");
	char name1[] = "Smith";
	char name2[] = "Angel";
	int len4 = strlen(name1);
	int len5 = strlen(name2);

	printf("Smith字符串长度:>%d\nAngel字符串长度:>%d\n", len4, len5);



	return 0;
}