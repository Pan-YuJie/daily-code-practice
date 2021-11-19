#include<stdio.h>
int main()
{
	double score;
	printf("请输入百分制成绩");
	scanf("%lf",&score);
	
	if(score<0||score>100)
		printf("error");
		
	int t=score/10;
	
	switch(t)
	{
		case 9:
			printf("优秀");
			break; 
		case 8:
			printf("良好");
			break;
		case 7:
			printf("中等");
			break;
		case 6:
			printf("及格");
			break;
		case 5:
			printf("不及格"); 
			break;
	}
	return 0;
}
