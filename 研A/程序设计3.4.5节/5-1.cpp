#include <stdio.h>
int main()
{
	int a;
	float x,y; 
	printf("请输入水果编号和重量：");
	scanf("%d%f",&a,&x);
	if(a==1)
	y=2*x;
	else if(a==2)
	y=2.5*x;
	else if(a==3)
	y=3*x;
	else if(a==4)
	y=4.5*x;
	printf("%f",y);
	return 0;
	 
 } 
