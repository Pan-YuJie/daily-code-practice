#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

struct Student
{
	int num;  
	char name[20];
	char gender[3];
	int age;
};
 
struct Node 
{
	void* data;
	Node* next;
};

Node* CreateLinkedlist(int n,void(*ptr)(Node*,FILE*),FILE*);//����������ָ�� 
void Write_studentFromstdin(Node*,FILE*);//�������뵽�ļ������������� 
void Read_studentFromfile(Node*,FILE*);//���ļ����������� 
void input_student(Node*);

int CountFile_members(int(*ptr)(FILE*),FILE*);//ͨ�ü����ļ���������ָ�� 
int StuFile_members(FILE*);//��ȡѧ�� ������������ 

void Traverse(Node* phead);
void Printf_Student(Node*);
void DestroyList(Node*& phead);

int main()
{
	FILE* fp=NULL;
	int option=1;
	while(1)
	{
		system("cls");
		printf("\n\t**********��������ͨ�ó���**********\n\n");
		printf("\n\t\t    (1) ��������\n");
		printf("\n\t\t    (2) ���̶�ȡ\n");
		printf("\n\t\t    (0) �˳�\n");
		printf("\n\t************************************\n\n");
		scanf("%d",&option);
		switch (option)
		{
			case 1:
			{
					int m=0;
					printf("\n�����Ҫ�������ݵĸ���:>");
					scanf("%d",&m);
					fp=fopen("student.dat","ab+");
					Node* new_stuphead=CreateLinkedlist(m,Write_studentFromstdin,fp);
					Traverse(new_stuphead);
					fclose(fp); 
				break;
			}
			case 2:
			{
					FILE *fp=fopen("student.dat","rb");
					int n=CountFile_members(StuFile_members,fp);
					rewind(fp);
					if(n==0)
					{
						printf("�ļ�Ϊ��\n");
					} 
					else
					{
						Node* phead=CreateLinkedlist(n,Read_studentFromfile,fp);
						Traverse(phead);
					} 
					
					fclose(fp);
				break;
			}
			
			case 0:
				return 0;
				 
			default:
				printf("\n�����������������\n");
				
		} 
		system("pause");
	}
	
	return 0;
	
}

int CountFile_members(int(*ptr)(FILE*),FILE* fp)
{
	
	return ptr(fp);
}


//����һ�� 
/*int StuFile_members(FILE* fp)
{
	int n=0;
	Student data;
	while (fread(&data, sizeof(Student), 1, fp))
	{
		if (feof(fp))
		{
			break;
		}
		
		n++;
	}
	return n;
}
*/ 

//������
int StuFile_members(FILE* fp)
{
	fseek(fp,0,SEEK_END);
	
	return ftell(fp)/sizeof(Student);
}


void Read_studentFromfile(Node* pnew,FILE* fp)
{
	pnew->data=(Student*)malloc(sizeof(Student));
	fread(pnew->data,sizeof(Student),1,fp);
}

void Write_studentFromstdin(Node* pnew,FILE* fp)
{
	Student *s=(Student *)malloc(sizeof(Student));
	pnew->data=s;

	input_student(pnew);
	
	fwrite(pnew->data,sizeof(Student),1,fp);
	
} 


Node* CreateLinkedlist(int n,void(*ptr)(Node*,FILE*),FILE* fp)
{   
    Node* phead=NULL; 
    Node* pnew=NULL;
    
    for(int i=0; i<n;i++)
	{
    	pnew=(Node *)malloc(sizeof(Node));
	
		ptr(pnew,fp);
		pnew->next=phead;
		phead=pnew;
    }

	return phead;
}

void input_student(Node* p)
{

	Student *s=(Student *)malloc(sizeof(Student));
	p->data=s;

	printf("\nѧ��:>");scanf("%d",&s->num);
	printf("����:>");scanf("%s",&s->name);
	printf("�Ա�:>");scanf("%s",&s->gender);
	printf("����:>");scanf("%d",&s->age);

}
 
void Traverse(Node* phead)
{
	Node* p=phead; 
	while(p)
	{   		
       Printf_Student(p);
	   p = p->next;
	}

}

void Printf_Student(Node* p)
{

	Node* cur = p;
	Student* tmp = NULL;
	tmp = (Student*)cur->data;
	
	printf("\n\n\tѧ�ţ�%d", tmp->num);
	printf("\t������%s", tmp->name);
	printf("\t�Ա�%s", tmp->gender);
	printf("\t���䣺%d\n", tmp->age);
	
}

void DestroyList(Node*& phead)
{
	if (phead == NULL)
		return;

	Node* p = phead;

	while (p)
	{
		Node* next = p->next;
		free(p->data);
		free(p);
		p = next;
	}

	phead = NULL;
}


