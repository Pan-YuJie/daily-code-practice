#include<stdio.h>
int main()
{
	int x;
	printf("������һ��0--999����");
	scanf("%d",&x);
	char hz[10][30]{
	"��","һ","��","��","��","��","��","��","��","��"}; 
	if(x<0||x>999)
	{
		printf("����"); 
	}
	if(x>10&&x<100&&x%10==0)
	{
		int b=x/10;
		printf("%sʮ",hz[b]);
	}
	else if(x>10&&x<100&&x%10!=0)
	{
		int b=x%10;
		int c=x/10;
		printf("%sʮ%s",hz[c],hz[b]);
	}
	else if(x>=100&&x%100==0)
	{
		int b=x/100;
		printf("%s��",hz[b]); 
	}
	else if(x>100&&(x/10)%10==0)
	{
		int b,c;
		b=x/100;
		c=x%10;
		printf("%s����%s",hz[b],hz[c]);
	}
	else if(x>100&&x%10==0)
	{
		int b,c;
		b=x/100;
		c=x/10%10;
		printf("%s��%s",hz[b],hz[c]);
	}
	else if(x>100&&x%10!=0&&x/10%10!=0)
	{
		int b,c,d;
		b=x/100;
		c=x/10%10;
		d=x%10;
		printf("%s��%sʮ%s",hz[b],hz[c],hz[d]);
	}
	else
	{
		printf("%s",hz[x]);
	}
	return 0;
}
