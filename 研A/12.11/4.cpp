#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100

struct Student {
	int sno;
	char sname[20];
	char gender[5];
	int age;
};

void input_stu(Student*, int);
void show_stu(Student*, int);

int compare_sno(const void*,const void*); 
int compare_sname(const void*,const void*); 
int compare_age(const void*,const void*); 


int main() 
{
	Student s[N];
	int num = 0;
	int op;

	while (1) {
		system("cls");
		printf( "\n\t\t----------------------");
		printf( "\n\t\t 1.����ѧ��");
		printf( "\n\t\t 2.����������");
		printf( "\n\t\t 3.��ѧ������");
		printf( "\n\t\t 4.����������");
		printf( "\n\t\t 0.�˳�");
		printf( "\n\t\t----------------------");
		printf( "\n\t\tselect(0~4)��");

		scanf("%d", &op);

		switch (option) {
		case 1:
			printf("��Ҫ����ѧ������:") ;
			scanf("%d",&num);
			input_stu(s,num); 
			
			break;
		case 2:
			printf( "����ǰ��");
			show_stu(s, num);
			qsort(s, num, sizeof(Student), compare_age);
			printf( "\n�����");
			show_stu(s, num);

			break;
		case 3:
			printf( "����ǰ��");
			show_stu(s, num);
			qsort(s, num, sizeof(Student), compare_sno);
			printf( "\n�����");
			show_stu(s, num);
			break;
		case 4:
			printf( "����ǰ��");
			show_stu(s, num);
			qsort(s, num, sizeof(Student), compare_sname);
			printf("\n�����");
			show_stu(s, num);
			break;
		case 0:
			return 0;
		}
		system("pause"); 
	}

	return 0;
}

void input_stu(Student *s, int n)
{
for(int i=0;i<n;i++)
{

	printf("ѧ�ţ�");
	scanf("%d", &s[i].sno);
	printf("������");
	scanf("%s", s[i].sname);
	printf("�Ա�");
	scanf("%s", s[i].gender);
	printf("���䣺");
	scanf("%d", &s[i].age);
}
}

void show_stu(Student *s, int n)
{
	for (int i = 0; i < n; i++) 
	{
		printf("\nѧ�ţ�%d", s[i].sno);
		printf("\t������%s", s[i].sname);
		printf("\t�Ա�%s", s[i].gender);
		printf("\t���䣺%d", s[i].age);
	}

}


int compare_sno(const void* p1,const void* p2)
{  
	const Student* q1=(const Student*)p1;
	const Student* q2=(const Student*)p2; 
    
	if(q1->sno < q2->sno) return -1;
	else if(q1->sno == q2->sno) return 0;
	else return 1; 
}
int compare_sname(const void* p1,const void* p2)
{  
	const Student* q1=(const Student*)p1;
	const Student* q2=(const Student*)p2;
    
	if(strcmp(q1->sname, q2->sname)<0) return -1;
	else if(strcmp(q1->sname, q2->sname)==0) return 0;
	else return 1; 
}
int compare_age(const void* p1,const void* p2)
{  
	const Student* q1=(const Student*)p1;
	const Student* q2=(const Student*)p2;
    
	if(q1->age  < q2->age) return -1;
	else if(q1->age == q2->age) return 0;
	else return 1; 
}


