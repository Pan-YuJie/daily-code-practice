#include <stdio.h>
int main()
{
	int i,a,b,c;
	scanf("%d",&i);
	if(i<=999&&i>=99)
	{

		a=i%10;
		b=i/10%10;
		c=i/100%10;
	
	 if(i==a*a*a+b*b*b+c*c*c)
	   printf("是水仙花数"); 
	else
	printf("不是水仙花数");
    }
    else
    printf("不是水仙花数"); 
 } 
