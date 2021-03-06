#include "SList.h"

void SListPushBack(SLTNode** pphead, SLTDataType x)//二级指针**，传地址 或 C++引用 *&
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
        while (tail->next != NULL)//找到尾节点的指针
        {
            tail = tail->next;
        }

        //尾节链接新节点
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
    //1.空
    if (*pphead == NULL)
    {
        return;
    }

    //2.只有一个节点
    else if ((*pphead)->next == NULL)
    {
        free(*pphead);
        *pphead = NULL;
    }

    //3.有一个以上的节点
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

  
SLTNode* SListFind(SLTNode* phead,SLTDataType x)
{
    SLTNode* cur = phead;

    while (cur != NULL)
    {

        if (cur->data == x)
        {
            return cur;
        }

        cur = cur->next;

    }

    return NULL;

}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
    //相当于头插
    if (pos == *pphead)
    {
        SListPushFront(pphead,x);
    }

    else
    {
        SLTNode* prev = *pphead;
        SLTNode* newnode = BuySListNode(x);
        while (prev->next != pos)
        {
            prev = prev->next;
        }

        prev->next = newnode;
        newnode->next = pos;
    }
}


void SListErase(SLTNode** pphead, SLTNode* pos)
{
    if (pos == *pphead)
    {

        SListPopFront(pphead);

    }

    else
    {
        SLTNode* prev = *pphead;
        while (prev->next != pos)
        {
            prev = prev->next;
        }

        prev->next = pos->next;
        free(pos);

    }

}







