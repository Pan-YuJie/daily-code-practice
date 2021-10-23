 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int d[6] = { 0 };

void add(int L, int R, int v)
{
	d[L] += v;
	d[R + 1] -= v;


}

int main()
{
	int arr[5] = { 1,3,7,5,2 };

	add(2, 4, 5);
	add(1, 3, 2);
	add(0, 2, -3);


	for (int i = 1; i < 5; i++)
	{
		d[i] = d[i] + d[i - 1];//sum d dµÄÇ°×ººÍ
	}

	for (int j = 0; j < 5; j++)
	{
		arr[j] += d[j];
		printf("%d ", arr[j]);
	}

	return 0;
}