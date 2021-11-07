#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 100

struct stud_type
{
    char num[20]; //ѧ�� 
    char name[10];//���� 
    char sex[20]; //F �� M
    char age[10]; //���� 

}student[N];


FILE *fp;          /*�����ļ�ָ��*/
FILE *fp_sert;     /*�����ļ�ָ��*/
FILE *fp_output;   /*�����ļ�ָ��*/
static int  n=0;

void Menu();
void Input();  /*������Ϣ*/
void Putout(); /*�����Ϣ*/
void Query();  /*��ѯ��Ϣ*/
void Sort();   /*����*/
void Averge(); /*ƽ��ֵ*/ 
void Count_sex();
void Delete();

int main()
{
    Menu();

    return 0;
}

//�˵� 
void Menu()
{
	char choice_choose;
    printf("\n");
    printf(" _______________________________________ \n");
    printf("|                                       |\n");
    printf("|               1.����                  |\n");
    printf("|               2.��ѯ                  |\n");
    printf("|               3.����                  |\n");
    printf("|               4.���                  |\n");
    printf("|               5.����ƽ��ֵ            |\n");
    printf("|               6.ͳ����Ů����          |\n");
    printf("|               7.ɾ��                  |\n");
    printf("|                                       |\n");
    printf("|               8.�˳�                  |\n");
    printf("|_______________________________________|\n");
    printf("\n��ѡ��˵�:  ");
    
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
              printf("�����������������ѡ��˵���\n");
    }
    
    Menu();
}

//���� 
void Input()
{
    char ch;
    if ((fp = fopen("input.txt", "wb")) == NULL)
    {
        printf("���ܴ��ļ�!");
        exit(0);
    }

    for (n = 0; n < N; n++)
    {
    	
        printf("\n�������%d��ѧ����Ϣ:\n����:", n + 1);
        gets(student[n].name);
        printf("ѧ��:");
        gets(student[n].num);
        printf("����:");
        gets(student[n].age);
        
        printf("�Ա�F & M��: ");
        gets(student[n].sex);

        fwrite(&student[n], sizeof(student[n]), 1, fp); 

        printf("�Ƿ�������� (y/n��)\n");
        ch = getchar();
        getchar();
        if (ch == 'n')
        {
            break;
        }
    }
    
    fclose(fp);
}

//����
void Sort()
{ 
   char ch;
   int i,j,temp0,temp1;
   
   struct stud_type *p_temp;
   
   p_temp=(struct stud_type *)malloc(1*sizeof(struct stud_type));
  
   if((fp=fopen("input.txt","rb"))==NULL)
   {
       printf("���ܴ��ļ���");
       exit(0);
   }
   
   printf("ѡ��������Ŀ: ");
   printf("1.ѧ��  2.����   3.����\n"); 
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
   
   printf("\n��������\n\n");
   printf("-����       ѧ��        ����   �Ա�\n");
   
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
/*���������ļ�*/
     fp=fopen("input.txt","rb");
     printf("input�����ļ���\n");
     
     for(i=0;i<n+1;i++)
     {  
         fread(&student[i],sizeof(student[0]),1,fp);
         printf("%-15s%-11s%-3s%-3s\n",student[i].name,student[i].num,student[i].age,student[i].sex);
     }
     printf("\n\n");
     
 /*�����ѯ���ļ�*/
     fp_output=fopen("query.txt","rb");
     printf("\nquery��ѯ�ļ�:\n");
     while(!feof(fp_output))
     {
        printf("%c",fgetc(fp_output));
     }
     printf("\n\n");

 /*�����������ļ�*/
     fp_sert=fopen("serted.txt","rb");
     printf("\nserted�����ļ�:\n");
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
        printf("���ļ�ʧ��!\n ");
        exit(0);
    }
    printf("��ѡ��һ�ֲ�ѯ��ʽ��");
    printf("1.���� 2.ѧ�� \n");
    ch=getchar();
    getchar();
    
    switch(ch)
    {
     case '1':
              printf(" ��������Ҫ���ҵ�����:");
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
             printf("����Ҫ���ҵ�ѧ�ţ�");
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
    fwrite(&student[i],sizeof(student[n]),1,fp_output);/*�´β�ѯ���Ḳ��ԭ����*/
    
    printf("���ҽ�����£�\n \n");
    printf("-����         ѧ��           ���� �Ա�\n");
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

	printf("ѧ������ƽ��ֵ:%d\n",ave);
 	
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
	
	printf("������%d��\nŮ����%d��\n",m,f);
	
}


//ɾ�� 
void Delete()
{
    char ch;
    int flag=0, j;
    char s1[100];
    printf("ѡ��ɾ������Ŀ: ");
    printf("1.ѧ��  2.����\n"); 
   
    ch=getchar();
    getchar();
	
	switch(ch)
	{
	case '1':
   		 printf("������Ҫɾ��ѧ����ѧ�ţ�\n");
   		 gets(s1);
         
   		for (int i = 0; i <= n; i++)
 	   {
 	        if(!strcmp(student[i].num, s1))
       		{
         	  flag = 1;
        	  for (j = i; j < n - 1; j++)
              {
               student[j] = student[j + 1];  // �Ӻ���ǰ��Ų 
              }
       }
        
        if (flag == 1) break;
    }
    
    if (flag == 0) 
	    printf("δ�ҵ���ѧ����\n");
	    
    if (flag == 1)
    {
        printf("ɾ���ɹ���\n");
        n--; //ѧ��-1 
    }
    break;
	
	case '2':	
    printf("������Ҫɾ��ѧ����������\n");
    gets(s1);
    
    for (int i = 0; i <= n; i++)
    {
        if (!strcmp(student[i].name, s1))
        {
            flag = 1;
            
            for (j = i; j < n - 1; j++)
            {
                student[j] = student[j + 1];  // �Ӻ���ǰ��Ų 
            }
        }
        
        if (flag == 1) break;
    }
    
    if (flag == 0) 
	    printf("δ�ҵ���ѧ����\n");
	    
    if (flag == 1)
    {
        printf("ɾ���ɹ���\n");
        n--; //ѧ��-1 
    }
    
    break;
	}
	
} 

 
 
 

