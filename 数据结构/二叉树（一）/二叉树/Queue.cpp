#include "Queue.h"

void QueueInit(Queue* pq)
{
    assert(pq);
    pq->head = NULL;
    pq->tail = NULL;

}


void QueueDestory(Queue* pq)
{
    assert(pq);

    QNode* cur = pq->head;
    while (cur)
    {
        QNode* next = cur->next;
        free(cur);
        cur = next;
    }

    pq->head = pq->tail = NULL;

}

void QueuePush(Queue* pq, QDataType x)
{
    assert(pq);

    QNode* newnode = (QNode*)malloc(sizeof(QNode));
    if (newnode == NULL)
    {
        printf("malloc failed\n");
        exit(-1);
    }

    //��ʼ���ڵ�
    newnode->data = x;
    newnode->next = NULL;

    //���ͷΪ��
    if (pq->head == NULL)
    {
         pq->tail = newnode;
         pq->head = newnode;
    }

    else
    {
        pq->tail->next = newnode;
        pq->tail = newnode;
    }

}

void QueuePop(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    //һ���Ͷ���ڵ�
    if (pq->head->next == NULL)
    {
        free(pq->head);
        pq->tail = NULL;
        pq->head = NULL;
    }
   
        
    else
    {
        QNode* next = pq->head->next;
        free(pq->head);
        pq->head = next;
    }   

}

//�����Ƚ��ȳ�
bool QueueEmpty(Queue* pq)
{
    assert(pq);
    return pq->head == NULL;

}

QDataType QueueFront(Queue* pq)
{
    assert(pq);
    assert(pq->head);

    return pq->head->data;
}

int  QueueSize(Queue* pq)
{
    assert(pq);
    int size = 0;

    QNode* cur = pq->head;

    while (cur)
    {
        size++;
        cur=cur->next;
    }

    return size;
}