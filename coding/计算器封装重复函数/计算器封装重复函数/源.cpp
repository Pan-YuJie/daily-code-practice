 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void cal_menu()
{
	printf("*****************************\n");
	printf("*****   1.Add     2.Sub  ****\n");
	printf("*****   3.Mul     4.Div  ****\n");
	printf("******    0.exit     ********\n");
	printf("*****************************\n");
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

void Calc(int (*pf)(int, int))  
{
	int x = 0;
	int y = 0;
	printf("请输入两个操作数:>>\n");
	scanf("%d%d", &x, &y);
	printf("%d\n",(*pf)(x, y)); 
}

int main()
{
	int input;//根据菜单提示输入操作符

	do
	{
		cal_menu();
		printf("请选择操作:>>\n");
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			Calc(Add);
			break;
		case 2:
			Calc(Sub);
			break;
		case 3:
			Calc(Mul);
			break;
		case 4:
			Calc(Div);
			break;
		case 0:
			printf("退出!\n");
			break;
		default:
			printf("选择错误!\n");
			break;
		}
	} while (input);
	return 0;
}
