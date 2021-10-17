 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>

#include<assert.h>

//1.计数器
int my_strlen1(const char* str)
{
	assert(str != NULL);

	int count = 0;
	while (*str != '\0')
	{
		count++;
		str++;
	}
	return count;
}

//2.递归实现
int my_strlen2(const char* str)
{
	assert(str != NULL);

	if (*str != '\0')
	{
		return 1 + my_strlen2(str+1);
	}

	else
		return 0;
}

//3.指针-指针
int my_strlen3(const char* str)
{
	assert(str != NULL);
	const char* tmp = str;

	while (*str != '\0')
	{
		str++;
	}
	return str - tmp;

}

int main()
{
	char arr[] = "abcdefgh";

	int ret1 = my_strlen1(arr);//1.计数器方法
	int ret2 = my_strlen2(arr);//2.递归方法
	int ret3 = my_strlen3(arr);//3.指针 - 指针方法

	printf("%d\n", ret1);
	printf("%d\n", ret2);
	printf("%d\n", ret3);
	return 0;
}