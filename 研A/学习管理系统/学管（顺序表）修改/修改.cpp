#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stud_type
{
	struct stud_type* a;
	int size;// 有效数据 
	int cacpcity; //容量 
	
    char num[20]; //学号 
    char name[10];//姓名 
    char sex[20]; //F 、 M
    char age[10]; //年龄 
};

typedef stud_type student;

FILE *fp;          /*输入文件指针*/
FILE *fp_sert;     /*排序文件指针*/
FILE *fp_output;   /*查找文件指针*/

void Menu();   /*菜单*/ 
void Init(student*);/*初始化*/
void Input(student*);  /*输入信息*/
void Putout(student*); /*输出信息*/
int Query(student*);  /*查询信息*/
void Sort(student*);   /*排序*/
float Averge(student*); /*平均值*/ 
void Count_sex(student*,int*);/*计算男女个数*/ 
void Delete(student*,int* nums_sex); /*删除学生*/ 
void Printf(student*);

int main()
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

//初始化 
void Init(student* ps)
{
	ps->a=NULL;
	ps->cacpcity=0;
	ps->size=0;
} 

//检查扩容 
void CheckCacpcity(student* ps)
{
	if(ps->size==ps->cacpcity)
	{
		int newcacpcity=ps->cacpcity==0?5:ps->cacpcity*2;
		
		student* tmp=(student*)realloc(ps->a,newcacpcity*2*(sizeof(student)));
		
		if (tmp == NULL)
		{
			printf("realloc is fail\n");
			exit(-1);
		}

		else
		{
			ps->a = tmp;
			ps->cacpcity = newcacpcity;
		}
		
	}
	
}

//插入 
void Input(student* ps)
{	
	
	if ((fp = fopen("input.txt", "wb")) == NULL)
    {
       	printf("不能打开文件!");
      	exit(0);
   	}
   	
    CheckCacpcity(ps);
    	
    printf("\n请输入第%d个学生信息:\n姓名:", ps->size + 1);
    gets(ps->a[ps->size].name);
    
    printf("学号:");
    gets(ps->a[ps->size].num);
    
    printf("年龄:");
    gets(ps->a[ps->size].age);
        
    printf("性别（F & M）: ");
    gets(ps->a[ps->size].sex);
    
    
    fwrite(&ps->a[ps->size], sizeof(ps->a[ps->size]), 1, fp); 
    
    ps->size++; 
    
	fclose(fp);
}

void Putout(student* ps)
{  
     int i;
     
     /*输出输入的文件*/
     fp=fopen("input.txt","rb");
     printf("input输入文件：\n");
     
     for(i=0;i<ps->size;i++)
     {  
         fread(&ps->a[i],sizeof(ps->a[0]),1,fp);
         printf("%-15s%-11s%-3s%-3s\n",ps->a[i].name,ps->a[i].num,ps->a[i].age,ps->a[i].sex);
     }
     printf("\n\n");
     

    /*输出已排序的文件*/
     fp_sert=fopen("serted.txt","rb");
     printf("\nserted排序文件:\n");
     for(i=0;i<ps->size;i++)
     {
         fread(&ps->a[i],sizeof(ps->a[0]),1,fp);
         printf("%-15s%-11s%-3s%-3s\n",ps->a[i].name,ps->a[i].num,ps->a[i].age,ps->a[i].sex);
     }
     
      printf("\n\n");
  
     fclose(fp);
     fclose(fp_sert);
     
 }
 
//排序
void Sort(student* ps)
{ 
   int x;
   int i,j,temp0,temp1;
   
   student *p_temp;
   
   p_temp=(student*)malloc(1*sizeof(student));
  
   if((fp=fopen("input.txt","rb"))==NULL)
   {
       printf("不能打开文件！");
       exit(0);
   }
   
   printf("选择排序项目: ");
   printf("1.学号  2.年龄   3.姓名\n"); 
   scanf("%d", &x);
   getchar();
   
   switch(x)
   {
     case 1: 
              for(i=0;i<ps->size+1;i++)
              { 
                  for(j=1;j<ps->size+1-i;j++)
                  {
                     if(strcmp(ps->a[j-1].num,ps->a[j].num)>0)
                     {
                        *p_temp=ps->a[j];
                        ps->a[j]=ps->a[j-1];
                        ps->a[j-1]=*p_temp;
                     }
                  }
              }
              break;
              
    case 2:

             for(i=0;i<ps->size+1;i++)
             {
                for(j=1;j<ps->size+1-i;j++)
                {
                    temp0=atoi(ps->a[j-1].age);
                    temp1=atoi(ps->a[j].age);
                    
                    if(temp0<temp1)
                    {
                         *p_temp=ps->a[j];
                         ps->a[j]=ps->a[j-1];
                         ps->a[j-1]=*p_temp;
                    }
                }
             }
             
             break;
             
    case 3:
             for(i=0;i<ps->size+1;i++)
             {
                 for(j=1;j<ps->size+1-i;j++)
                 {
                    if(strcmp(ps->a[j-1].name,ps->a[j].name)>0)
                    {
                        *p_temp=ps->a[j];
                        ps->a[j]=ps->a[j-1];
                        ps->a[j-1]=*p_temp;
                    }
                 }
             }
             break;
   }
   
   printf("排序成功\n");
   
   fp_sert=fopen("serted.txt","wb");
   
   for(i=0;i<=ps->size;i++)
   {
       fwrite(&ps->a[ps->size],sizeof(ps->a[0]),1,fp_sert);
   }
   
   fclose(fp);
   fclose(fp_sert);

   free(p_temp);
   
}

