
#include <stdio.h>
#include<string.h>
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
void SeqListInit(SL* ps);//��ʼ��

//ͷ�� β��  ͷɾ  βɾ
void SeqListPushBack(SL* ps, SQDateType x);
void SeqListPushFront(SL* ps, SQDateType x);
void SeqListPopBack(SL* ps);
void SeqListPopFront(SL* ps);

void SeqListPrintf(SL* ps);
void SeqLIstCheckCacpcity(SL* ps);