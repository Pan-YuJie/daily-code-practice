#include <stdio.h>
#include <math.h>
main()
{
	double a,b,c,ja,jb,jc,cosa,cosb,cosc;
	scanf("%lf%lf%lf",&a,&b,&c); 
	if(a>0 && b>0 && c>0 && a+b>c && a+c>b&& b+c>a)
	{
		cosa=(b*b+c*c-a*a)/(2*b*c);
		cosb=(a*a+c*c-b*b)/(2*a*c);
		cosc=(b*b+a*a-c*c)/(2*a*b);
	    ja=acos(cosa);
	    jb=acos(cosb);
	    jc=acos(cosc);
	    printf("½ÇA=%f ½ÇB=%f ½ÇC=%f\n",ja,ja,jc);
	    printf("½ÇA=%f ½ÇB=%f ½ÇC=%f\n",ja*180/3.14,jb*180/3.14,jc*180/3.14);
	}
	else
	printf("²»ÊÇÈý½ÇÐÎ\n");
}
