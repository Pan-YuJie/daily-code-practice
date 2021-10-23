 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
void Swap(int*, int*); //��������, ��������������ֵ
void QuickSort(int*, int, int); //��������, ��������

int main()
{
    int i; //ѭ������
    int arr[] = { 900, 2, -58, 3, 34, 5, 76, 7, 32, 4, 43, 9, 1, 56, 8,-70, 635, -234, 532, 543, 2500 };
    QuickSort(arr, 0, 20);    
    printf("����������Ϊ:\n");

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
            --high; //��ǰѰ��
        }

        if (key > arr[high])
        {
            Swap(&arr[low], &arr[high]);
            ++low;
        }

        while (low < high && key >= arr[low])
        {
            ++low; //���Ѱ��
        }

        if (key < arr[low])
        {
            Swap(&arr[low] , &arr[high]);

            --high;
        }
    }


    QuickSort(arr, i, low - 1); //��ͬ���ķ�ʽ�Էֳ�������ߵĲ��ֽ���ͬ�ϵ�����
    QuickSort(arr, low + 1, j); //��ͬ���ķ�ʽ�Էֳ������ұߵĲ��ֽ���ͬ�ϵ�����
}