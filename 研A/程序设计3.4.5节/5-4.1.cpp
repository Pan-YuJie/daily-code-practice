#include<stdio.h>
int main()
{
	double score;
	printf("������ٷ��Ƴɼ�");
	scanf("%lf",&score);
	
	if(score<0||score>100)
		printf("error");
		
	int t=score/10;
	
	switch(t)
	{
		case 9:
			printf("����");
			break; 
		case 8:
			printf("����");
			break;
		case 7:
			printf("�е�");
			break;
		case 6:
			printf("����");
			break;
		case 5:
			printf("������"); 
			break;
	}
	return 0;
}
