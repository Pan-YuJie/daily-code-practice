
#include <stdio.h>

void swap3(int *x, int *y)//异或
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

void swap1(int* x, int* y)//传址
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

//三种方法
int main()
{
    int a = 0, b = 0;
    printf("输入交换的两个值\n");
    scanf("%d%d", &a, &b);

    swap1(&a, &b);
    printf("输出交换的两个值\n");
    printf("%d %d\n", a, b);

    swap3(&a, &b);
    printf("输出再次交换的两个值\n");
    printf("%d %d\n", a, b);

    swap2(&a, &b);
    printf("输出再次交换的两个值\n");
    printf("%d %d\n", a, b);


    return 0;
}
