 #define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int factorials_1(int n)//Ñ­»µ
{
	int fac = 1;

	for (int i = 1; i <= n; i++)
	{
		fac = fac * i;
	}
	
	return fac;
}

int factorials_2(int n)//µÝ¹é
{
	if (n == 1)
	{
		return 1;
	}

	return n * factorials_2(n - 1);
}

int main()
{
	int n = 0;
	int fac1 = 0;
	int fac2 = 0;

	scanf("%d", &n);

	fac1= factorials_1(n);

	fac2 = factorials_2(n);

	printf("%d", fac1);//Ñ­»µ
	printf("\n");
	printf("%d", fac2);//µÝ¹é

	return 0;
}