#include "panyujie.h"

FILE *fp;          /*�����ļ�ָ��*/
FILE *fp_sert;     /*�����ļ�ָ��*/
FILE *fp_output;   /*�����ļ�ָ��*/



//��ʼ�� 
void Init(student* ps)
{
	ps->a=NULL;
	ps->cacpcity=0;
	ps->size=0;
} 

//������� 
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


//���� 
void Input(student* ps)
{	
	
	if ((fp = fopen("input.txt", "wb")) == NULL)
    {
       	printf("���ܴ��ļ�!");
      	exit(0);
   	}
   	
    CheckCacpcity(ps);
    	
    printf("\n�������%d��ѧ����Ϣ:\n����:", ps->size + 1);
    gets(ps->a[ps->size].name);
    
    printf("ѧ��:");
    gets(ps->a[ps->size].num);
    
    printf("����:");
    gets(ps->a[ps->size].age);
        
    printf("�Ա�F & M��: ");
    gets(ps->a[ps->size].sex);
    
    
    fwrite(&ps->a[ps->size], sizeof(ps->a[ps->size]), 1, fp); 
    
    ps->size++; 
    
	fclose(fp);
}

void Putout(student* ps)
{  
     int i;
     
     /*���������ļ�*/
     fp=fopen("input.txt","rb");
     printf("input�����ļ���\n");
     
     for(i=0;i<ps->size;i++)
     {  
         fread(&ps->a[i],sizeof(ps->a[0]),1,fp);
         printf("%-15s%-11s%-3s%-3s\n",ps->a[i].name,ps->a[i].num,ps->a[i].age,ps->a[i].sex);
     }
     printf("\n\n");
     

    /*�����������ļ�*/
     fp_sert=fopen("serted.txt","rb");
     printf("\nserted�����ļ�:\n");
     for(i=0;i<ps->size;i++)
     {
         fread(&ps->a[i],sizeof(ps->a[0]),1,fp);
         printf("%-15s%-11s%-3s%-3s\n",ps->a[i].name,ps->a[i].num,ps->a[i].age,ps->a[i].sex);
     }
     
      printf("\n\n");
  
     fclose(fp);
     fclose(fp_sert);
     
 }
 
//����
void Sort(student* ps)
{ 
   int x;
   int i,j,temp0,temp1;
   
   student *p_temp;
   
   p_temp=(student*)malloc(1*sizeof(student));
  
   if((fp=fopen("input.txt","rb"))==NULL)
   {
       printf("���ܴ��ļ���");
       exit(0);
   }
   
   printf("ѡ��������Ŀ: ");
   printf("1.ѧ��  2.����   3.����\n"); 
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
   
   printf("����ɹ�\n");
   
   fp_sert=fopen("serted.txt","wb");
   
   for(i=0;i<=ps->size;i++)
   {
       fwrite(&ps->a[ps->size],sizeof(ps->a[0]),1,fp_sert);
   }
   
   fclose(fp);
   fclose(fp_sert);

   free(p_temp);
   
}

// ��ӡ 
void Printf(student* ps)
{	
	
    printf("-����       ѧ��        ����   �Ա�\n");
	for (int i=0;i < ps->size; i++)
    {
    printf("%-11s  %-11s  %-5s %-5s\n",ps->a[i].name,ps->a[i].num,ps->a[i].age,ps->a[i].sex);

    }
}

//��ѯ 
int Query(student* ps)
{
    char ch, * numstr;
    int i;
    numstr=(char *)malloc(20*sizeof(char));
    
    printf("��ѡ��һ�ֲ�ѯ��ʽ��");
    printf("1.���� 2.ѧ�� \n");
    ch=getchar();
    getchar();
    
    switch(ch)
    {
     case '1':
              printf(" ��������Ҫ���ҵ�����:");
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
             printf("����Ҫ���ҵ�ѧ�ţ�");
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

//�˵� 
void Menu()
{
    printf("\n");
    printf(" _______________________________________ \n");
    printf("|                                       |\n");
    printf("|               1.����                  |\n");
    printf("|               2.��ѯ                  |\n");
    printf("|               3.����                  |\n");
    printf("|               4.������ļ�            |\n");
    printf("|               5.����ƽ��ֵ            |\n");
    printf("|               6.ͳ����Ů����          |\n");
    printf("|               7.ɾ��ѧ����Ϣ          |\n");
    printf("|               8.��ӡѧ����Ϣ          |\n");
    printf("|               9.�˳�                  |\n");
    printf("|_______________________________________|\n");
    printf("\n��ѡ��˵�:  ");
}

//ƽ��ֵ 
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

//������Ů���� 
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

//ɾ�� 
void Delete(student* ps,int* nums_sex)
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
	//ѧ�� 
	case '1':
   		 printf("������Ҫɾ��ѧ����ѧ�ţ�\n");
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
               ps->a[j] = ps->a[j + 1];  // �Ӻ���ǰ��Ų 
              }
       }
        
        if (flag == 1) break;
    }
    
    if (flag == 0) 
	    printf("δ�ҵ���ѧ����\n");
	    
    if (flag == 1)
    {
        printf("ɾ���ɹ���\n");
        ps->size--; //ѧ��-1 
    }
    break;
	
	//���� 
	case '2':	
    printf("������Ҫɾ��ѧ����������\n");
    gets(s1);
    
    for (int i = 0; i <= ps->size;)
    {
        if (!strcmp(ps->a[i].name, s1))
        {
            flag = 1;
            
            for (j = i; j < ps->size - 1; j++)
            {
                ps->a[j] = ps->a[j + 1];  // �Ӻ���ǰ��Ų 
            }
        }
        
        if (flag == 1) break;
        i++;
    }
    
    if (flag == 0) 
	    printf("δ�ҵ���ѧ����\n");
	    
    if (flag == 1)
    {
        printf("ɾ���ɹ���\n");
        ps->size--; //ѧ��-1 
    }
    
    break;
	}
	
} 


