#include "SList.h"

void TestSList1()
{
    SListNode* plist = NULL;
    SListPushBack(&plist, 1);//´«µØÖ·
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
    SListPopBack(&plist);
    SListPopBack(&plist);
    SListPrintf(plist);




}

int main()
{
    TestSList1();

    return 0;
}