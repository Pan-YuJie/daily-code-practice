 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int a[101], n; //��������ȫ�ֱ��� 

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
		if (i < j) //�����������������е�λ�� 
		{
			t = a[i];
			a[i] = a[j];
			a[j] = t;
		}
	}

	//���ս�������λ 
	a[left] = a[i];
	a[i] = temp;

	QuickSort(left, i - 1);   //�ݹ鴦����� 

	QuickSort(i + 1, right);  //�ݹ鴦���Ҳ� 
}

int main() 
{
	int i, j, t;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}

	QuickSort(0, n - 1);   //����������� 

	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	return 0;
}
