
#include<stdio.h>

int main()
{
    int n = 5;
    int a[] = { 4,3,5,-2,1 };
    int x;
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n-1; i++)//����Խ����ʣ���ѭ���������ƾͿ�
        {
            if (a[i] > a[i + 1])
            {
                x = a[i];
                a[i] = a[i + 1];
                a[i + 1] = x;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}
