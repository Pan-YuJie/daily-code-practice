#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
void shellsort(int*, int);

int main()
{
	int arr[10] = { -2,76,43,44,7,3,5,8,9,55 };

	shellsort(arr,10);

    for(int i=0;i<10;i++)
    printf("%d ", arr[i]);

	return 0;
}

void shellsort(int* k, int n)
{
    int i, j, temp, gap = n;
    while (gap > 1)
    {
        gap = gap / 2;                /*������С��ÿ�μ���*/
        for (i = 0; i < n - gap; i++) //n-gap �ǿ������޲���Խ��
        {
            j = i + gap;    //���ڼ����ǰ��ֵ���бȽ�
            if (k[i] > k[j])
            {
                temp = k[i];
                k[i] = k[j];
                k[j] = temp;
            }
        }
    }
}