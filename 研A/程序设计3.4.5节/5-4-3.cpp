#include <stdio.h>
int main()
{
	char grade;
	scanf("%s",&grade);
	
	switch(grade)
	{
		case 'A':
			printf("90~100");
			break; 
		case 'B':
			printf("80~90");
			break;
		case 'C':
			printf("70~80");
			break;
		case 'D':
			printf("60~70");
			break;
		case 'E':
			printf("0~60");
			break;
		default:
			printf("error");
	 } 
 }
