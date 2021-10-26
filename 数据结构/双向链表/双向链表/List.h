#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;

typedef  struct ListNode
{
    struct ListNode* prev;
    struct ListNode* next;
    LTDataType data;

}ListNode;



ListNode* ListInit();

void ListDestory(ListNode* plist);

void ListPushFront(ListNode* plist,LTDataType x);
void ListPushBack(ListNode* plist, LTDataType x);