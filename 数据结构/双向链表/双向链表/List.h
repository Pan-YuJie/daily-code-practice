#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;


//��ͷ˫��ѭ������----> ���ŵ�����ṹ ---> ������λ�ò���ɾ�����ݶ��� O(1)
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

//ɾ��posλ�õ�ֵ
void ListErase(ListNode* pos);

//��pos��λ��ǰ����x
void ListInsert(ListNode* pos, LTDataType x);


