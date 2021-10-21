 #define _CRT_SECURE_NO_WARNINGS 1
#include "seqList.h"

void TestSeqList1()
{
	SL sl;
	SeqListInit(&sl);
	SeqListPushBack(&sl, 1);
	SeqListPushBack(&sl, 2);
	SeqListPushBack(&sl, 3);
	SeqListPushBack(&sl, 4);
	SeqListPushBack(&sl, 5);
	SeqListPushBack(&sl, 6);

	SeqListPrintf(&sl);
	
	SeqListPushFront(&sl,1);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 1);
	SeqListPushFront(&sl, 1);

	SeqListPrintf(&sl);
}

int main()
{
	TestSeqList1();


	return 0;
}


