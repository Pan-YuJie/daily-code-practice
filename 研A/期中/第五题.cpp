#include<stdio.h>
#include<assert.h>

int my_strstr(const char* str1, const char* str2);

int main()
{
	char str1[] = "abbbchjdfdj";
	char str2[] = "bc";
	
	gets(str1);
	gets(str2); 
	
	int ret = my_strstr(str1, str2);

	if (ret == NULL)
	{
		printf("找不到\n");
	}
	else if(ret==-1)
	{
		printf("所输入查找的字符串是空字符串('\\0')");	
	} 
	else 
	{
		printf("首次出现的位置是%d\n", ret);
	}

	return 0;
}

int my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	
	char* cur = (char*)str1;
	
	const char* p1 = NULL;
	const char* p2 = NULL;
	
	int find=1;
	
	if(*str2=='\0')
	{
		return -1;	
	}
	 
	while (*cur != '\0')
	{
		p1 = cur;
		p2 = str2;
		
		while ((*p1 == *p2) && (*p1 != '\0') && (*p2 != '\0'))
		{
			p1++; 
			p2++;
		}
		
		if (*p2 == '\0')
		{
			return find;//找到字符串的情况
		}
		
		cur++;
		find++; 
		
	}
	
	return NULL;//找不到字符的情况
}
