#include<stdio.h>
int main(int argc,char*argv[])
{
	int p;
	float money,tcl;
	printf("请输入所接工程利润:");
	scanf("%d",&p);
	switch((p-1)/1000)
	{
		case 0:
			   tcl=0;
			   break;
	    case 1:
	    	   tcl=0.1;
	    	   break;
	    case 2:
	    case 3:
	    case 4:
	    	   tcl=0.15;
	    	   break;
	    case 5:
	    case 6:
	    case 7:
	    case 8:
	    case 9:
	    	   tcl=0.2;
	    	   break;
	    default:
	    	   tcl=0.25;
	    	   break;
	}
	money=500+p*tcl;
	printf("总工资为:%f",money);
	return 0;
}
