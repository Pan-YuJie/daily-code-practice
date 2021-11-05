#include<stdio.h>
#include<string.h>

int main()
{

		char str[30]="hellohellossssss";
		printf("输入一个字符串\n");
		
		gets(str);
		 
		int len = strlen(str);

		int cnt[26] = { 0 };

		for (int i = 0; i < len; i++)
		{
			
			int a = str[i] - 97;
			 
			cnt[a]++;
		}

		for (int i = 0; i < 26; i++) 
		{
			
			if (cnt[i] != 0) 
			{
				printf("字符:%c出现%d次\n",(char)(i + 97) , cnt[i]);
				
			}
			
		}

		return 0;
}




	
