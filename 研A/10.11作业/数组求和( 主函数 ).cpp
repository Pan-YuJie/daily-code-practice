#define _CRT_SECURE_NO_WARNINGS 1


#include<stdio.h>
#include<stdlib.h>

int main()
{
	int n = 0;
	int sum = 0;

	printf("������Ҫʹ�õ������С��>");
	scanf("%d", &n);

	int* arr = (int*)malloc(sizeof(int)*n);

	if (arr == NULL)
	{
		return 0;
	}

	
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=", i);
		scanf("%d", arr+i); 
	}

	for (int j = 0; j < n; j++)
	{
		sum += *(arr+j);
	}

	printf("%d", sum);

	free(arr);

	return 0;
}