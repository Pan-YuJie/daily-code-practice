 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>

#define MAX 100

int main()
{
	char str1[MAX] ;

	gets_s(str1);

	char* p = str1;
	
	int cnt = 0;
	int flag = 0;
	while (*p)
	{
		if (*p == ' ')//�����ո��������ж�
		{
			flag = 0;
		}

		else if(flag==0)//�����¸��ַ��Ž���
		{
			flag = 1;
			cnt++;
		}

		p++;
	}

	printf("��%d����", cnt);

	return 0;
}