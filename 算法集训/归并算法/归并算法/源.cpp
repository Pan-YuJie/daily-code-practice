 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

void merge(int arr[], int tmpArr[], int left, int mid,int right)
{
	//����������һ��δ���������
	int begin1 = left;

	//����Ұ�����һ��δ���������
	int begin2 = mid + 1;

	//��ʱ����Ԫ�ص��±�
	int pos = left;

	//�ϲ�
	while (begin1 <= mid && begin2 <= right)
	{
		if (arr[begin1] < arr[begin2])
		{
			tmpArr[pos++] = arr[begin1++];
		}

		else
		{
			tmpArr[pos++] = arr[begin2++];
		}
	}

	//�ϲ������ʣ��Ԫ��
	while (begin1 <= mid)
	{
		tmpArr[pos++] = arr[begin1++];
	}

	//�ϲ��Ұ���ʣ��Ԫ��
	while (begin2 <= right)
	{
		tmpArr[pos++] = arr[begin2++];
	}

	//����ʱ�����кϲ����Ԫ�ظ��Ƶ�ԭ����������
	/*while (left <= right)
	{
		arr[left] = tmpArr[left];
		left++;
	}*/

	for (int i = left; i <= right; i++)
	{
		arr[i] = tmpArr[i];
	}
}

//�鲢����
void msort(int arr[],int tmpArr[], int left, int right)
{
	if (left >= right)
	{
		return;
	}

	//�����м��
	int mid = (left + right) / 2;

	//�������
	msort(arr, tmpArr, left, mid);
	//�Ұ�����
	msort(arr, tmpArr, mid + 1, right);

	//�ϲ�
	merge(arr, tmpArr, left, mid,right);

}

//�鲢���
void mergesort(int arr[], int n)
{
	//���丨������
	int* tmpArr = (int*)malloc(sizeof(int)* n);

	if (tmpArr==NULL)
	{
		return;
	}
	
	msort(arr, tmpArr, 0, n - 1);
	free(tmpArr);

}

int main()
{
	int arr[9] = { 2,345,33,4,76,342,2,3,-4 };
	int n = 9;

	for ( int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	mergesort(arr,n);

	printf("\n");

	for (int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}



