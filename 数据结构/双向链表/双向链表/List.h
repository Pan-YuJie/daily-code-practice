#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;


//带头双向循环链表----> 最优的链表结构 ---> 在任意位置插入删除数据都是 O(1)
typedef  struct ListNode
{
    struct ListNode* prev;
    struct ListNode* next;
    LTDataType data;

}ListNode;



ListNode* ListInit();

void ListDestory(ListNode* plist);
void ListPrintf(ListNode* plist);

void ListPushFront(ListNode* plist,LTDataType x);
void ListPushBack(ListNode* plist, LTDataType x);

void ListPopBack(ListNode* plist);
void ListPopFront(ListNode* plist);

ListNode* ListFind(ListNode* phead,LTDataType x);
ListNode* ListModify(ListNode* phead, LTDataType x, LTDataType y);

//删除pos位置的值
void ListErase(ListNode* pos);

//在pos的位置前插入x
void ListInsert(ListNode* pos, LTDataType x);


