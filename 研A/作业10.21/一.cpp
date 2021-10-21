 #define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int x = 3;
	int y = 4;

	int* p = NULL;
	p = &x;

	int z = x + *p;
	//z=3+3=6

	*p = x + y;
	//*p=3+4=7

	int* q = NULL;
	q = &y;
	
	x = z + *q;
	//x=6+4=10 

	*q = *p + 1;
	//*q=10+1=11  ♥
	
	*p = *p + *q;
	//*p= 10+11=21


	q[0] = p[0] + x;
	//*q= 21+21=42  ♥

	q = p;
	//P的地址赋给了q,q的地址没了，p和q指向42

	
	*q = *p + y;
	//63=21+42


	return 0;
}