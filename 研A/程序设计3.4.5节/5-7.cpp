//����һ�������գ������Ӧ����
#include <stdio.h>
int main()
{
	char hz[13][30]=
	{"��","һ","��","��","��","��","��","��","��","��","ʮ","ʮһ","ʮ��" };
    int year,month,day;
    printf("������������"); 
	scanf("%d%d%d",&year,&month,&day);
	int a,b,c,d;
	int e,f;
	a=year%10;
	b=year/10%10;
	c=year/100%10;
	d=year/1000;
	
	printf("%s%s%s��",hz[d],hz[c],hz[b],hz[a]) ;
	printf("%s��",hz[month]);
	if (day>12)
	{
		e=day%10;
		f=day/10;
		printf("%sʮ%s��",hz[f],hz[e]);
	}
	else 
	    printf("%s��",hz[day]);
return 0 ;
	 
}
