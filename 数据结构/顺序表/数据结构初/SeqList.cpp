#include "seqList.h"

void SeqLIstCheckCacpcity(SL* ps)
{
	//�жϱ���������
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

//��ʼ��
void SeqListInit(SL* ps)
{
	ps->a = NULL;
	ps->size = 0;
	ps->cacpcity = 0;
}

//β��
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

//ͷ��
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

//βɾ
void SeqListPopBack(SL* ps)
{
	assert(ps->size > 0);//size������0�Ͷ�����

	// ps->a[ps->size - 1] = 0; ���п���
	ps->size--;

}	

//ͷɾ
void SeqListPopFront(SL* ps)
{
	assert(ps->size > 0);

	int start = 1;
	while (start < ps->size)
	{
		ps->a[start-1] = ps->a[start];
		start++;
	}
	ps->size--;

}

//
void SeqListInsert(SL* ps, int pos, SQDateType x)
{
	assert(pos< ps->size );
	SeqLIstCheckCacpcity(ps);

	int end = ps->a[ps->size - 1];
	while (end <= pos)
	{
		ps->a[end + 1] = ps->a[end];
		end--;

	}

	ps->a[pos] = x;
	ps->size++;
}



void SeqListErase(SL* ps, int pos)
{
	assert(pos < ps->size);
	int start = pos+1;
	while (start <ps->size )
	{
		ps->a[start-1] = ps->a[start];
		start++;
	}

	ps->size--;
}



int SeqListFind(SL* ps, SQDateType x)
{
	for (int i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}

	return -1;

}

int SeqListModity(SL* ps, int pos, SQDateType x)
{
	assert(pos < ps->size);

	ps->a[pos] = x;

	return 0;
}



