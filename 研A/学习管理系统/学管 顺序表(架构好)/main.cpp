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
			//���� 
			case 1:
		    for (;s->size <= s->cacpcity;)
			{
			    Input(&S);	
			    
				printf("�Ƿ�������� (y/n)\n");
				
        		scanf("%c",&x);
        		getchar();
        		
        		if(x!='n'&& x!='y')
        		{
        			while(x!='n'&& x!='y')
        			{
        			 printf("�����������������(y/n)\n");
        			 scanf("%c",&x);
        		  	 getchar();			
					}
			
				} 
				
        		if (x == 'n')
           		  break;	
           		
			}
			break;
			
			//��ѯ 
			case 2:	
			i=Query(&S); 
			
			if(i==-1)
			{
				printf("û���ҵ�");
			}
			
			else
			{
				 printf("-����       ѧ��        ����   �Ա�\n");
				 printf("%-11s  %-11s  %-5s %-5s\n",s->a[i].name,s->a[i].num,s->a[i].age,s->a[i].sex);
			}
			
			break;
		
			//���� 
			case 3:
				Sort(&S); 
			break;
			
			case 4:
				Putout(&S);
			break;
				
			case 5:
				averge =Averge(&S);
				printf("ѧ������ƽ��ֵ:%f\n",averge);
			break;
				
			case 6:
				Count_sex(&S,nums_sex);		
				printf("������%d��\nŮ����%d��\n",nums_sex[0],nums_sex[1]);
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
              printf("�����������������ѡ��˵���\n");
		}
		
	}
	
	return 0;
}
