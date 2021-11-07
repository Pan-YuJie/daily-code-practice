#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

struct stud_type
{
    char num[20]; //学号 
    char name[10];//姓名 
    char sex[20]; //F 、 M
    char age[10]; //年龄 

}student[N];


FILE *fp;          /*输入文件指针*/
FILE *fp_sert;     /*排序文件指针*/
FILE *fp_output;   /*查找文件指针*/
static int  n=0;

void Menu();
void Input();  /*输入信息*/
void Putout(); /*输出信息*/
void Query();  /*查询信息*/
void Sort();   /*排序*/
void Averge(); /*平均值*/ 
void Count_sex();
void Delete();

int main()
{
    Menu();

    return 0;
}

//菜单 
void Menu()
{
	char choice_choose;
    printf("\n");
    printf(" _______________________________________ \n");
    printf("|                                       |\n");
    printf("|               1.输入                  |\n");
    printf("|               2.查询                  |\n");
    printf("|               3.排序                  |\n");
    printf("|               4.输出                  |\n");
    printf("|               5.年龄平均值            |\n");
    printf("|               6.统计男女人数          |\n");
    printf("|               7.删除                  |\n");
    printf("|                                       |\n");
    printf("|               8.退出                  |\n");
    printf("|_______________________________________|\n");
    printf("\n请选择菜单:  ");
    
    choice_choose=getchar();
    getchar();
    
    switch(choice_choose)
    {
      case'1':Input(); break;
      
      case'2':Query(); break;
      
      case'3':Sort(); break;
      
      case'4':Putout(); break;
      
      case'5':Averge(); break;
      
      case'6':Count_sex(); break;
      
      case'7':Delete(); break;
      
      case'8':exit(0);
      
      default:
              printf("你的输入有误，请重新选择菜单。\n");
    }
    
    Menu();
}

//插入 
void Input()
{
    char ch;
    if ((fp = fopen("input.txt", "wb")) == NULL)
    {
        printf("不能打开文件!");
        exit(0);
    }

    for (n = 0; n < N; n++)
    {
    	
        printf("\n请输入第%d个学生信息:\n姓名:", n + 1);
        gets(student[n].name);
        printf("学号:");
        gets(student[n].num);
        printf("年龄:");
        gets(student[n].age);
        
        printf("性别（F & M）: ");
        gets(student[n].sex);

        fwrite(&student[n], sizeof(student[n]), 1, fp); 

        printf("是否继续输入 (y/n？)\n");
        ch = getchar();
        getchar();
        if (ch == 'n')
        {
            break;
        }
    }
    
    fclose(fp);
}

//排序
void Sort()
{ 
   char ch;
   int i,j,temp0,temp1;
   
   struct stud_type *p_temp;
   
   p_temp=(struct stud_type *)malloc(1*sizeof(struct stud_type));
  
   if((fp=fopen("input.txt","rb"))==NULL)
   {
       printf("不能打开文件！");
       exit(0);
   }
   
   printf("选择排序项目: ");
   printf("1.学号  2.年龄   3.姓名\n"); 
   ch=getchar();
   getchar();
   
   switch(ch)
   {
     case '1': 
              for(i=0;i<n+1;i++)
              { 
                  for(j=1;j<n+1-i;j++)
                  {
                     if(strcmp(student[j-1].num,student[j].num)>0)
                     {
                        *p_temp=student[j];
                        student[j]=student[j-1];
                        student[j-1]=*p_temp;
                     }
                  }
              }
              break;
              
    case '2':

             for(i=0;i<n+1;i++)
             {
                for(j=1;j<n+1-i;j++)
                {
                    temp0=atoi(student[j-1].age);
                    temp1=atoi(student[j].age);
                    
                    if(temp0<temp1)
                    {
                         *p_temp=student[j];
                         student[j]=student[j-1];
                         student[j-1]=*p_temp;
                    }
                }
             }
             
             break;
             
    case '3':
             for(i=0;i<n+1;i++)
             {
                 for(j=1;j<n+1-i;j++)
                 {
                    if(strcmp(student[j-1].name,student[j].name)>0)
                    {
                        *p_temp=student[j];
                        student[j]=student[j-1];
                        student[j-1]=*p_temp;
                    }
                 }
             }
             break;
   }
   
   printf("\n排序结果：\n\n");
   printf("-姓名       学号        年龄   性别\n");
   
   fp_sert=fopen("serted.txt","wb");
   
   for(i=0;i<=n;i++)
   {
       printf("%-11s  %-11s  %-5s %-5s\n",student[i].name,student[i].num,student[i].age,student[i].sex);
       fwrite(&student[i],sizeof(student[0]),1,fp_sert);
   }
   
   fclose(fp);
   fclose(fp_sert);
   free(p_temp);
}

