#include <stdio.h>
int main()
{ 
    float x; 
	printf("输入该学生的成绩:");
	scanf("%f",&x);
	
	if(x<=100&&x>=90)
	 printf("A\n");
	 
	else if(x<90&&x>=80)
	 printf("B\n");
	 
	else if(x<80&&x>=70)
	 printf("C\n");
	 
	else if(x<70&&x>=60)
	 printf("D\n");
	 
	else if(x<60&&x>=0)
	 printf("E\n");
	 
	else
	 printf("输入错误\n");
}
