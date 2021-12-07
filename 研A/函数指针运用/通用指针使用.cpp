#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<assert.h>

struct Student  //学生 
{
	int num;
	char name[10];
	char gender[5];
	int age;
};

struct Course   //课程 
{
	int num;    //课程号
	char cname[10];  //课程名
	int credit;    //学分
};

struct Node
{
	void* data;
	Node* next;
};

Node* createLinkedlist_Student(int n);  //建立学生链表
Node* createLinkedlist_Course(int n);  //建立课程链表
Node* CreateLinkedlist(Node* (*ptr)(int), int);//建立链表函数指针 

void input_student(Node* pnew);
void input_course(Node* pnew);
void Input(void(*ptr)(Node*), Node*);// 输入函数指针

void Printf_Course(Node*);
void Printf_Student(Node*);
void Printflist(void(*ptr)(Node*), Node* phead);//打印函数指针

void DestroyList(Node*&);


int main()//测试
{

	int n;
	printf("输入学生数量\n");
	scanf("%d", &n);

	printf("输入学生\n");
	//Node* phead_Stu = createLinkedlist_Student(n);
	Node* phead_Stu = CreateLinkedlist(createLinkedlist_Student, n);

	Input(input_student, phead_Stu);

	//Node* cur = phead_Stu;
	//while (cur)
	//{
	//	input(input_student, phead_Stu);
	//	cur = cur->next;
	//}
	//Printf_Student(phead_Stu);

	Printflist(Printf_Student, phead_Stu);

	printf("输入课程数量\n");
	scanf("%d", &n);
	//Node* phead_Cour = createLinkedlist_Course(n);
	Node* phead_Cour = CreateLinkedlist(createLinkedlist_Course, n);

	Input(input_course, phead_Cour);
	Printflist(Printf_Course, phead_Cour);

	DestroyList(phead_Cour);
	DestroyList(phead_Stu);


	Printflist(Printf_Student, phead_Stu);
	Printflist(Printf_Course, phead_Cour);


	return 0;
}

Node* CreateLinkedlist(Node* (*ptr)(int), int n)
{
	return ptr(n);
}

void Destroy(void(*ptr)(Node*&), Node*& phead)
{

	ptr(phead);

}

void Input(void(*ptr)(Node*), Node* phead)
{
	Node* cur = phead;

	while (cur)
	{
		ptr(cur);
		cur = cur->next;
	}

}

void Printflist(void(*ptr)(Node*), Node* phead)
{
	if (phead == NULL)
	{
		return;
	}

	Node* cur = phead;
	ptr(cur);
}

Node* createLinkedlist_Student(int n)  //建立学生链表
{
	if (n == 0)
		return NULL;

	Node* phead = NULL;
	Node* tail = NULL;

	for (int i = 0; i < n; i++)
	{
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->next = NULL;

		if (phead == NULL)
		{
			phead = newnode;
		}

		else
		{
			tail->next = newnode;
		}

		tail = newnode;
	}

	return phead;

}

Node* createLinkedlist_Course(int n) //建立课程链表
{
	if (n == 0)
		return NULL;

	Node* phead = NULL;
	Node* tail = NULL;

	for (int i = 0; i < n; i++)
	{
		Node* pnew = (Node*)malloc(sizeof(Node));
		pnew->next = NULL;

		if (phead == NULL)
		{
			phead = pnew;
		}

		else
		{
			tail->next = pnew;
		}

		tail = pnew;

	}

	return phead;

}



void input_student(Node* pnew)
{
	Student* tmp = (Student*)malloc(sizeof(Student));
	scanf("%d", &tmp->num);
	scanf("%s", &tmp->name);
	scanf("%s", &tmp->gender);
	scanf("%d", &tmp->age);

	pnew->data = tmp;
}

void input_course(Node* pnew)
{

	Course* tmp = (Course*)malloc(sizeof(Student));
	scanf("%d", &tmp->num);
	scanf("%s", &tmp->cname);
	scanf("%d", &tmp->credit);

	pnew->data = tmp;

}

void Printf_Student(Node* phead)
{
	assert(phead);
	Node* cur = phead;
	Student* tmp = NULL;

	while (cur)
	{
		tmp = (Student*)cur->data;
		printf("\t学号：%d", tmp->num);
		printf("\t姓名：%s", tmp->name);
		printf("\t性别：%s", tmp->gender);
		printf("\t年龄：%d\n", tmp->age);
		cur = cur->next;
	}
}

void Printf_Course(Node* phead)
{
	assert(phead);
	Node* cur = phead;
	Course* tmp = NULL;

	while (cur)
	{
		tmp = (Course*)cur->data;
		printf("\t课程号：%d", tmp->num);
		printf("\t课程名：%s", tmp->cname);
		printf("\t学分：%d\n", tmp->credit);
		cur = cur->next;

	}

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



