#include <stdio.h>
int main()
{
	int x,i;
	printf("请输入年份:"); 
	scanf("%d",&x);
	i=x%4;
	if(i==0)
	printf("该年为闰年");
	else
	printf("该年不是闰年"); 
	
}
