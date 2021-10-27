#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int  STDataType;

//使用数组实现 动态栈
typedef struct Stack
{
    STDataType* a;
    int top;
    int cacpcity;

}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);

//栈顶 插入、删除数据
//入栈
void StackPush(ST* ps, STDataType x);
//出栈
void StackPop(ST* ps);

STDataType StackTop(ST* ps);
int StackSize(ST* ps);
int StackEmpty(ST* ps);
