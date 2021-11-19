#include<stdio.h>
int main()
{
	int x;
	printf("请输入一个0--999的数");
	scanf("%d",&x);
	char hz[10][30]{
	"零","一","二","三","四","五","六","七","八","九"}; 
	if(x<0||x>999)
	{
		printf("错误"); 
	}
	if(x>10&&x<100&&x%10==0)
	{
		int b=x/10;
		printf("%s十",hz[b]);
	}
	else if(x>10&&x<100&&x%10!=0)
	{
		int b=x%10;
		int c=x/10;
		printf("%s十%s",hz[c],hz[b]);
	}
	else if(x>=100&&x%100==0)
	{
		int b=x/100;
		printf("%s百",hz[b]); 
	}
	else if(x>100&&(x/10)%10==0)
	{
		int b,c;
		b=x/100;
		c=x%10;
		printf("%s百零%s",hz[b],hz[c]);
	}
	else if(x>100&&x%10==0)
	{
		int b,c;
		b=x/100;
		c=x/10%10;
		printf("%s百%s",hz[b],hz[c]);
	}
	else if(x>100&&x%10!=0&&x/10%10!=0)
	{
		int b,c,d;
		b=x/100;
		c=x/10%10;
		d=x%10;
		printf("%s百%s十%s",hz[b],hz[c],hz[d]);
	}
	else
	{
		printf("%s",hz[x]);
	}
	return 0;
}
