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
    
    printf("请输入一元二次方程a,b,c的值:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    double dt=calculate(a,b,c);

    if (dt < 0)
        printf("此方程无解");

    else if (dt == 0)
        printf("方程为一元一次方程，有一个根x=%lf\n", -b / (2 * a));

    else
    {
        x1 = (-b + sqrt(dt)) / (2 * a);
        x2 = (-b - sqrt(dt)) / (2 * a);
        printf("方程有两个实根：\n");
        printf("x1=%lf,x2=%lf", x1, x2);
    }
    
}












