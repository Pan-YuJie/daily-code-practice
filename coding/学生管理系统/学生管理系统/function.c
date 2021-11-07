#include "function.h"

int Max_xh = 1;                 //��ǰ���ѧ��
int dj[6] = {0, 0, 0, 0, 0, 0}; //һά����洢ABCDE���ȼ�����

StuLink *ReadFromFile(FILE *fp, StuLink *head)
{
    StuLink *p1 = NULL, *p2 = NULL;
    char ch;
    int i = 0;
    if ((fp = fopen("student.txt", "r")) == NULL)
    {
        fp = fopen("student.txt", "w");
    } //�ж��Ƿ��������ļ���ʹָ���ļ�
    head = NULL;
    ch = fgetc(fp);
    if (ch != EOF)
    {
        rewind(fp);
        while (!feof(fp))
        {
            if ((p2 = (StuLink *)malloc(sizeof(StuLink))) == NULL)
            {
                printf(" ���ܳɹ����䴢��飡\n");
                exit(0);
            } //��̬����ռ�

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
        printf("\n �޷������ر������ļ���\n");
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
        printf("\n �ļ���ʧ�ܣ�\n");
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
        printf("\n �޷������ر������ļ���\n");
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
        printf("\n �ڴ����ʧ�ܣ�\n");
        getchar();
        exit(0);
    }
    printf("\n ����������������������Ա𡢳ɼ���(0�������� 1����Ů���������Կո����)\n\n ");
    scanf("%s %d %d", new->xm, &new->xb, &new->cj);
    while (new->xb != 0 && new->xb != 1)
    {
        printf("\n �Ա�������������������Ա� 0 �� 1 ����\n ");
        scanf("%d", &new->xb);
    }
    while (new->cj > 100 || new->cj < 0)
    {
        printf("\n �ɼ������������������ɼ��� 0 �� 100����\n ");
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
    printf("\n ����ɹ���\n");
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
                printf("\n ��������ϢΪ��\n\nѧ�ţ�%d  ������%s  �Ա���  �ɼ���%d  �ȼ���%c  ���Σ�%d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
                break;
            case girl:
                printf("\n ��������ϢΪ��\n\nѧ�ţ�%d  ������%s  �Ա�Ů  �ɼ���%d  �ȼ���%c  ���Σ�%d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
                break;
            }
            printf("\n Ҫ�޸ĵ��������ǣ�\n");
            printf("\n   1)����   2)�Ա�   3)�ɼ�   4)����\n");
        start:
            printf("\n ������:");
            scanf("%d", &choose);
            printf("\n ���޸ģ�");
            if (choose == 1)
                scanf("%s", p->xm);
            else if (choose == 2)
            {
                printf("(0�������� 1����Ů��)  ");
                scanf("%d", &p->xb);
                while (p->xb != 0 && p->xb != 1)
                {
                    printf("\n �Ա�������������������Ա�!��0�������� 1����Ů����\n\n ");
                    scanf("%d", &p->xb);
                }
            }
            else if (choose == 3)
            {
                scanf("%d", &p->cj);
                while (p->cj > 100 || p->cj < 0)
                {
                    printf("\n �ɼ������������������ɼ��� 0 �� 100 ����\n\n ");
                    scanf("%d", &p->cj);
                }
                dj_change(p);
                RankLink(head);
            }
            else if (choose == 4)
                return;
            else
            {
                printf("\n �������\n\n");
                goto start;
            }
            printf("\n �޸ĳɹ���\n");
            break;
        }
        p = p->next;
    }
    if (p == NULL)
    {
        printf("\n �޷��鵽��ѧ�ŵ���Ϣ��\n");
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
        printf("\n �޷��鵽��ѧ�ŵ���Ϣ��\n");
        return head;
    }
    RankLink(head);
    printf("\n ɾ���ɹ���\n");
    getchar();
    return head;
}

void QueryNode(StuLink *head, int num)
{
    StuLink *p = head;
    if (head == NULL)
    {
        printf("\n ����Ϊ�գ�\n");
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
                    printf("\n ��������ϢΪ��\n\n ѧ�ţ�%d  ������%s  �Ա���  �ɼ���%d  �ȼ���%c  ���Σ�%d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
                    break;
                case girl:
                    printf("\n ��������ϢΪ��\n\n ѧ�ţ�%d  ������%s  �Ա�Ů  �ɼ���%d  �ȼ���%c  ���Σ�%d\n", p->xh, p->xm, p->cj, p->dj, p->mc);
                    break;
                }
                break;
            }
            p = p->next;
        }
        if (p == NULL)
        {
            printf("\n �޷��鵽��ѧ�ŵ���Ϣ��\n");
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
        printf("\n ����Ϊ�գ�\n");
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
                    printf("\n\tѧ��\t ���� \t�Ա�\t�ɼ�\t�ȼ�\t����\n");
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
            p = p->next;
        }
        if (i == 0)
        {
            printf("\n û�в�����������\n");
        }
        else
        {
            printf("\n ������������%d ��\n", i);
        }
    }
}

