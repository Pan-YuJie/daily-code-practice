 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int arr[] = { 22,44,33,11,43,65,42 };
	int size = sizeof(arr) / sizeof(int);
	int i = 0;//记录循环的趟数
	int j = 0;//记录每一次数组循坏的位置

	/* 每轮内循环都将一个最小值放到对应位置 */
	for (i = 0; i < size ; i++)
	{
		int min = i;//记录最小值的位置
		for (j=size-1;j>=i;j--)   //倒着遍历
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;

		/* 每轮内循环后输出数组的现状 */
		int k;
		printf("the %d for(): ", i);
		for (k = 0; k < size; ++k)
		{
			printf("%d ", arr[k]);
		}
		printf("\n");
	}

	for (int a = 0; a < size; a++)
	{
		printf("%d  ", arr[a]);
	}


	return 0;
}
