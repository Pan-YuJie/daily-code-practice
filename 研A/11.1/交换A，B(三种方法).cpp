
#include <stdio.h>

void swap3(int *x, int *y)//���
{
    *x = *x ^ *y;
    *y = *x ^ *y;
    *x = *x ^ *y;
}

void swap2(int* x, int* y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void swap1(int* x, int* y)//��ַ
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//���ַ���
int main()
{
    int a = 0, b = 0;
    printf("���뽻��������ֵ\n");
    scanf("%d%d", &a, &b);

    swap1(&a, &b);
    printf("�������������ֵ\n");
    printf("%d %d\n", a, b);

    swap3(&a, &b);
    printf("����ٴν���������ֵ\n");
    printf("%d %d\n", a, b);

    swap2(&a, &b);
    printf("����ٴν���������ֵ\n");
    printf("%d %d\n", a, b);


    return 0;
}
