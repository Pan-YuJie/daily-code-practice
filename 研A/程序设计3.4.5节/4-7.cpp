#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,x1,x2,p,q;
	double t;
	printf("������һԪ���η��̵�����ϵ��\n");
	scanf("%lf%lf%lf",&a,&b,&c);
	t=b*b-4*a*c;
	
	if(t>0)
	{
		printf("��������ͬ��ʵ��");
		x1=(-b-sqrt(t))/(2*a);
		x2=(-b+sqrt(t))/(2*a);
		printf("%lf%lf",x1,x2);
	}
	
	else if(t==0)
	{
		printf("��������ͬ��ʵ��");
		x1=x2=(-b)/(2*a);
		printf("%lf%lf",x1,x2);
	}
	
	else
	{
		p=-b/(2*a);
		q=fabs(sqrt(-t)/(2*a));
		printf("���������x1=%f+%fi x2=%f-%fi\n",p,q,p,q);
	}
	return 0;
 } 
