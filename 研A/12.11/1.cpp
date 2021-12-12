#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void Write_studentFromstdin(Node*,FILE*);
Node* CreateLinkedlist(int n,void(*ptr)(Node*,FILE*),FILE*);

void input_student(Node*);
void Traverse(Node* phead);
void Printf_Student(Node*);
void DestroyList(Node*& phead);

int main()
{
	FILE* fp=NULL;
	fp=fopen("student.dat","ab+");
	int m=0;
	printf("\n请输出要输入数据的个数:>");
	scanf("%d",&m);
	Node* new_stuphead=CreateLinkedlist(m,Write_studentFromstdin,fp);
	Traverse(new_stuphead);
	fclose(fp); 

	return 0;	
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

