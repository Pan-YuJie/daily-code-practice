#include<stdio.h>
#include<assert.h>
//1.计数器实现求字符串长度函数
	int my_strlen1(const char* str)//整个过程不改变指针指向内容，加上const
{
	assert(str != NULL);//加上断言，防止接收空指针
	int count = 0;
	while (*str != '\0')//也可以直接用while(*str)
	{
		count++;
		str++;
	}
	return count;
}

//2.递归实现求字符串长度，不用创建临时变量
int my_strlen2(const char* str)
{
	assert(str != NULL);
	if (*str != '\0')//也可以直接用if(*str)
	{
		return 1 + strlen(str + 1);
	}
	else
		return 0;
}

//3.指针-指针得到中间元素的个数，实现求字符串长度
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

