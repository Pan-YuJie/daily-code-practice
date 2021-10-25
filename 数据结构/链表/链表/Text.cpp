#include "SList.h"

void TestSList1()
{
    SListNode* plist = NULL;
    SListPushBack(&plist, 1);//传地址
    SListPushBack(&plist, 2);
    SListPushBack(&plist, 3);
    SListPushBack(&plist, 4);

    SListPrintf(plist);

    SListPushFront(&plist, 0);
    SListPushFront(&plist, -1);
    SListPrintf(plist);

    SListPopFront(&plist);
    SListPrintf(plist);

    SListPopBack(&plist);

    SListPrintf(plist);

    //查找+修改
    SLTNode* pos1 = SListFind(plist, 2);
    if (pos1 != NULL)
    {
        SListInsert(&plist, pos1, 30);
    }

    SListPrintf(plist);

    SLTNode* pos2 = SListFind(plist, 0);
    if (pos2 != NULL)
    {
        SListErase(&plist, pos2);
    }

    SListPrintf(plist);

}

int main()
{
    TestSList1();

    return 0;
}