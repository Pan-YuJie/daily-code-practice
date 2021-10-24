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
			//不使用%
			// 方法一：
			//使用pow开方库函数
			k = pow(-1 , i) * ((i - 1.0) / i);

			// 方法二：
			//count = count * -1;
			//k = count * ((i - 1.0) / i);

		}

		sum = sum + k;
	}

	printf("%f", sum);


	return 0;
}