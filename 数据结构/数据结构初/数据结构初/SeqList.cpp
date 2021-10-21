 #define _CRT_SECURE_NO_WARNINGS 1

#include "seqList.h"

void SeqLIstCheckCacpcity(SL* ps)
{
	//ÅÐ¶Ï±íÂú¾ÍÀ©ÈÝ
	if (ps->size == ps->cacpcity)
	{
		int newcacpcity = ps->cacpcity == 0 ? 4 : ps->cacpcity * 2;

		SQDateType* tmp = (SQDateType*)realloc(ps->a, newcacpcity * 2 * sizeof(SQDateType));

		if (tmp == NULL)
		{
			printf("realloc is fail\n");
			exit(-1);
		}

		else
		{
			ps->a = tmp;
			ps->cacpcity = newcacpcity;
		}
	}
}

//³õÊ¼»¯
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->cacpcity = 0;

}

//Î²²å
void SeqListPushBack(SL* ps, SQDateType x)
{
	SeqLIstCheckCacpcity(ps);

	ps->a[ps->size] = x;
	ps->size++;

}

void SeqListPrintf(SL* ps)
{
	for (int i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");

}

//Í·²å
void SeqListPushFront(SL* ps, SQDateType x)
{

	SeqLIstCheckCacpcity(ps);

	int end = ps->size - 1;
	int start = 0;
	while (end>=start)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}

	ps->a[0] = x; 
	ps->size++;

}

void SeqListPopBack(SL* ps, SQDateType x)
{

}
void SeqListPopFront(SL* ps, SQDateType x)
{

}

