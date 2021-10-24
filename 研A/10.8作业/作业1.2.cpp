 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>


int main()
{
	double sum = 0;
	int n = 0;
	float k = 0;
	double factorial = 1;
	int count = 1;

	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		
		factorial = factorial * i;

		if(i%2==0)
		k = -(1.0 / factorial);
		else
		k = (1.0 / factorial);

		sum = sum + k;

	}
	printf("%f", sum);

	return 0;
}