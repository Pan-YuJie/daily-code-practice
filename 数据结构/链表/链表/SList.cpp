#include "SList.h"

void SListPushBack(SLTNode** pphead, SLTDataType x)//����ָ��**������ַ �� C++���� *&
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    newnode->data = x;
    newnode->next = NULL;

    if (*pphead == NULL)
    {
        *pphead = newnode;
    }

    else
    {

        SLTNode* tail = *pphead;
        while (tail->next != NULL)//�ҵ�β�ڵ��ָ��
        {
            tail = tail->next;
        }

        //β�������½ڵ�
        tail->next = newnode;
    }
} 


void SListPushFront(SLTNode** pphead, SLTDataType x)
{

    SLTNode* newnode = BuySListNode(x);

    newnode->next = *pphead;
    *pphead = newnode;

}


SLTNode* BuySListNode(SLTDataType x)
{
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));

    newnode->next = NULL;
    newnode->data = x;

    return newnode;
}


void SListPrintf(SLTNode* phead)
{
    SLTNode* cur = phead;
    while (cur != NULL)
    {
        printf("%d->", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}


void SListPopFront(SLTNode** pphead)
{
    SLTNode* next = (*pphead)->next;
    
    free(*pphead);

    *pphead = next;

}


void SListPopBack(SLTNode** pphead)
{
    //1.��
    if (*pphead == NULL)
    {
        return;
    }

    //2.ֻ��һ���ڵ�
    else if ((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }

    //3.��һ�����ϵĽڵ�
    else
    {
        SLTNode* tail = *pphead;
        SLTNode* prev = NULL;
        while (tail->next != NULL)
        {
            prev = tail;
            tail = tail->next;

        }

        free(tail);
        prev->next = NULL;
    }
}

  










