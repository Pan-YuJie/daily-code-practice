 #define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
int Fib(int n)
{
	int f1 = 1;
	int f2 = 1;
	for (int i = 3; i <= n; ++i)
	{
		f2 = f1 + f2;
		f1 = f2 - f1;

		if (n == 1 || n == 2) 
		{  
			printf("第%d个斐波那契数是%d.\n", n, f2);  
		}
		else 
		{
			printf("第%d个斐波那契数是%d.\n", n, f2); 
		}
	}

	return 0;
}

int Fibonacci(int n)
{
	if (n == 1 || n == 2)
	{  
		return 1;
	}

	return Fibonacci(n - 1) + Fibonacci(n - 2);  
}


int main()
{
	int n;

	scanf("%d", &n);

	int b=Fibonacci(n);
	
	printf("%d", b);

	return 0;
}
