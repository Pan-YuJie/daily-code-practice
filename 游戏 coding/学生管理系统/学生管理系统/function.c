#include "function.h"

int Max_xh = 1;                 //当前最大学号
int dj[6] = {0, 0, 0, 0, 0, 0}; //一维数组存储ABCDE各等级人数

StuLink *ReadFromFile(FILE *fp, StuLink *head)
{
    StuLink *p1 = NULL, *p2 = NULL;
    char ch;
    int i = 0;
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        fp = fopen("student.txt", "w");
    } //判断是否正常打开文件并使指向文件
    head = NULL;
    ch = fgetc(fp);
    if (ch != EOF)
    {
        rewind(fp);
        while (!feof(fp))
        {
            if ((p2 = (StuLink *)malloc(sizeof(StuLink))) == NULL)
            {
                printf(" 不能成功分配储存块！\n");
                exit(0);
            } //动态分配空间

            fscanf(fp, "%d %s %d %d %c %d\n", &p2->xh, p2->xm, &p2->xb, &p2->cj, &p2->dj, &p2->mc);

            p2->next = NULL;
            if (head == NULL)
            {
                p1 = p2;
                head = p2;
            }
            else
            {
                p1->next = p2;
                p1 = p2;
            }
            if (p2->xh > i)
                i = p2->xh;
        }

        Max_xh = i + 1;
        AnalysisLink(head);
        RankLink(head);
    }
    if (fclose(fp))
    {
        printf("\n 无法正常关闭数据文件！\n");
        getchar();
        exit(0);
    }
    return head;
}

void SaveToFile(FILE *fp, StuLink *head)
{
    StuLink *p = head;
    SortLink(head, 1);
    if ((fp = fopen("student.txt", "w")) == NULL)
    {
        printf("\n 文件打开失败！\n");
        getchar();
        exit(0);
    }
    while (p != NULL)
    {
        fprintf(fp, "%d %s %d %d %c %d\n", p->xh, p->xm, p->xb, p->cj, p->dj, p->mc);
        p = p->next;
    }
    if (fclose(fp))
    {
        printf("\n 无法正常关闭数据文件！\n");
        getchar();
        exit(0);
    }
}

