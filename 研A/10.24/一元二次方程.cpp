#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>
#include<math.h>

int calculate(int a, int b, int c)
{
    return b * b - 4 * a * c;
}

int main()
{
    double a, b, c, x1, x2;
    
    printf("������һԪ���η���a,b,c��ֵ:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    double dt=calculate(a,b,c);

    if (dt < 0)
        printf("�˷����޽�");

    else if (dt == 0)
        printf("����ΪһԪһ�η��̣���һ����x=%lf\n", -b / (2 * a));

    else
    {
        x1 = (-b + sqrt(dt)) / (2 * a);
        x2 = (-b - sqrt(dt)) / (2 * a);
        printf("����������ʵ����\n");
        printf("x1=%lf,x2=%lf", x1, x2);
    }
    
}












