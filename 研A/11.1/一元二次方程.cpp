#define _CRT_SECURE_NO_WARNINGS 1

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

char* judgement(int a, int b, int c)
{
	
	char* str=(char*)malloc(100);
	
	int dt=b * b - 4 * a * c;
	
	if (dt < 0)
      strcpy(str,"�˷����޽�");

    else if (dt == 0)
     strcpy(str,"��һ��ʵ��");

    else
	{
		strcpy(str,"����������ʵ��");
    }
    
    return str;
	
}

int main()
{
    double a, b, c, x1, x2;
    
    printf("������һԪ���η���a,b,c��ֵ:\n");
    scanf("%lf%lf%lf", &a, &b, &c);
    
    char* p=judgement(a,b,c);

    printf("%s\n",p);
    
}












