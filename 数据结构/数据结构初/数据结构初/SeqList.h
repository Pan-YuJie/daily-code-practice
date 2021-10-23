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
    int size; //��Ч���ݸ���
    int cacpcity;//����
}SL;

//��ɾ������
void SeqListInit(SL* ps);
void SeqListDestory(SL* ps);
int SeqListFind(SL* ps, SQDateType x); 
int SeqListModity(SL* ps, int pos, SQDateType x);

//ͷ�� β��  ͷɾ  βɾ  �������
void SeqListPushBack(SL* ps, SQDateType x);
void SeqListPushFront(SL* ps, SQDateType x);

void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

void SeqListInsert(SL* ps, int pos, SQDateType x);
void SeqListErase(SL* ps, int pos);


void SeqListPrintf(SL* ps);
void SeqLIstCheckCacpcity(SL* ps);

