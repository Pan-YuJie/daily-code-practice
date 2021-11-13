#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "panyujie.h"  


int main(int argc, char *argv[]) 
{
	int option=0;
	int i=0,f=0,m=0; 
	int nums_sex[2]={0};
	char x=0;
	float averge=0;

	student S;
	student* s=&S;
	
	Init(&S);
	
	while(option!=-1)
	{
		Menu();
		scanf("%d",&option);
		getchar();
		
		switch(option)
		{
			//插入 
			case 1:
		    for (;s->size <= s->cacpcity;)
			{
			    Input(&S);	
			    
				printf("是否继续输入 (y/n)\n");
				
        		scanf("%c",&x);
        		getchar();
        		
        		if(x!='n'&& x!='y')
        		{
        			while(x!='n'&& x!='y')
        			{
        			 printf("输入错误，请重新输入(y/n)\n");
        			 scanf("%c",&x);
        		  	 getchar();			
					}
			
				} 
				
        		if (x == 'n')
           		  break;	
           		
			}
			break;
			
			//查询 
			case 2:	
			i=Query(&S); 
			
			if(i==-1)
			{
				printf("没有找到");
			}
			
			else
			{
				 printf("-姓名       学号        年龄   性别\n");
				 printf("%-11s  %-11s  %-5s %-5s\n",s->a[i].name,s->a[i].num,s->a[i].age,s->a[i].sex);
			}
			
			break;
		
			//排序 
			case 3:
				Sort(&S); 
			break;
			
			case 4:
				Putout(&S);
			break;
				
			case 5:
				averge =Averge(&S);
				printf("学生年龄平均值:%f\n",averge);
			break;
				
			case 6:
				Count_sex(&S,nums_sex);		
				printf("男生有%d人\n女生有%d人\n",nums_sex[0],nums_sex[1]);
			break;
			
			case 7:
				Delete(&S,nums_sex);
			break;
			
			case 8:
				Printf(&S);
			break;
			
			case 9:
				return 0; 
			
			default:
              printf("你的输入有误，请重新选择菜单。\n");
		}
		
	}
	
	return 0;
}
