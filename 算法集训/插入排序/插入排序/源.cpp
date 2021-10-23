#define _CRT_SECURE_NO_WARNINGS 

#include<stdio.h>

void StraightSort(int*, int);

int main()
{
	int arr[10] = { 1,4,3,6,996,45,3,55,96,44 };

	StraightSort(arr, 10);

	for(int i=0;i<10;i++)
	printf("%d ", arr[i]);

	return 0;
}

void StraightSort(int* arr, int len)
{
	int tmp;
	int i;
	int j;

	for (i = 1; i < len; i++)
	{
		tmp = arr[i];

		for (j = i - 1; j>0 && arr[j] > tmp; j--)
		{
			arr[j + 1] = arr[j];
		}

		arr[j + 1] = tmp;
	}

}