#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void menu()
{
	printf("**************************\n");
	printf("**  1. add       2. sub **\n");
	printf("**  3. mul       4. div **\n");
	printf("**  5. xor       0. exit**\n");
	printf("**************************\n");
}

int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

int Xor(int x, int y)
{
	return x ^ y;
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	//pfArr 是一个函数指针数组 
	
	int(*pfArr[])(int, int) = { 0, Add, Sub, Mul, Div, Xor };

	do
	{
		menu();//菜单

		printf("请选择:>");
		scanf("%d", &input);

		if (input >= 1 && input <= 5)
		{
			printf("请输入两个操作数:>");
			scanf("%d%d", &x, &y);

			int ret = pfArr[input](x, y);
			printf("%d\n", ret);
		}

		else if (input == 0)
		{
			printf("退出\n");
		}
		else

		{
			printf("选择错误\n");
		}

	} while (input);
	return 0;
}

