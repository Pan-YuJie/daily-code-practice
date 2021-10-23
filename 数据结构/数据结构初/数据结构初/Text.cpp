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
	
	printf("下标为%d\n", Findpos);

}


void meau()
{
	printf("********************************************\n");
	printf("(1).头插数据         (2).尾插数据\n");
	printf("(3).头删数据         (4).尾删数据\n");
	printf("(5).打印数据         (6).查找数据\n");
	printf("(7).任意位置插入数据  (8).任意位置删除数据\n");
	printf("(9).任意位置修改数据  (-1).退出程序\n");
	printf("********************************************\n");

	printf("\n**请输入你的操作选项:>**\n");

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
			printf("请输入你要头插的数据，用-1结束\n");
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
			printf("请输入你要尾插的数据，以-1结束\n");
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
			printf("头删数据，输入1确定，输入-1退出\n");
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
			printf("尾删数据，输入1确定，输入-1退出\n");
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
			printf("请输入你要查找的数据（返回输出下标，没找到输出-1），输入-1结束\n");
			do
			{
				scanf("%d", &x);
				int a = x;
				if (x != -1)
				{
					int Findpos = SeqListFind(&s, a);
					
					if (Findpos == -1)
					{
						printf("没有找到\n");
					}
					else
					{
						printf("下标为%d", Findpos);
					}

				}
			} while (x != -1);
			break;

		case 7:
			printf("请输入你 插入数据位置的下标 和 插入数据，输入-1结束\n");
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
			printf("请输入你要删除位置的下标，输入-1结束\n");
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
			printf("请输入你 修改数据位置的下标 和 修改的数据，输入-1结束\n");
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
			printf("退出\n");
			return 0;
			break;

		default:
			printf("输入错误，请重新输入\n");
			break;
		}

	}

	//测试用例
	//TestSeqList1();


	return 0;
}


