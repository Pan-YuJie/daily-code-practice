#include<stdio.h>
int main()
{
	int score,p;
	printf("������ٷ��Ƴɼ�");
	scanf("%d",&score);
	
	p=score/10;
	if(score<0||score>100)
		printf("����"); 
		
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
