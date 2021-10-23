 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()

{
	int arr[9] = { 2, 5, 6, 8, 9, 33, 44, 65, 78 };

	int left = 0;
	int right = 8;
	
	int targe = 65;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (arr[mid]==targe)
		{
			printf("找到了下标是%d",mid);
			break;
		}
		else if (arr[mid] > targe)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}

	}

	if (left > right)
	{
		printf("找不到");
	}

	return 0;
}
