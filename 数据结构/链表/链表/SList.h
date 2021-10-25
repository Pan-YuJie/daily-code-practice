#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>

typedef int SLTDataType;
typedef struct SListNode
{
     SLTDataType data;
     struct SListNode* next;
}SLTNode;

void SListPrintf(SLTNode* phead);

void SListPushBack(SLTNode** phead, SLTDataType x);
//void SListPushBack(SLTNode*& pphead, SLTDataType x)//C++ÒýÓÃ
void SListPushFront(SLTNode** phead, SLTDataType x);

void SListPopFront(SLTNode** phead);
void SListPopBack(SLTNode** phead);

void SListInsert(SLTNode** phead);
void SListErase(SLTNode** phead);




SLTNode* BuySListNode(SLTDataType x);
