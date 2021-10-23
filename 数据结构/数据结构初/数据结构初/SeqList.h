#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include<string.h>
#include <assert.h>
#include <stdlib.h>
// #define MAX_SIZE 10
typedef int SQDateType;


typedef struct SeqList
{
    SQDateType* a;
    int size; //有效数据个数
    int cacpcity;//容量
}SL;

//增删查改入口
void SeqListInit(SL* ps);
void SeqListDestory(SL* ps);
int SeqListFind(SL* ps, SQDateType x); 
int SeqListModity(SL* ps, int pos, SQDateType x);

//头插 尾插  头删  尾删  随意插入
void SeqListPushBack(SL* ps, SQDateType x);
void SeqListPushFront(SL* ps, SQDateType x);

void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

void SeqListInsert(SL* ps, int pos, SQDateType x);
void SeqListErase(SL* ps, int pos);


void SeqListPrintf(SL* ps);
void SeqLIstCheckCacpcity(SL* ps);