// 打印 
void Printf(student* ps)
{	
	
    printf("-姓名       学号        年龄   性别\n");
	for (int i=0;i < ps->size; i++)
    {
    printf("%-11s  %-11s  %-5s %-5s\n",ps->a[i].name,ps->a[i].num,ps->a[i].age,ps->a[i].sex);

    }
}

//查询 
int Query(student* ps)
{
    char ch, * numstr;
    int i;
    numstr=(char *)malloc(20*sizeof(char));
    
    printf("请选择一种查询方式：");
    printf("1.姓名 2.学号 \n");
    ch=getchar();
    getchar();
    
    switch(ch)
    {
     case '1':
              printf(" 输入你所要查找的姓名:");
              gets(numstr);
              for(i=0;i<=ps->size;i++)
              {
                  if(!strcmp(numstr,ps->a[i].name))
                  {
                    	return i;
                  }
              }
              break;
    case '2':
             printf("输入要查找的学号：");
             gets(numstr);
             for(i=0;i<=ps->size;i++)
             {
                if(!strcmp(numstr,ps->a[i].num))
                {
                   return i;
                }
             }
             break;
    }
    
    return -1;
    
 }

//菜单 
void Menu()
{
    printf("\n");
    printf(" _______________________________________ \n");
    printf("|                                       |\n");
    printf("|               1.输入                  |\n");
    printf("|               2.查询                  |\n");
    printf("|               3.排序                  |\n");
    printf("|               4.输出到文件            |\n");
    printf("|               5.年龄平均值            |\n");
    printf("|               6.统计男女人数          |\n");
    printf("|               7.删除学生信息          |\n");
    printf("|               8.打印学生信息          |\n");
    printf("|               9.退出                  |\n");
    printf("|_______________________________________|\n");
    printf("\n请选择菜单:  ");
}

//平均值 
float Averge(student* ps)
{

    float sum=0; 
	float averge=0;
	float temp0;
	
	for(int i=0;i<ps->size;i++)
	{
		temp0=atoi(ps->a[i].age);
		sum+=temp0;
	} 
	
	averge=sum/(ps->size+1);
 	
 	return averge;
}

//计算男女人数 
void Count_sex(student* ps,int* nums_sex)
{

	for(int i=0;i<=ps->size;i++)
	{
		if(!strcmp(ps->a[i].sex,"F"))
		{
			nums_sex[1]++;
		}
		
		
		if(!strcmp(ps->a[i].sex,"M"))
		{
			nums_sex[0]++;
		}
		
	}
}

//删除 
void Delete(student* ps,int* nums_sex)
{
    char ch;
    int flag=0, j;
    char s1[100];
    printf("选择删除的项目: ");
    printf("1.学号  2.姓名\n"); 
   
    ch=getchar();
    getchar();
	
	switch(ch)
	{
	//学号 
	case '1':
   		 printf("请输入要删除学生的学号：\n");
   		 gets(s1);
         
   	   for (int i = 0; i <=ps->size ; i++)
 	   {
 	        if(!strcmp(ps->a[i].num, s1))
       		{
         	  flag = 1;
         	  
         	  if(ps->a[i].sex=="M")
         	  {
         	  	nums_sex[0]--;
			  }
			  
			  else if(ps->a[i].sex=="F")
			  {
			  	nums_sex[1]--;
			  }
			  
        	  for (j = i; j < ps->size - 1; j++)
              {
               ps->a[j] = ps->a[j + 1];  // 从后往前面挪 
              }
       }
        
        if (flag == 1) break;
    }
    
    if (flag == 0) 
	    printf("未找到该学生！\n");
	    
    if (flag == 1)
    {
        printf("删除成功！\n");
        ps->size--; //学生-1 
    }
    break;
	
	//姓名 
	case '2':	
    printf("请输入要删除学生的姓名：\n");
    gets(s1);
    
    for (int i = 0; i <= ps->size;)
    {
        if (!strcmp(ps->a[i].name, s1))
        {
            flag = 1;
            
            for (j = i; j < ps->size - 1; j++)
            {
                ps->a[j] = ps->a[j + 1];  // 从后往前面挪 
            }
        }
        
        if (flag == 1) break;
        i++;
    }
    
    if (flag == 0) 
	    printf("未找到该学生！\n");
	    
    if (flag == 1)
    {
        printf("删除成功！\n");
        ps->size--; //学生-1 
    }
    
    break;
	}
	
} 









