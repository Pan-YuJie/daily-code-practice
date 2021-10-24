#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<assert.h>
int my_strcmp(const char* p1, const char* p2)
{
	assert(p1 && p2);

	while (*p1 == *p2)
	{
		if (*p1 == 0)
		{
			return 0;
		}
		p1++;
		p2++;
	}

	if (*p1 > *p2)
	{
		return 1;
	}

	else
	{
		return -1;
	}

}
	

int main()
{
		
	char p1[30];
	char p2[30];

	gets_s(p1);
	gets_s(p2);

	int ret = my_strcmp(p1, p2);

	printf("ret = %d", ret);
	

	return 0;
}