#include "function.c"
#include "extra.c"

int main()
{
    int choice1;          //һ��ѡ��
    FILE *fp=NULL;             //����һ���ļ�ָ��
    StuLink *head = NULL; //����һ��ͷָ��

    head = ReadFromFile(fp, head); //��ȡѧ����Ϣ

start:
    start_menu();
start1:
    printf("\n ���Ӧ����������ţ�");
    scanf("%d", &choice1);
    if (choice1 == 1 || choice1 == 2 || choice1 == 3 || choice1 == 4 || choice1 == 0)
        goto out; //�������� --> �ƶ��� outλ�ü�������
    else          //���������� --> �ƶ��� startλ�ü�������
    {
        printf("\n ����������������룡\n");
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
        printf("\n �����������...");
        getchar();

        goto start;
    }
    }
    return 0;
}
