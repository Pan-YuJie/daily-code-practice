 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
//#define get_sum(L,R) (L?sum[R]-sum[L-1]:sum[R])
int sum[5] = {0};

int get_sum(int L, int R)
{
	if (L != 0)
	{
		return sum[R] - sum[L - 1];
	}
	else sum[R];
}

int main()
{
	int arr[5] = { 1,3,5,7,2 };


	for (int i = 1; i < 5; i++)
	{
		sum[i] = sum[i - 1] + arr[i];
	}

	printf("%d", get_sum(3, 4));

	return 0;
}
