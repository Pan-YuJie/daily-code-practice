 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Swap(int*, int*); //函数声明, 交换两个变量的值
void QuickSort(int*, int, int); //函数声明, 快速排序

int main()
{
    int i; //循环变量
    int arr[] = { 900, 2, -58, 3, 34, 5, 76, 7, 32, 4, 43, 9, 1, 56, 8,-70, 635, -234, 532, 543, 2500 };
    QuickSort(arr, 0, 20);    
    printf("最终排序结果为:\n");

    for (i = 0; i < 21; ++i)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void Swap(int* p, int* q)
{
    int tmp;
    tmp = *p;
    *p = *q;
    *q = tmp;
    return;
}

void QuickSort(int* arr, int low, int high)
{
    int i = low;
    int j = high;
    int key = arr[low];
    if (low >= high) 
    {
        return;
    }

    while (low < high) 
    {
        while (low < high && key <= arr[high])
        {
            --high; //向前寻找
        }

        if (key > arr[high])
        {
            Swap(&arr[low], &arr[high]);
            ++low;
        }

        while (low < high && key >= arr[low])
        {
            ++low; //向后寻找
        }

        if (key < arr[low])
        {
            Swap(&arr[low] , &arr[high]);

            --high;
        }
    }


    QuickSort(arr, i, low - 1); //用同样的方式对分出来的左边的部分进行同上的做法
    QuickSort(arr, low + 1, j); //用同样的方式对分出来的右边的部分进行同上的做法
}