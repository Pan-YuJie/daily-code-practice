 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define MAX 1000


int main()
{
	int arr[] = { 1,2,1,3,3,6,6,7,4,4,5,5,8,8,8,6,4,4 };//��������
	int arr2[MAX] = { 0 };//��������
	int sz = sizeof(arr) / sizeof(int);//���������С

	for (int i = 0; i < sz; i++)
	{
		arr2[i] = arr[i];//���������鸳ֵ
	}

	for (int i = 0; i < sz; i++)
	{
		int temp = arr2[i];
		int count=0;

		for (int j = 0; j < sz; j++)
		{
			if (arr[j] == temp)
			{
				count++;
				arr2[j] = -1;//��ֹ�´��ٴμ���
			}
		}

		if (temp !=-1)//����ӡ�Ѿ����������
		{
			printf("%d�������г�����%d��\n", temp, count);
		}
	}
	return 0;
}