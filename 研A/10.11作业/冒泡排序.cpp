 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int main()
{
	int arr[] = { 6,4,77,432,312,56,7,2,4,6,34,234,22 };

	int len = sizeof(arr) / sizeof(int);

	
	for (int i = 0; i < len-1 ; i++)
	{
		for (int j = 0; j < len-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}

	for (int i = 0; i < len - 1; i++)
	{
		printf("%d ", *(arr + i));//µÈ¼ÛÓÚarr[i]
	}

	return 0;
}
