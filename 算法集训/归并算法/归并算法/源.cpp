 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int tmpArr[], int left, int mid,int right)
{
	//标记左半区第一个未排序的数组
	int begin1 = left;

	//标记右半区第一个未排序的数组
	int begin2 = mid + 1;

	//临时数组元素的下标
	int pos = left;

	//合并
	while (begin1 <= mid && begin2 <= right)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmpArr[pos++] = arr[begin1++];
		}

		else
		{
			tmpArr[pos++] = arr[begin2++];
		}
	}

	//合并左半区剩余元素
	while (begin1 <= mid)
	{
		tmpArr[pos++] = arr[begin1++];
	}

	//合并右半区剩余元素
	while (begin2 <= right)
	{
		tmpArr[pos++] = arr[begin2++];
	}

	//把临时数组中合并后的元素复制到原来的数组中
	/*while (left <= right)
	{
		arr[left] = tmpArr[left];
		left++;
	}*/

	for (int i = left; i <= right; i++)
	{
		arr[i] = tmpArr[i];
	}
}

//归并排序
void msort(int arr[],int tmpArr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//找终中间点
	int mid = (left + right) / 2;

	//左半区域
	msort(arr, tmpArr, left, mid);
	//右半区域
	msort(arr, tmpArr, mid + 1, right);

	//合并
	merge(arr, tmpArr, left, mid,right);

}

//归并入口
void mergesort(int arr[], int n)
{
	//分配辅助数组
	int* tmpArr = (int*)malloc(sizeof(int)* n);

	if (tmpArr==NULL)
	{
		return;
	}
	
	msort(arr, tmpArr, 0, n - 1);
	free(tmpArr);

}

int main()
{
	int arr[9] = { 2,345,33,4,76,342,2,3,-4 };
	int n = 9;

	for ( int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	mergesort(arr,n);

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}



