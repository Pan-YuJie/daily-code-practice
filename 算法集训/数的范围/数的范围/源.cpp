 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
int main()
{

	int arr[] = { 1,2,4,7,8,8,8,9,10,11,15 };

	int target = 8;
	
	int L=0;
	int R=0;
	int i = 0;
	int j = (sizeof(arr)/sizeof(int))-1;

	while (i<j)
	{
	int mid = (i+j)/ 2;

		if (target <= arr[mid])
			j = mid;
		else
			i = mid + 1;
	}

	if (arr[i] != target)
	{
		printf("找不到");
	}

	else
	{

		 L = i;
		int i = 0;
		int j = (sizeof(arr) / sizeof(int)) - 1;

		while (i < j)
		{
			int mid = (i +j  + 1)/2;

			if (target >= arr[mid])
				i = mid;
			else
				j = mid - 1;
		}
		R = j;
	}

	
	printf("下标范围是：[%d,%d]", L, R);
	return 0;
}