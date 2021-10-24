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
        gap = gap / 2;                /*增量缩小，每次减半*/
        for (i = 0; i < n - gap; i++) //n-gap 是控制上限不让越界
        {
            j = i + gap;    //相邻间隔的前后值进行比较
            if (k[i] > k[j])
            {
                temp = k[i];
                k[i] = k[j];
                k[j] = temp;
            }
        }
    }
}