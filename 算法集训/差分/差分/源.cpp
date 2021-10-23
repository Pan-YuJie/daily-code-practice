 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


const int N = 100;

int a[N], b[N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);

        b[i] = a[i] - a[i - 1];      //构建差分数组
    }

    int l, r, c;

    while (m--)
    {
        scanf("%d%d%d", &l, &r, &c);

        b[l] += c;     //表示将序列中[l, r]之间的每个数加上c
        b[r + 1] -= c;

    }

    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];  //求前缀和运算
        printf("%d ", b[i]);
    }

    return 0;
}
