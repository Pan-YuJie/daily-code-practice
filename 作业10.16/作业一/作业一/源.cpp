 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 100
int main()
{
	char str1 [MAX];
	char str2 [MAX];
	
	printf("���������ַ���:\n");
	gets_s(str1);
	gets_s(str2);

	int len1 = strlen(str1);
	int len2 = strlen(str2);

	int ret=strcmp(str1, str2);
	if (ret > 0)
	{
		printf("str1����str2\n");
	}
	else if (ret < 0)
	{
		printf("str1С��str2\n");
	}
	else
	{
		printf("str1����str2\n");
	}

	printf("��һ���ַ�������:%d\n", len1);
	printf("�ڶ����ַ�������:%d\n", len2);

	strcat(str1, str2);
	printf("���������ַ���:%s\n", str1);

	int len3 = strlen(str1);
	printf("�����ַ�����׷���ַ����ĳ���:%d\n", len3);

	printf("\n");
	char name1[] = "Smith";
	char name2[] = "Angel";
	int len4 = strlen(name1);
	int len5 = strlen(name2);

	printf("Smith�ַ�������:>%d\nAngel�ַ�������:>%d\n", len4, len5);



	return 0;
}