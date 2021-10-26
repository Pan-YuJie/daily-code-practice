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

void ListPrintf(ListNode* phead)
{
    ListNode* cur = phead->next;
    while (cur != phead)
    {
        printf("%d ", cur->data);

        cur = cur->next;
    }
    printf("\n");
}

void ListPushBack(ListNode* phead, LTDataType x)
{

    assert(phead);

    ListNode* tail = phead->prev;
    ListNode* newnode = BuyListNode(x);

    newnode->next = phead;
    phead->prev = newnode;
    newnode->prev = tail;
    tail->next = newnode;

}

void ListPushFront(ListNode* phead,LTDataType x)
{
    ListNode* newnode = BuyListNode(x);
    ListNode* first = phead->next;

    phead->next = newnode;
    newnode->next = first;

}


void ListPopBack(ListNode* phead)
{
    assert(phead);
    assert(phead->next != phead);

    ListNode* tail = phead->prev;
    //tail->prev->next = phead;
    //phead->prev = tail->prev
    
    ListNode* prev = tail->prev;
    prev->next = phead;
    phead->prev = prev;

    free(tail);
    tail = NULL;

}

void ListPopFront(ListNode* phead)
{
    assert(phead);
    assert(phead->next!=phead);

    ListNode* first = phead->next;
    ListNode* second = first->next;

    phead->next = second;
    second->prev = phead;

    free(first);
    first = NULL;

}


ListNode* ListFind(ListNode* phead, LTDataType x)
{
    assert(phead);
    ListNode* cur = phead->next;

    while (cur != phead)
    {
        if (cur->data == x)
        {
            return cur;
        }

        cur = cur->next;
    }

    return NULL;

}

//查找附带修改作用
ListNode* ListModify(ListNode* phead, LTDataType x,LTDataType y)
{
    assert(phead);
    ListNode* cur = phead->next;

    while (cur != phead)
    {
        if (cur->data == x)
        {
            cur->data = y;
        }

        cur = cur->next;
    }

    return NULL;
}
                    
void ListInsert(ListNode* pos, LTDataType x)
{
    assert(pos);
    ListNode* newnode = BuyListNode(x);
    ListNode* prev = pos->prev;

    prev->next = newnode;
    newnode->prev = prev;
    newnode->next = pos;
    pos->prev = newnode;

}


void ListErase(ListNode* pos)
{
    assert(pos);

    ListNode* prev = pos->prev;
    ListNode* next = pos->next;

    prev->next = next;
    next->prev = prev;

    free(pos);
    pos = NULL;
}

void ListDestory(ListNode* phead)
{
    assert(phead);

    ListNode* cur = phead->next;
    
    while (cur != phead)
    {
        ListNode* next = cur->next;
        free(cur);
        cur=next;
    }

    free(phead);
    phead = NULL;

}

