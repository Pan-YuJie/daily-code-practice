#include "function.c"
#include "extra.c"

int main()
{
    int choice1;          //一级选择
    FILE *fp=NULL;             //定义一个文件指针
    StuLink *head = NULL; //定义一个头指针

    head = ReadFromFile(fp, head); //读取学生信息

start:
    start_menu();
start1:
    printf("\n 请对应操作输入序号：");
    scanf("%d", &choice1);
    if (choice1 == 1 || choice1 == 2 || choice1 == 3 || choice1 == 4 || choice1 == 0)
        goto out; //满足条件 --> 移动到 out位置继续运行
    else          //不满足条件 --> 移动到 start位置继续运行
    {
        printf("\n 输入错误！请重新输入！\n");
        getchar();
        goto start1;
    }
out:
    switch (choice1)
    {
    case 0:
    {
        SaveToFile(fp, head);
        exit(0);
    }
    case 1:
    case 2:
    case 3:
    case 4:
    {
        head = menu(choice1, head);
        SaveToFile(fp, head);
        printf("\n 按任意键返回...");
        getchar();

        goto start;
    }
    }
    return 0;
}
