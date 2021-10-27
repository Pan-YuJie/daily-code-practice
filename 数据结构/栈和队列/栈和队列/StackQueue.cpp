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

    ps->top = 0;//初始top为0，意味着，top指向栈顶元素下一个
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


//栈顶 插入、删除数据
//入栈
void StackPush(ST* ps,STDataType x)
{

    assert(ps);

    //满了-》增容
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

//出栈
void StackPop(ST* ps)
{
    
    assert(ps);
    //栈空了，调用Pop，终止程序
    assert(ps->top>0);

    ps->top--;

}
 

STDataType StackTop(ST* ps)
{
    assert(ps);
    //栈空了，调用Top，终止程序
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
