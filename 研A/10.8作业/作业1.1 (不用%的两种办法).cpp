 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include<math.h>

int main()
{
	float sum = 0;
	int count = -1;
	float k = 0;

	for (int i = 1; i <= 100; i++)
	{
		
		if (i == 1)
		{
			sum = 1;
		}

		else
		{
			//��ʹ��%
			// ����һ��
			//ʹ��pow�����⺯��
			k = pow(-1 , i) * ((i - 1.0) / i);

			// ��������
			//count = count * -1;
			//k = count * ((i - 1.0) / i);

		}

		sum = sum + k;
	}

	printf("%f", sum);


	return 0;
}