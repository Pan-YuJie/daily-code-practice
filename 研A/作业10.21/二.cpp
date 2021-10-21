 #define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	int a[] = { 1,2,3,4,5 };

	int* p = NULL;
	p = a;//p指向了数组a的首地址

	int  sum = 0;
	for (int i = 0; i < 5; i++)
	{
		sum += p[i];
	}

	printf("%d\n", sum);//15

	
	int x = 10; int y = 20;

	p = &x;
	
	int z = x + *p;
	//z=10+10   z=20
	
	int* q = NULL;
	q = a;//q是指向数组a的首地址

	z = *p + *q;
	//z=10+1=11  z=11

	*q = 30;//x=30
	z = a[0] + a[2];
	//z = 30 + 3 = 33

	q = p;//p的地址赋予了q，指向同一块内存

	a[2] = *p + *q;
	//a[2]=10+10=20  a[2]=20
	

	z = a[0] + a[2];
	//z=30+20=50  z=50

	p = &a[2];
	*p = *q;
	
	z = a[0] + *p;
	//z=30+10=40  z =40

	for (int i = 0; i < 3; i++)
	printf("%d\n", p[i]);//越界

	sum = 0;
	for (int i = 0; i < 3; i++)
	{
		sum += p[i];
	}
	
	printf("%d", sum);//19




	return 0;
}