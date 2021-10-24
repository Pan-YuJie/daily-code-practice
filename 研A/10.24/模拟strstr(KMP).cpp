#include<stdio.h>
#include<assert.h>

char* my_strstr(const char* str1, const char* str2);

int main()
{
	char str1[] = "abbbchjdfdj";
	char str2[] = "bc";
	char* ret = my_strstr(str1, str2);

	if (ret == NULL)
	{
		printf("找不到\n");
	}
	else
	{
		printf("%s", ret);
	}

	return 0;
}

char* my_strstr(const char* str1, const char* str2)
{
	assert(str1 != NULL);
	assert(str2 != NULL);
	char* cur = (char*)str1;
	const char* p1 = NULL;
	const char* p2 = NULL;
	if (*str2 == '\0')
		return (char*)str1;
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
			return cur;//找到字符串的情况
		}
		cur++;
	}
	return NULL;//找不到字符的情况
}
