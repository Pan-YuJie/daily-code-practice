#include "StackQueue.h"

void Test()
{
    ST st;
    StackInit(&st);

    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);
    StackPush(&st, 5);



    //ջ�Ͷ��в������������ϸ�������������ȡ������
    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));

        StackPop(&st);

    }

    StackDestory(&st);

}


int main()
{
    Test();

    return 0;
}





