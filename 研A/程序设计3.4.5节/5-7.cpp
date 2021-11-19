//输入一个年月日，输出对应汉字
#include <stdio.h>
int main()
{
	char hz[13][30]=
	{"零","一","二","三","四","五","六","七","八","九","十","十一","十二" };
    int year,month,day;
    printf("请输入年月日"); 
	scanf("%d%d%d",&year,&month,&day);
	int a,b,c,d;
	int e,f;
	a=year%10;
	b=year/10%10;
	c=year/100%10;
	d=year/1000;
	
	printf("%s%s%s年",hz[d],hz[c],hz[b],hz[a]) ;
	printf("%s月",hz[month]);
	if (day>12)
	{
		e=day%10;
		f=day/10;
		printf("%s十%s日",hz[f],hz[e]);
	}
	else 
	    printf("%s日",hz[day]);
return 0 ;
	 
}
