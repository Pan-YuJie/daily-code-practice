 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#define MAX 100
int main()
{
	int a[] = { 1,2,1,6,6,7,4,4 };
	int sz = sizeof(a) / sizeof(int);

	int  arr[MAX] = { 0 };

	for (int i = 0; i < sz; i++)
	{
		int temp = a[i];
		for (int j = 0; j < sz; j++)
		{
			if (a[i] == a[j])
			{
				arr[i]++;
			}
		}

		if (arr[i] != 0)
		{
			printf("%d在数组中出现%d次\n", temp, arr[i]);
		}
	
	}

	return 0;
}