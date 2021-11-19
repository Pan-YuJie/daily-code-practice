#include<stdio.h>
int main()
{
	int x;
	printf("请输入一个整数\n");
	scanf("%d",&x);
	while(x%10>0)
	{
		int t;
		t=x%10;
		printf("%d",t);
		x=x/10;
	}
	return 0;
}
