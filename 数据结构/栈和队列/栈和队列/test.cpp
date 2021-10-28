#include "StackQueue.h"
#include "Queue.h"

void StackTest()
{
    ST st;
    StackInit(&st);

    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    printf("%d ", StackTop(&st));

    StackPop(&st);
    StackPush(&st, 4);
    StackPush(&st, 5);



    //栈和队列不能随便遍历，严格按照他的性质来取其内容
    while (!StackEmpty(&st))
    {
        printf("%d ", StackTop(&st));

        StackPop(&st);

    }

    StackDestory(&st);

}


void QueueTest()
{
    Queue q;
    QueueInit(&q);//传递结构体,传地址
    
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);

    while (!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");
    
    QueueDestory(&q);
}

int main()
{
   // StackTest();

    QueueTest();

    return 0;
}