void Putout()
{  
     int i;
/*输出输入的文件*/
     fp=fopen("input.txt","rb");
     printf("input输入文件：\n");
     
     for(i=0;i<n+1;i++)
     {  
         fread(&student[i],sizeof(student[0]),1,fp);
         printf("%-15s%-11s%-3s%-3s\n",student[i].name,student[i].num,student[i].age,student[i].sex);
     }
     printf("\n\n");
     
 /*输出查询的文件*/
     fp_output=fopen("query.txt","rb");
     printf("\nquery查询文件:\n");
     while(!feof(fp_output))
     {
        printf("%c",fgetc(fp_output));
     }
     printf("\n\n");

 /*输出已排序的文件*/
     fp_sert=fopen("serted.txt","rb");
     printf("\nserted排序文件:\n");
     for(i=0;i<n+1;i++)
     {
         fread(&student[i],sizeof(student[0]),1,fp_sert);
         printf("\n%-15s%-11s%-3s%-3s\n",student[i].name,student[i].num,student[i].age,student[i].sex);
     }
      printf("\n\n");
  
     fclose(fp);
     fclose(fp_sert);
     fclose(fp_output);
     
 }
 
 void Query()
 {
    char ch, * numstr;
    int i;
    numstr=(char *)malloc(20*sizeof(char));
    
    if((fp=fopen("input.txt","rb"))==NULL)
    {
        printf("打开文件失败!\n ");
        exit(0);
    }
    printf("请选择一种查询方式：");
    printf("1.姓名 2.学号 \n");
    ch=getchar();
    getchar();
    
    switch(ch)
    {
     case '1':
              printf(" 输入你所要查找的姓名:");
              gets(numstr);
              for(i=0;i<=n;i++)
              {
                  if(!strcmp(numstr,student[i].name))
                  {
                      break;
                     
                  }
              }
              break;
    case '2':
             printf("输入要查找的学号：");
             gets(numstr);
             for(i=0;i<=n;i++)
             {
                if(!strcmp(numstr,student[i].num))
                {
                     break;
                    
                }
             }
             break;
    }
    
    fp_output=fopen("Query.txt","wb");
    fwrite(&student[i],sizeof(student[n]),1,fp_output);/*下次查询，会覆盖原数据*/
    
    printf("查找结果如下：\n \n");
    printf("-姓名         学号           年龄 性别\n");
    printf("%-15s%-15s%-5s%-5s\n",student[i].name,student[i].num,student[i].age,student[i].sex);
    
    fclose(fp_output);
    fclose(fp);
    
 }
 
void Averge()
{

    int sum=0; 
	int ave=0;
	int temp0;
	for(int i=0;i<=n;i++)
	{
		temp0=atoi(student[i].age);
		sum+=temp0;
		
	} 
	
	ave=sum/(n+1);

	printf("学生年龄平均值:%d\n",ave);
 	
}

void Count_sex()
{
	int f=0;
	int m=0;
	
	for(int i=0;i<=n;i++)
	{
		if(!strcmp(student[i].sex,"F"))
		{
			f++;
		}
		
		
		if(!strcmp(student[i].sex,"M"))
		{
			m++;
		}
		
	}
	
	printf("男生有%d人\n女生有%d人\n",m,f);
	
}


//删除 
void Delete()
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
	case '1':
   		 printf("请输入要删除学生的学号：\n");
   		 gets(s1);
         
   		for (int i = 0; i <= n; i++)
 	   {
 	        if(!strcmp(student[i].num, s1))
       		{
         	  flag = 1;
        	  for (j = i; j < n - 1; j++)
              {
               student[j] = student[j + 1];  // 从后往前面挪 
              }
       }
        
        if (flag == 1) break;
    }
    
    if (flag == 0) 
	    printf("未找到该学生！\n");
	    
    if (flag == 1)
    {
        printf("删除成功！\n");
        n--; //学生-1 
    }
    break;
	
	case '2':	
    printf("请输入要删除学生的姓名：\n");
    gets(s1);
    
    for (int i = 0; i <= n; i++)
    {
        if (!strcmp(student[i].name, s1))
        {
            flag = 1;
            
            for (j = i; j < n - 1; j++)
            {
                student[j] = student[j + 1];  // 从后往前面挪 
            }
        }
        
        if (flag == 1) break;
    }
    
    if (flag == 0) 
	    printf("未找到该学生！\n");
	    
    if (flag == 1)
    {
        printf("删除成功！\n");
        n--; //学生-1 
    }
    
    break;
	}
	
} 

 
 
 

