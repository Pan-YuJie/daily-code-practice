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

void SListPushBack(SLTNode** pphead, SLTDataType x);
//void SListPushBack(SLTNode*& pphead, SLTDataType x)//C++ÒýÓÃ
void SListPushFront(SLTNode** pphead, SLTDataType x);

void SListPopFront(SLTNode** pphead);
void SListPopBack(SLTNode** pphead);

void SListInsert(SLTNode** pphead,SLTNode* pos,SLTDataType x);
void SListErase(SLTNode** pphead, SLTNode* pos);

SLTNode* SListFind(SLTNode* phead, SLTDataType x);
SLTNode* BuySListNode(SLTDataType x);
