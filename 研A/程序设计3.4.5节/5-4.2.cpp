#include<stdio.h>
int main()
{
	int score,p;
	printf("请输入百分制成绩");
	scanf("%d",&score);
	
	p=score/10;
	if(score<0||score>100)
		printf("错误"); 
		
	switch(p)
	{
		case 10:
		case 9:
			printf("A");
			break; 
		case 8:
			printf("B");
			break;
		case 7:
			printf("C");
			break;
		case 6:
			printf("D");
			break;
		default:
			printf("E");
			break;
	}
	return 0;
}
