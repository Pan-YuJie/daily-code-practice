 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int a[101], n; //定义两个全局变量 

void QuickSort(int left, int right) {
	int i, j, temp, t;
	if (left > right)
		return;
	temp = a[left];
	i = left;
	j = right;
	while (i != j)
	{
		while (a[j] >= temp && i < j)
		{
			j--;
		}
		while (a[i] <= temp && i < j) {
			i++;
		}
		if (i < j) //交换两个数在数组中的位置 
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	//最终将基数定位 
	a[left] = a[i];
	a[i] = temp;

	QuickSort(left, i - 1);   //递归处理左侧 

	QuickSort(i + 1, right);  //递归处理右侧 
}

int main() 
{
	int i, j, t;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	QuickSort(0, n - 1);   //快速排序调用 

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