void RankLink(StuLink *head)
{
    StuLink *p1, *p2;
    int i = 1;
    if (head == NULL)
    {
        printf("\n ����Ϊ�գ�\n");
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
        printf("\n ����Ϊ�գ�\n");
        getchar();
        return;
    }
    else
    {
        for (i = 1; i <= 5; i++)
            dj[i] = 0; //��ʼ���ȼ�����
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
        printf("\n �ռ����ʧ�ܣ�\n");
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

    if (choose == 1) //��ѧ����������
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
    else if (choose == 2) //���ɼ�����������
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
        printf("\n �������\n");
}

void OutputLink_1(StuLink *head, int choose)
{
    StuLink *p = NULL;
    if (choose == 1)
    {
        if (head != NULL)
        {
            SortLink(head, 1);
            printf("\n ѧ���ɼ������£�(��ѧ����������)\n");
            printf("\n\tѧ��\t ���� \t�Ա�\t�ɼ�\t�ȼ�\t����\n");
            for (p = head; p != NULL; p = p->next)
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
            AnalysisLink(head);
            printf("\n ���ȼ�������\n");
            printf("\n   A�ȼ���%d ��\n   B�ȼ���%d ��\n   C�ȼ���%d ��\n   D�ȼ���%d ��\n   E�ȼ���%d ��\n", dj[1], dj[2], dj[3], dj[4], dj[5]);
        }
        else
        {
            printf("\n ����Ϊ�գ�\n");
        }
    }
    else if (choose == 2)
    {
        if (head != NULL)
        {
            SortLink(head, 2);
            printf("\n ѧ���ɼ������£�(��ѧ����������)\n");
            printf("\n\tѧ��\t ���� \t�Ա�\t�ɼ�\t�ȼ�\t����\n");
            for (p = head; p != NULL; p = p->next)
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
            AnalysisLink(head);
            printf("\n ���ȼ�������\n");
            printf("\n   A�ȼ���%d ��\n   B�ȼ���%d ��\n   C�ȼ���%d ��\n   D�ȼ���%d ��\n   E�ȼ���%d ��\n", dj[1], dj[2], dj[3], dj[4], dj[5]);
        }
        else
        {
            printf("\n ����Ϊ�գ�\n");
        }
    }
    else
        printf("\n �������\n");
    getchar();
}

void OutputLink_2(StuLink *head, int num)
{
    int i = 1; //ÿʮ�������е�һ�����ݵ��±�
    int choose;
    int page = 1;
    if (head == NULL)
    {
        printf("\n ����Ϊ�գ�\n");
        getchar();
        return;
    }
    else
    {
        printf("\n ��ǰλ�ã��� %d ҳ , �� %d ҳ\n", page, (count(head) / 10) + 1);
        OutputLink_only10(head, 1);
        printf("\n\n       1)��ҳ   2)��һҳ   3)��һҳ   4)βҳ   0)����\n");
    back:
        printf("\n ���Ӧ����������ţ�");
        scanf("%d", &choose);
        switch (choose)
        {
        case 1:
        {
            if (i == 1 || num == 10)
            {
                printf("\n ��ǰλ��λ����ҳ��\n");
            }
            else
            {
                system("cls");
                start_menu();
                printf("\n");
                page = 1;
                printf("\n ��ǰλ�ã��� %d ҳ\n", page);
                OutputLink_only10(head, 1);
                printf("\n\n       1)��ҳ   2)��һҳ   3)��һҳ   4)βҳ   0)����\n");
                i = 1;
            }
            getchar();
            goto back;
        }
        case 2:
        {
            if (i == 1 || num == 10)
            {
                printf("\n ��ǰλ��λ����ҳ��\n");
                getchar();
                goto back;
            }
            else
            {
                system("cls");
                start_menu();
                printf("\n");
                page--;
                printf("\n ��ǰλ�ã��� %d ҳ\n", page);
                OutputLink_only10(head, i - 10);
                printf("\n\n       1)��ҳ   2)��һҳ   3)��һҳ   4)βҳ   0)����\n");
                i = i - 10;
            }
            getchar();
            goto back;
        }
        case 3:
        {
            if (i == num / 10 * 10 + 1 || num == 10)
            {
                printf("\n ��ǰλ��λ��βҳ��\n");
                getchar();
                goto back;
            }
            else
            {
                system("cls");
                start_menu();
                printf("\n");
                page++;
                printf("\n ��ǰλ�ã��� %d ҳ\n", page);
                OutputLink_only10(head, i + 10);
                printf("\n\n       1)��ҳ   2)��һҳ   3)��һҳ   4)βҳ   0)����\n");
                i = i + 10;
            }
            getchar();
            goto back;
        }
        case 4:
        {
            if (i == num / 10 * 10 + 1 || num == 10)
            {
                printf("\n ��ǰλ��λ��βҳ��\n");
            }
            else
            {
                system("cls");
                start_menu();
                printf("\n");
                page = num / 10;
                printf("\n ��ǰλ�ã��� %d ҳ\n", page);
                if (num % 10 == 0)
                    OutputLink_only10(head, (num / 10 - 1) * 10 + 1);
                else
                    OutputLink_only10(head, num / 10 * 10 + 1);
                printf("\n\n       1)��ҳ   2)��һҳ   3)��һҳ   4)βҳ   0)����\n");
                i = num / 10 * 10 + 1;
            }
            getchar();
            goto back;
        }
        case 0:
            return;
        default:
        {
            printf("\n ����������������룡\n");
            getchar();
            goto back;
        }
        }
    }
}