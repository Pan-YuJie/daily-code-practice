#include<stdio.h>
#include<string.h>
int main()
{
	int day;
	char a[30];
	printf("������1-7��һ������\n");
	scanf("%d",&day);
	switch(day)
	{
		case 1:
			printf("Monday");
			break;
		case 2:
			printf("Tuesday");
			break;
		case 3:
			printf("Wednesday");
			break;
		case 4:
			printf("Thursday");
			break;
		case 5:
			printf("Friday");
			break;
		case 6:
			printf("Saturday");
			break;
		case 7:
			printf("Sunday");
			break;
	}
	return 0;
}
	

