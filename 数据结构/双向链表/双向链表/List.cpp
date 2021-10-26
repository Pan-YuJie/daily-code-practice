#include"List.h"

ListNode* BuyListNode(LTDataType x)
{

    ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->data = x;
    newnode->next = NULL;
    newnode->prev = NULL;

    return newnode;
}

ListNode* ListInit()
{
    ListNode*  phead = BuyListNode(0);
    phead->next = phead;
    phead->prev = phead;

    return phead;
}

