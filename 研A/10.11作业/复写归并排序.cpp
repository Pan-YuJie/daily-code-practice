 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>


void meger(int arr[], int tmpArr[], int start, int mid, int end)
{
	int index = start;
	int i = start;
	int j = mid + 1;

	while (i <= mid && j <= end)
	{
		if (arr[i] < arr[j])
		{
			tmpArr[index++] = arr[i++];
		}
		else
		{
			tmpArr[index++] = arr[j++];
		}

	}

	while (i <= mid)
	{
		tmpArr[index++] = arr[i++];
	}

	while (j <= end)
	{
		tmpArr[index++] = arr[j++];
	}

	for (int i = start; i <= end; i++)//※※ 小于等于注意注意 ※※
	{
		arr[i] = tmpArr[i];
	}
}

void msort(int arr[], int tmpArr[], int start, int end)
{
	if (start >= end)
	{
		return;
	}

	int mid = (start + end) / 2;
	
	msort(arr, tmpArr, start, mid);
	msort(arr, tmpArr, mid+1, end);

	meger(arr, tmpArr, start, mid, end);


}

//归并入口
void megersort(int arr[], int n)
{
	int* tmpArr = (int*)malloc(sizeof(int) * n);

		if (tmpArr == NULL)
		{
			return;
		}

	msort(arr, tmpArr, 0,n-1);

	free(tmpArr);
}

int main()
{
	int arr[10] = { 1,43,5,78,5,3,8,56,89,44 };
	
	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}


	megersort(arr, 10);

	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}
