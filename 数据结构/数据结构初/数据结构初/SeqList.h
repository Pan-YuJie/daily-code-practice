
#include <stdio.h>
#include<string.h>
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
void SeqListInit(SL* ps);//初始化

//头插 尾插  头删  尾删
void SeqListPushBack(SL* ps, SQDateType x);
void SeqListPushFront(SL* ps, SQDateType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

void SeqListPrintf(SL* ps);
void SeqLIstCheckCacpcity(SL* ps);