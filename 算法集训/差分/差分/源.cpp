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

        b[i] = a[i] - a[i - 1];      //�����������
    }

    int l, r, c;

    while (m--)
    {
        scanf("%d%d%d", &l, &r, &c);

        b[l] += c;     //��ʾ��������[l, r]֮���ÿ��������c
        b[r + 1] -= c;

    }

    for (int i = 1; i <= n; i++)
    {
        b[i] += b[i - 1];  //��ǰ׺������
        printf("%d ", b[i]);
    }

    return 0;
}
