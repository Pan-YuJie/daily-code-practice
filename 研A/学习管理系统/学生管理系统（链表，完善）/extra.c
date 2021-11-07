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
    printf("\n\tѧ��\t ���� \t�Ա�\t�ɼ�\t�ȼ�\t����\n");
    for (p; (p != NULL) && (i <= 10); p = p->next, i++)
    {
        switch (p->xb)
        {
        case boy:
            printf("\n\t%3d\t%6s\t  ��\t%3d\t  %c\t%3d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
            break;
        case girl:
            printf("\n\t%3d\t%6s\t  Ů\t%3d\t  %c\t%3d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
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
    printf("\n\t**********��ӭ����ѧ������ϵͳ**********\n\n");
    printf("\n\t\t    (1) ����ά��\n\n\t\t    (2) ���ݲ�ѯ\n\n\t\t    (3) ͳ�Ʒ���\n\n\t\t    (4) �������\n\n\t\t    (0) �˳�\n\n");
    printf("\n          �벻Ҫǿ�ƹرձ����ڵ������ݱ������!\n");
    printf("\n\t*****************************************\n\n");
}
StuLink *menu(int choose1, StuLink *head)
{
    int choose2, choose3, num, i; //choose2:�����˵�ѡ��  choose3:�����˵�ѡ��  num��ѧ��  i:����
    switch (choose1)
    {
    case 1:
    {
    start1:
        printf("\n   1)���ݲ���   2)�����޸�   3)����ɾ��   0)����\n");
        printf("\n ���Ӧ����������ţ�");
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
            printf("\n ������ѧ�ţ�");
            scanf("%d", &num);
            EditNode(head, num);
            getchar();
            break;
        }
        case 3:
        {
            printf("\n ������ѧ�ţ�");
            scanf("%d", &num);
            DeleteNode(head, num);
            break;
        }
        case 0:
            break;
        default:
        {
            printf("\n ����������������룡\n");
            goto start1;
        }
        }
        break;
    }
    case 2:
    {
    start2:
        printf("\n   1)ѧ�Ų�ѯ   2)������ѧ����ѯ   0)����\n");
        printf("\n ���Ӧ����������ţ�");
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
        {
            printf("\n ������ѧ�ţ�");
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
            printf("\n ����������������룡\n");
            getchar();
            goto start2;
        }
        }
        break;
    }
    case 3:
    {
    start3:
        printf("\n   1)�ɼ����μ���   2)�ɼ�Ƶ�ȷ���   0)����\n");
        printf("\n ���Ӧ����������ţ�");
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
        {
            RankLink(head);
            printf("\n ������ɣ�\n");
            getchar();
            break;
        }
        case 2:
        {
            AnalysisLink(head);
            printf("\n ������ɣ�\n");
            printf("\n ���ȼ�������\n");
            printf("\n   A�ȼ���%d ��\n   B�ȼ���%d ��\n   C�ȼ���%d ��\n   D�ȼ���%d ��\n   E�ȼ���%d ��\n", dj[1], dj[2], dj[3], dj[4], dj[5]);
            getchar();
            break;
        }
        case 0:
            break;
        default:
        {
            printf("\n ����������������룡\n");
            getchar();
            goto start3;
        }
        }
        break;
    }
    case 4:
    {
    start4:
        printf("\n   1)������ʾѧ����Ϣ   2)��ҳ��ʾѧ����Ϣ   0)����\n");
        printf("\n ���Ӧ����������ţ�");
        scanf("%d", &choose2);
        switch (choose2)
        {
        case 1:
        {
            printf("\n  1)��ѧ����������   2)���ɼ���������\n");
            printf("\n ���Ӧ����������ţ�");
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
            printf("\n ����������������룡\n");
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