#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int  STDataType;

//ʹ������ʵ�� ��̬ջ
typedef struct Stack
{
    STDataType* a;
    int top;
    int cacpcity;

}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);

//ջ�� ���롢ɾ������
//��ջ
void StackPush(ST* ps, STDataType x);
//��ջ
void StackPop(ST* ps);

STDataType StackTop(ST* ps);
int StackSize(ST* ps);
int StackEmpty(ST* ps);
