 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>

int main()
{
	float sum = 1;
	int count = 1;

	float k = 0;

	for (int i = 1; i < 100; i++)
	{

		
		k = count * (i / (i+1.0));

		sum = sum + k;//1+1/2

		count = count * -1;
	
		
	}

	printf("%f", sum);


	return 0;
}