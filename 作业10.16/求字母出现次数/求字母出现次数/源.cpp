 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<string.h>


int main()
{

		char str[30]="hellohellossssss";
		int len = strlen(str);

		int cnt[26] = { 0 };

		for (int i = 0; i < len; i++)
		{
			
			int a = str[i] - 97;//����aΪ���ҵ���Ӧ��ĸ��ASCII��97
			 
			cnt[a]++;
		}

		for (int i = 0; i < 26; i++) 
		{
			
			if (cnt[i] != 0) 
			{
				printf("�ַ�:%c����%d��\n",(char)(i + 97) , cnt[i]);
				
			}
			
		}

		return 0;
}




	
