 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
int main()
{
	int arr[] = { 22,44,33,11,43,65,42 };
	int size = sizeof(arr) / sizeof(int);
	int i = 0;//��¼ѭ��������
	int j = 0;//��¼ÿһ������ѭ����λ��

	/* ÿ����ѭ������һ����Сֵ�ŵ���Ӧλ�� */
	for (i = 0; i < size ; i++)
	{
		int min = i;//��¼��Сֵ��λ��
		for (j=size-1;j>=i;j--)   //���ű���
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		int tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;

		/* ÿ����ѭ��������������״ */
		int k;
		printf("the %d for(): ", i);
		for (k = 0; k < size; ++k)
		{
			printf("%d ", arr[k]);
		}
		printf("\n");
	}

	for (int a = 0; a < size; a++)
	{
		printf("%d  ", arr[a]);
	}


	return 0;
}
