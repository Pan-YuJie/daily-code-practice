#include "List.h"

void Test()
{
    ListNode* plist = ListInit();

    ListPushBack(plist, 1);
    ListPushBack(plist, 2);
    ListPushBack(plist, 3);
    ListPushBack(plist, 4);

    ListPrintf(plist);


    ListPushFront(plist, 0);
    ListPushFront(plist, -1);
    ListPrintf(plist);


    ListPopFront(plist);
    ListPopFront(plist);
    ListPrintf(plist);


    ListPopBack(plist);
    ListPrintf(plist);


    ListNode* pos = ListFind(plist,3);
    if (pos)
    {
        printf("找到了\n");
    }
    else
    {
        printf("没找到\n");
    }

    ListModify(plist, 3, 30);
    ListPrintf(plist);

    ListInsert(pos, 300);
    ListPrintf(plist);

    ListNode* pos2 = ListFind(plist, 300);
    ListErase(pos2);
    ListPrintf(plist);


}



int main()
{

    Test();


    return 0;
}