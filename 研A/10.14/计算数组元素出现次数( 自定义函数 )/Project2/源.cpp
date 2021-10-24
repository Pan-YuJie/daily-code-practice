#include <stdio.h>
#define MAX 1000

void Nums_count(int *,int); //函数声明

int main()
{
	int arr[] = { 1,2,1,3,3,6,6,7,4,4,5,5,8,8,8,6,4,4 };//给定数组
	int sz = sizeof(arr) / sizeof(int);//计算数组大小

	Nums_count(arr,sz);

	return 0;

}

void Nums_count(int* arr1, int sz)
{
	int arr2[MAX] = { 0 };//辅助数组


	for (int i = 0; i < sz; i++)
	{
		arr2[i] = arr1[i];//给辅助数组赋值
	}

	for (int i = 0; i < sz; i++)
	{
		int temp = arr2[i];
		int count = 0;

		for (int j = 0; j < sz; j++)
		{
			if (arr1[j] == temp)
			{
				count++;
				arr2[j] = -1;//防止下次再次计算
			}
		}

		if (temp != -1)//不打印已经计算过的数
		{
			printf("%d在数组中出现了%d次\n", temp, count);
		}
	}
}
