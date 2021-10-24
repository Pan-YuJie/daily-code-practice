 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	float sum = 0;
	float k = 0;

	for (int i = 1; i <= 100; i++)
	{
		if (i == 1)
		{
			sum = 1;
		}

		else
		{
			if (i % 2 == 0)
			{
				k = (i-1.0) / i ;
			}

			else
			{
				k = -((i-1.0)/ i);   
			}
		}

		sum = sum + k;

	}

	printf("%f ", sum);
	return 0;
}