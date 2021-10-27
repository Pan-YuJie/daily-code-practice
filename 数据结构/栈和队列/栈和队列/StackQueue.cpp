#include "StackQueue.h"

void StackInit(ST* ps)
{
    assert(ps);

    ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);

    if (ps->a == NULL)
    {
        printf("realloc fail\n");
        exit(-1);
    }

    ps->top = 0;//��ʼtopΪ0����ζ�ţ�topָ��ջ��Ԫ����һ��
    ps->cacpcity = 4;

}


void StackDestory(ST* ps)
{

    assert(ps);

    free(ps->a);
    ps->a = NULL;
    ps->top = 0;
    ps->cacpcity = 0;

}


//ջ�� ���롢ɾ������
//��ջ
void StackPush(ST* ps,STDataType x)
{

    assert(ps);

    //����-������
    if (ps->top == ps->cacpcity)
    {
        STDataType* tmp = (STDataType*)realloc(ps->a, ps->cacpcity * 2 * sizeof(STDataType));

        if (tmp == NULL)
        {
            printf("realloc fail\n");
            exit(-1);
        }

        else
        {
            ps->a = tmp;
            ps->cacpcity *= 2;

        }

    }

    ps->a[ps->top] = x;
    ps->top++;

}

//��ջ
void StackPop(ST* ps)
{
    
    assert(ps);
    //ջ���ˣ�����Pop����ֹ����
    assert(ps->top>0);

    ps->top--;

}
 

STDataType StackTop(ST* ps)
{
    assert(ps);
    //ջ���ˣ�����Top����ֹ����
    assert(ps->top > 0);

    return ps->a[ps->top - 1];
}

int StackSize(ST* ps)
{

    assert(ps);

    return ps->top;
}


int StackEmpty(ST* ps)
{
    assert(ps);

    return ps->top == 0;

}  
