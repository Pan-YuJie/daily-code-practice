#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char* judgement(int a, int b, int c)
{
	
	char* str=(char*)malloc(100);
	
	int dt=b * b - 4 * a * c;
	
	if (dt < 0)
      strcpy(str,"此方程无解");

    else if (dt == 0)
     strcpy(str,"有一个实根");

    else
	{
		strcpy(str,"方程有两个实根");
    }
    
    return str;
	
}

int main()
{
    double a, b, c, x1, x2;
    
    printf("请输入一元二次方程a,b,c的值:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    char* p=judgement(a,b,c);

    printf("%s\n",p);
    
}












