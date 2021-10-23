 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int Quicksort(int arr[], int left, int right)
{
	if (left >= right)
	{
		return 0;
	}

	int l = left;
	int r = right;
	int key = arr[left];

	while (l < r)
	{
		while (l < r && key >= arr[r])
		{
			r--;
		}
		while (l < r && key <= arr[l])
		{
			l++;
		}

		if (l < r)
		{
			int tmp = arr[r];
			arr[r] = arr[l];
			arr[l] = tmp;
		}

	}

	arr[left] = arr[l];
	arr[l] = key;

	Quicksort(arr, left, l - 1);//处理前面
	Quicksort(arr, l + 1, right);//处理后面
}

int main()
{
	int arr[10] = { 13,6,1,2,7,8,10,12,11,5 };
	
	for(int i=0;i<10;i++)
	{
	printf("%d  ", arr[i]);
	}

	Quicksort(arr,0,9);
	printf("\n");

	for (int i = 0; i < 10; i++)
	{
		printf("%d  ", arr[i]);
	}

	return 0;

}