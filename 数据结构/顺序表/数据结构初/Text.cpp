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
	
	SeqListPopBack(&sl);
	SeqListPopBack(&sl);

	SeqListPrintf(&sl);

	SeqListPopFront(&sl);
	SeqListPopFront(&sl);

	SeqListPrintf(&sl);

	SeqListInsert(&sl, 1, 20);
	SeqListInsert(&sl, 2, 30);

	SeqListPrintf(&sl);

	SeqListErase(&sl, 2);

	SeqListPrintf(&sl);

	SeqListModity(&sl, 2, 55);

	SeqListPrintf(&sl);

	int Findpos=SeqListFind(&sl , 55);
	
	printf("�±�Ϊ%d\n", Findpos);

}


void meau()
{
	printf("********************************************\n");
	printf("(1).ͷ������         (2).β������\n");
	printf("(3).ͷɾ����         (4).βɾ����\n");
	printf("(5).��ӡ����         (6).��������\n");
	printf("(7).����λ�ò�������  (8).����λ��ɾ������\n");
	printf("(9).����λ���޸�����  (-1).�˳�����\n");
	printf("********************************************\n");

	printf("\n**��������Ĳ���ѡ��:>**\n");

}



int main()
{
	int option = 0;
	int x = 0;
	int y = 0;
	SL s;
	SeqListInit(&s);

	while (option !=-1)
	{
		meau();
		scanf("%d",&option);

		switch (option)
		{
		case 1:
			printf("��������Ҫͷ������ݣ���-1����\n");
			do
			{
				scanf("%d", &x);
				if (x != -1)
				{
					SeqListPushFront(&s, x);
				}

			} while (x!=-1);
			break;

		case 2:
			printf("��������Ҫβ������ݣ���-1����\n");
			do
			{
				scanf("%d", &x);
				if (x != -1)
				{
					SeqListPushBack(&s, x);
				}

			} while (x != -1);
			break;

		case 3:
			printf("ͷɾ���ݣ�����1ȷ��������-1�˳�\n");
			do
			{
				scanf("%d", &x);
				if (x == 1)
				{
					SeqListPopFront(&s);
				}

			} while (x == 1);
			break;

		case 4:
			printf("βɾ���ݣ�����1ȷ��������-1�˳�\n");
			do
			{
				scanf("%d", &x);
				if (x == 1)
				{
					SeqListPopBack(&s);
				}

			} while (x == 1);
			break;

		case 5:
			SeqListPrintf(&s);
			break;

		case 6:
			printf("��������Ҫ���ҵ����ݣ���������±꣬û�ҵ����-1��������-1����\n");
			do
			{
				scanf("%d", &x);
				int a = x;
				if (x != -1)
				{
					int Findpos = SeqListFind(&s, a);
					
					if (Findpos == -1)
					{
						printf("û���ҵ�\n");
					}
					else
					{
						printf("�±�Ϊ%d", Findpos);
					}

				}
			} while (x != -1);
			break;

		case 7:
			printf("�������� ��������λ�õ��±� �� �������ݣ�����-1����\n");
			do
			{
				scanf("%d", &x);
				if (x != -1)
				{
					scanf("%d", &y);
					SeqListInsert(&s,x,y);
				}

			} while (x != -1);
			break;

		case 8:
			printf("��������Ҫɾ��λ�õ��±꣬����-1����\n");
			do
			{
				scanf("%d", &x);
				if (x != -1)
				{
					SeqListPushBack(&s, x);
				}

			} while (x != -1);
			break;

		case 9:
			printf("�������� �޸�����λ�õ��±� �� �޸ĵ����ݣ�����-1����\n");
			do
			{
				scanf("%d", &x);
				if (x != -1)
				{
					scanf("%d", &y);
					SeqListModity(&s, x, y);
				}

			} while (x != -1);
			break;


		case -1:
			printf("�˳�\n");
			return 0;
			break;

		default:
			printf("�����������������\n");
			break;
		}

	}

	//��������
	//TestSeqList1();


	return 0;
}


