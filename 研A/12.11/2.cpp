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

Node* CreateLinkedlist(int n,void(*ptr)(Node*,FILE*),FILE*);//建立链表函数指针 
void Read_studentFromfile(Node*,FILE*);//读文件并建立链表 
void input_student(Node*);

int CountFile_members(int(*ptr)(FILE*),FILE*);//通用计算文件数量函数指针 
int StuFile_members(FILE*);//读取学生 类型数据数量 

void Traverse(Node* phead);
void Printf_Student(Node*);
void DestroyList(Node*& phead);

int main()
{
	FILE *fp=fopen("student.dat","rb");
	int n=CountFile_members(StuFile_members,fp);
	rewind(fp);
	if(n==0)
	{
		printf("文件为空\n");
	} 
	else
	{
		Node* phead=CreateLinkedlist(n,Read_studentFromfile,fp);
		Traverse(phead);
	} 
	
	fclose(fp);
	


	return 0;	
} 

int CountFile_members(int(*ptr)(FILE*),FILE* fp)
{
	
	return ptr(fp);
}

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

	printf("\n学号:>");scanf("%d",&s->num);
	printf("姓名:>");scanf("%s",&s->name);
	printf("性别:>");scanf("%s",&s->gender);
	printf("年龄:>");scanf("%d",&s->age);

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
	
	printf("\n\n\t学号：%d", tmp->num);
	printf("\t姓名：%s", tmp->name);
	printf("\t性别：%s", tmp->gender);
	printf("\t年龄：%d\n", tmp->age);
	
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














