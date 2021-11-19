#include <stdio.h>
int main()
{
	int x,y,x1,x2,y1,y2;
	scanf("%d%d",&x,&y);
	int a1,a2;
	if(x<y)
	a1=x;
	else
	a1=y;
	for(int i=a1;i<=a1;i--)
	{
		x1=x%i;
		y1=y%i;
		if(x1==0&&y1==0)
		{
		printf("最大公因数是：%d\n",i);
		break;
	}
	}
	if(x>y)
	a2=x;
	else
	a2=y;
	for(int i=a2;i>=a2;i++)
	{
	    x2=i%x;
		y2=i%y;
		if(x2==0&&y2==0)
		{
		printf("最小公倍数是：%d",i);
		break;
	}
	}
	
	
}
