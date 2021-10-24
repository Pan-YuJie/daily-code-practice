 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<stdlib.h>

int main() 
{
    int arr[] = { 1,5,4,6,4,1,1,2,2,5 };
    int sz = sizeof(arr) / sizeof(int);
    int max = 0;

    for (int i = 0; i < sz; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    int range = max + 1;

    int* cnt = (int*)malloc(sizeof(int) * range);

    if (cnt == NULL)
    {
        return 0;
    }

    for (int i = 0; i < range; i++)
    {
        *(cnt + i) = 0;
    }

    for (int i = 0; i < sz; i++)
    {
        cnt[arr[i]]++;
    }

    for (int i = 0; i <range; i++) 
    {
        if (cnt[i] != 0)
        {
            printf("%d 在数组中出现次数是 %d\n", i, cnt[i]);
        }
    }

    free(cnt);

    return 0;
}
