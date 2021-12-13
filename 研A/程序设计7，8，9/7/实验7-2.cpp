#include<stdio.h>
int main()
{
	int day,i;
	double money,p,dj;
	dj=0.8;
	i=2; 
	while(1)
	{
		money=dj*i+money;
		i=i*2;
		day++;
		if(i>100)
			{
				i=i/2;
				break;
			}
	}
	printf("%d\n",i); 
	p=money/day;
	printf("平均花%.2lf元",p);
	return 0;
 } 
