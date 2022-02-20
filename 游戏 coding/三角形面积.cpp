#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, area;
    printf("Input a,b,c:");
    scanf("%f%f%f", &a, &b, &c);

    if (a + b > c && c - a < b)
    {
        float s = (a + b + c) / 2;
        area = sqrt(s * (s - a) * (s - b) * (s - c));
        printf("area=%f", area);
    }

    else

        printf("不能构成三角形");

    return 0;
}