StuLink *InsertNode(StuLink *head)
{
    StuLink *new = NULL, *p = NULL;
    char xb[10];
    if ((new = (StuLink *)malloc(sizeof(StuLink))) == NULL)
    {
        printf("\n 内存分配失败！\n");
        getchar();
        exit(0);
    }
    printf("\n 请依次输入该生的姓名、性别、成绩：(0代表男生 1代表女生，各项以空格隔开)\n\n ");
    scanf("%s %d %d", new->xm, &new->xb, &new->cj);
    while (new->xb != 0 && new->xb != 1)
    {
        printf("\n 性别输入错误！请重新输入性别（ 0 或 1 ）！\n ");
        scanf("%d", &new->xb);
    }
    while (new->cj > 100 || new->cj < 0)
    {
        printf("\n 成绩输入错误！请重新输入成绩（ 0 至 100）！\n ");
        scanf("%d", &new->cj);
    }
    dj_change(new);
    new->next = NULL;
    p = head;
    if (head == NULL)
    {
        head = new;
    }
    else
    {
        while (p->next != NULL)
            p = p->next;
        p->next = new;
    }
    xh_define(new, head);
    printf("\n 插入成功！\n");
    return head;
}
void EditNode(StuLink *head, int num)
{
    StuLink *p = head;
    int choose;
    while (p != NULL)
    {
        if (p->xh == num)
        {
            switch (p->xb)
            {
            case boy:
                printf("\n 该生的信息为：\n\n学号：%d  姓名：%s  性别：男  成绩：%d  等级：%c  名次：%d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
                break;
            case girl:
                printf("\n 该生的信息为：\n\n学号：%d  姓名：%s  性别：女  成绩：%d  等级：%c  名次：%d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
                break;
            }
            printf("\n 要修改的数据项是：\n");
            printf("\n   1)姓名   2)性别   3)成绩   4)返回\n");
        start:
            printf("\n 请输入:");
            scanf("%d", &choose);
            printf("\n 请修改：");
            if (choose == 1)
                scanf("%s", p->xm);
            else if (choose == 2)
            {
                printf("(0代表男生 1代表女生)  ");
                scanf("%d", &p->xb);
                while (p->xb != 0 && p->xb != 1)
                {
                    printf("\n 性别输入错误！请重新输入性别!（0代表男生 1代表女生）\n\n ");
                    scanf("%d", &p->xb);
                }
            }
            else if (choose == 3)
            {
                scanf("%d", &p->cj);
                while (p->cj > 100 || p->cj < 0)
                {
                    printf("\n 成绩输入错误！请重新输入成绩（ 0 至 100 ）！\n\n ");
                    scanf("%d", &p->cj);
                }
                dj_change(p);
                RankLink(head);
            }
            else if (choose == 4)
                return;
            else
            {
                printf("\n 输入错误！\n\n");
                goto start;
            }
            printf("\n 修改成功！\n");
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\n 无法查到该学号的信息！\n");
    }
}

StuLink *DeleteNode(StuLink *head, int num)
{
    StuLink *p1 = head, *p2 = NULL;
    while (p1->xh != num && p1 != NULL)
    {
        p2 = p1;
        p1 = p1->next;
    }
    if (p1->xh == num && p1 == head)
    {
        head = head->next;
        free(p1);
    }
    else if (p1->xh == num)
    {
        p2->next = p1->next;
        free(p1);
    }
    else
    {
        printf("\n 无法查到该学号的信息！\n");
        return head;
    }
    RankLink(head);
    printf("\n 删除成功！\n");
    getchar();
    return head;
}

void QueryNode(StuLink *head, int num)
{
    StuLink *p = head;
    if (head == NULL)
    {
        printf("\n 数据为空！\n");
        getchar();
        return;
    }
    else
    {
        while (p != NULL)
        {
            if (p->xh == num)
            {
                switch (p->xb)
                {
                case boy:
                    printf("\n 该生的信息为：\n\n 学号：%d  姓名：%s  性别：男  成绩：%d  等级：%c  名次：%d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
                    break;
                case girl:
                    printf("\n 该生的信息为：\n\n 学号：%d  姓名：%s  性别：女  成绩：%d  等级：%c  名次：%d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
                    break;
                }
                break;
            }
            p = p->next;
        }
        if (p == NULL)
        {
            printf("\n 无法查到该学号的信息！\n");
        }
        getchar();
    }
}
void QueryLink(StuLink *head)
{
    int i = 0;
    StuLink *p = head;
    if (head == NULL)
    {
        printf("\n 数据为空！\n");
        return;
    }
    else
    {
        while (p != NULL)
        {
            if (p->cj < 60)
            {
                i++;
                if (i == 1)
                    printf("\n\t学号\t 姓名 \t性别\t成绩\t等级\t名次\n");
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
            p = p->next;
        }
        if (i == 0)
        {
            printf("\n 没有不及格人数！\n");
        }
        else
        {
            printf("\n 不及格人数：%d 人\n", i);
        }
    }
}

void RankLink(StuLink *head)
{
    StuLink *p1, *p2;
    int i = 1;
    if (head == NULL)
    {
        printf("\n 数据为空！\n");
        getchar();
        return;
    }
    if (head->next == NULL)
    {
        head->mc = 1;
        return;
    }
    for (p1 = head; p1 != NULL; p1 = p1->next)
    {
        for (p2 = head; p2 != NULL; p2 = p2->next)
        {
            if (p1->cj < p2->cj)
                i++;
        }
        p1->mc = i;
        i = 1;
    }
}

void AnalysisLink(StuLink *head)
{
    StuLink *p = head;
    int i;
    if (head == NULL)
    {
        printf("\n 数据为空！\n");
        getchar();
        return;
    }
    else
    {
        for (i = 1; i <= 5; i++)
            dj[i] = 0; //初始化等级数组
        while (p != NULL)
        {
            if (p->cj >= 90)
                dj[1]++;
            else if (p->cj < 90 && p->cj >= 80)
                dj[2]++;
            else if (p->cj < 80 && p->cj >= 70)
                dj[3]++;
            else if (p->cj < 70 && p->cj >= 60)
                dj[4]++;
            else if (p->cj < 60)
                dj[5]++;
            p = p->next;
        }
    }
}

void exchange(StuLink *p1, StuLink *p2)
{
    StuLink *temp;
    if ((temp = (StuLink *)malloc(sizeof(StuLink))) == NULL)
    {
        printf("\n 空间分配失败！\n");
        getchar();
        exit(0);
    }
    temp->xh = p1->xh;
    strcpy(temp->xm, p1->xm);
    temp->xb = p1->xb;
    temp->cj = p1->cj;
    temp->dj = p1->dj;
    temp->mc = p1->mc;

    p1->xh = p2->xh;
    strcpy(p1->xm, p2->xm);
    p1->xb = p2->xb;
    p1->cj = p2->cj;
    p1->dj = p2->dj;
    p1->mc = p2->mc;

    p2->xh = temp->xh;
    strcpy(p2->xm, temp->xm);
    p2->xb = temp->xb;
    p2->cj = temp->cj;
    p2->dj = temp->dj;
    p2->mc = temp->mc;

    free(temp);
}

void SortLink(StuLink *head, int choose)
{
    StuLink *p1 = head, *p2;
    StuLink *temp;
    if (p1 == NULL || p1->next == NULL)
        return;

    if (choose == 1) //按学号排序（升序）
    {
        for (p1 = head; p1->next != NULL; p1 = p1->next)
        {
            temp = p1;
            for (p2 = p1->next; p2 != NULL; p2 = p2->next)
            {
                if (temp->xh > p2->xh)
                    temp = p2;
            }
            exchange(temp, p1);
        }
    }
    else if (choose == 2) //按成绩排名（降序）
    {
        for (p1 = head; p1->next != NULL; p1 = p1->next)
        {
            temp = p1;
            for (p2 = p1->next; p2 != NULL; p2 = p2->next)
            {
                if (temp->cj < p2->cj)
                    temp = p2;
            }
            exchange(temp, p1);
        }
    }
    else
        printf("\n 输入错误！\n");
}

void OutputLink_1(StuLink *head, int choose)
{
    StuLink *p = NULL;
    if (choose == 1)
    {
        if (head != NULL)
        {
            SortLink(head, 1);
            printf("\n 学生成绩表如下：(按学号升序排序)\n");
            printf("\n\t学号\t 姓名 \t性别\t成绩\t等级\t名次\n");
            for (p = head; p != NULL; p = p->next)
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
            AnalysisLink(head);
            printf("\n 各等级人数：\n");
            printf("\n   A等级：%d 人\n   B等级：%d 人\n   C等级：%d 人\n   D等级：%d 人\n   E等级：%d 人\n", dj[1], dj[2], dj[3], dj[4], dj[5]);
        }
        else
        {
            printf("\n 数据为空！\n");
        }
    }
    else if (choose == 2)
    {
        if (head != NULL)
        {
            SortLink(head, 2);
            printf("\n 学生成绩表如下：(按学号升序排序)\n");
            printf("\n\t学号\t 姓名 \t性别\t成绩\t等级\t名次\n");
            for (p = head; p != NULL; p = p->next)
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
            AnalysisLink(head);
            printf("\n 各等级人数：\n");
            printf("\n   A等级：%d 人\n   B等级：%d 人\n   C等级：%d 人\n   D等级：%d 人\n   E等级：%d 人\n", dj[1], dj[2], dj[3], dj[4], dj[5]);
        }
        else
        {
            printf("\n 数据为空！\n");
        }
    }
    else
        printf("\n 输入错误！\n");
    getchar();
}

void OutputLink_2(StuLink *head, int num)
{
    int i = 1; //每十个数据中第一个数据的下标
    int choose;
    int page = 1;
    if (head == NULL)
    {
        printf("\n 数据为空！\n");
        getchar();
        return;
    }
    else
    {
        printf("\n 当前位置：第 %d 页 , 共 %d 页\n", page, (count(head) / 10) + 1);
        OutputLink_only10(head, 1);
        printf("\n\n       1)首页   2)上一页   3)下一页   4)尾页   0)返回\n");
    back:
        printf("\n 请对应操作输入序号：");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            if (i == 1 || num == 10)
            {
                printf("\n 当前位置位于首页！\n");
            }
            else
            {
                system("cls");
                start_menu();
                printf("\n");
                page = 1;
                printf("\n 当前位置：第 %d 页\n", page);
                OutputLink_only10(head, 1);
                printf("\n\n       1)首页   2)上一页   3)下一页   4)尾页   0)返回\n");
                i = 1;
            }
            getchar();
            goto back;
        }
        case 2:
        {
            if (i == 1 || num == 10)
            {
                printf("\n 当前位置位于首页！\n");
                getchar();
                goto back;
            }
            else
            {
                system("cls");
                start_menu();
                printf("\n");
                page--;
                printf("\n 当前位置：第 %d 页\n", page);
                OutputLink_only10(head, i - 10);
                printf("\n\n       1)首页   2)上一页   3)下一页   4)尾页   0)返回\n");
                i = i - 10;
            }
            getchar();
            goto back;
        }
        case 3:
        {
            if (i == num / 10 * 10 + 1 || num == 10)
            {
                printf("\n 当前位置位于尾页！\n");
                getchar();
                goto back;
            }
            else
            {
                system("cls");
                start_menu();
                printf("\n");
                page++;
                printf("\n 当前位置：第 %d 页\n", page);
                OutputLink_only10(head, i + 10);
                printf("\n\n       1)首页   2)上一页   3)下一页   4)尾页   0)返回\n");
                i = i + 10;
            }
            getchar();
            goto back;
        }
        case 4:
        {
            if (i == num / 10 * 10 + 1 || num == 10)
            {
                printf("\n 当前位置位于尾页！\n");
            }
            else
            {
                system("cls");
                start_menu();
                printf("\n");
                page = num / 10;
                printf("\n 当前位置：第 %d 页\n", page);
                if (num % 10 == 0)
                    OutputLink_only10(head, (num / 10 - 1) * 10 + 1);
                else
                    OutputLink_only10(head, num / 10 * 10 + 1);
                printf("\n\n       1)首页   2)上一页   3)下一页   4)尾页   0)返回\n");
                i = num / 10 * 10 + 1;
            }
            getchar();
            goto back;
        }
        case 0:
            return;
        default:
        {
            printf("\n 输入错误！请重新输入！\n");
            getchar();
            goto back;
        }
        }
    }
}