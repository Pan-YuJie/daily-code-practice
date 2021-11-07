#include "function.h"

extern int Max_xh;
extern int dj[6];

void dj_change(StuLink *p)
{
    if (p->cj >= 90)
        p->dj = 'A';
    else if (p->cj < 90 && p->cj >= 80)
        p->dj = 'B';
    else if (p->cj < 80 && p->cj >= 70)
        p->dj = 'C';
    else if (p->cj < 70 && p->cj >= 60)
        p->dj = 'D';
    else if (p->cj < 60)
        p->dj = 'E';
}

void xh_define(StuLink *p, StuLink *head)
{
    p->xh = Max_xh;
    Max_xh++;
}

void OutputLink_only10(StuLink *head, int start)
{
    int i = 1;
    StuLink *p = head;
    while (p != NULL && i != start)
    {
        p = p->next;
        i++;
    }
    i = 1;
    printf("\n\t学号\t 姓名 \t性别\t成绩\t等级\t名次\n");
    for (p; (p != NULL) && (i <= 10); p = p->next, i++)
    {
        switch (p->xb)
        {
        case boy:
            printf("\n\t%3d\t%6s\t  男\t%3d\t  %c\t%3d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
            break;
        case girl:
            printf("\n\t%3d\t%6s\t  女\t%3d\t  %c\t%3d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
            break;
        }
    }
}

int count(StuLink *head)
{
    int num = 0;
    StuLink *p = head;
    while (p != NULL)
    {
        p = p->next;
        num++;
    }
    return num;
}

void start_menu()
{
    printf("\n\t**********欢迎来到学生管理系统**********\n\n");
    printf("\n\t\t    (1) 数据维护\n\n\t\t    (2) 数据查询\n\n\t\t    (3) 统计分析\n\n\t\t    (4) 报表输出\n\n\t\t    (0) 退出\n\n");
    printf("\n          请不要强制关闭本窗口导致数据保存出错!\n");
    printf("\n\t*****************************************\n\n");
}
StuLink *menu(int choose1, StuLink *head)
{
    int choose2, choose3, num, i; //choose2:二级菜单选择  choose3:三级菜单选择  num：学号  i:人数
    switch (choose1)
    {
    case 1:
    {
    start1:
        printf("\n   1)数据插入   2)数据修改   3)数据删除   0)返回\n");
        printf("\n 请对应操作输入序号：");
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
        {
            head = InsertNode(head);
            RankLink(head);
            getchar();
            break;
        }
        case 2:
        {
            printf("\n 请输入学号：");
            scanf("%d", &num);
            EditNode(head, num);
            getchar();
            break;
        }
        case 3:
        {
            printf("\n 请输入学号：");
            scanf("%d", &num);
            DeleteNode(head, num);
            break;
        }
        case 0:
            break;
        default:
        {
            printf("\n 输入错误！请重新输入！\n");
            goto start1;
        }
        }
        break;
    }
    case 2:
    {
    start2:
        printf("\n   1)学号查询   2)不及格学生查询   0)返回\n");
        printf("\n 请对应操作输入序号：");
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
        {
            printf("\n 请输入学号：");
            scanf("%d", &num);
            QueryNode(head, num);
            break;
        }
        case 2:
        {
            QueryLink(head);
            getchar();
            break;
        }
        case 0:
            break;
        default:
        {
            printf("\n 输入错误！请重新输入！\n");
            getchar();
            goto start2;
        }
        }
        break;
    }
    case 3:
    {
    start3:
        printf("\n   1)成绩名次计算   2)成绩频度分析   0)返回\n");
        printf("\n 请对应操作输入序号：");
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
        {
            RankLink(head);
            printf("\n 操作完成！\n");
            getchar();
            break;
        }
        case 2:
        {
            AnalysisLink(head);
            printf("\n 操作完成！\n");
            printf("\n 各等级人数：\n");
            printf("\n   A等级：%d 人\n   B等级：%d 人\n   C等级：%d 人\n   D等级：%d 人\n   E等级：%d 人\n", dj[1], dj[2], dj[3], dj[4], dj[5]);
            getchar();
            break;
        }
        case 0:
            break;
        default:
        {
            printf("\n 输入错误！请重新输入！\n");
            getchar();
            goto start3;
        }
        }
        break;
    }
    case 4:
    {
    start4:
        printf("\n   1)排序显示学生信息   2)分页显示学生信息   0)返回\n");
        printf("\n 请对应操作输入序号：");
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
        {
            printf("\n  1)按学号升序排序   2)按成绩降序排序\n");
            printf("\n 请对应操作输入序号：");
            scanf("%d", &choose3);
            OutputLink_1(head, choose3);
            break;
        }
        case 2:
        {
            OutputLink_2(head, count(head));
            break;
        }
        case 0:
            break;
        default:
        {
            printf("\n 输入错误！请重新输入！\n");
            goto start4;
        }
        }
        break;
    }
    default:
        break;
    }
    return head;
}