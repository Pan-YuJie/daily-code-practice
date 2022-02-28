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

Node* CreateLinkedlist(Node*, int n, void(*ptr)(Node*, FILE*), FILE*);//��������ͨ�ú���ָ�� 
void Write_studentFromstdin(Node*, FILE*);//�������뵽�ļ����������� 
void Read_studentFromfile(Node*, FILE*);//���ļ�����������
void Read_studentFromlist(Node*,FILE*);//����д���ļ� 
void input_student(Node*);

int CountFile_members(int(*ptr)(FILE*), FILE*);//ͨ�ü����ļ���������ָ��
int StuFile_members(FILE*);//����ѧ�������������� 

void Swap_StuNode(Node*, Node*);//������������

void SortList(void(*ptr)(Node*,Node*),Node*);//����������ͨ��ָ��
void Quicksort_Stunum(Node*, Node*);//��ѧ������
void Quicksort_Stuname(Node*, Node*);//����������
void Quicksort_Stuage(Node*, Node*);//����������

int DeleteList(int(*ptr)(Node*,int),Node* phead,int sno); //ɾ��ѧ�� 
int DeletestuBysno(Node*,int);

void Traverse(void(*ptr)(Node*), Node*);
void Printf_Student(Node*);
void DestroyList(Node*& phead);

int main()
{
	FILE* fp;
	int option = 1;
	Node* phead = NULL;

	//��ȡ�����ļ�
	fp = fopen("student.dat", "rb");
	int n = CountFile_members(StuFile_members, fp);
	rewind(fp);
	phead = CreateLinkedlist(phead, n, Read_studentFromfile, fp);
	Traverse(Printf_Student, phead);
	system("pause");
	fclose(fp);

	while (1)
	{

		system("cls");
		printf("\n\t**********��ӭ����ѧ������ϵͳ**********\n\n");
		printf("\n\t\t    (1) ѧ���������\n");
		printf("\n\t\t    (2) ����ѧ������\n");
		printf("\n\t\t    (3) �������\n");
		printf("\n\t\t    (4) ����\n");//ѧ�ţ�����������
		printf("\n\t\t    (5) ɾ��ѧ����Ϣ\n");
		printf("\n\t\t    (0) �˳�\n");
		printf("\n\t*****************************************\n\n");
		printf("������ָ�0~5��:");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
		{
			int m = 0;
			printf("\n�����Ҫ�������ݵĸ���:>");
			scanf("%d", &m);
			fp = fopen("student.dat", "ab+");
			phead = CreateLinkedlist(phead, m, Write_studentFromstdin, fp);
			fclose(fp);
			break;
		}
		case 2:
		{
			fp = fopen("student.dat", "rb");
			int cnt = CountFile_members(StuFile_members, fp);
			rewind(fp);
			printf("%d\n", cnt);
			fclose(fp);
			break;
		}

		case 3:
		{
			Traverse(Printf_Student, phead);
			break;
		}

		case 4:
		{
			fp = fopen("student.dat", "rb");
			n = CountFile_members(StuFile_members, fp);
			rewind(fp);

			printf("\n\t\t (1)��ѧ������   (2)����������   (3)����������\n");
			printf("��ѡ��:>");

			int op = 0;
			scanf("%d", &op);
			if (op == 1)
			{
				SortList(Quicksort_Stunum, phead);
			}

			else if (op == 2)
			{
				SortList(Quicksort_Stuname, phead);
			}
			
			else if (op == 3)
			{
				SortList(Quicksort_Stuage, phead);
			}

			Traverse(Printf_Student, phead);
			
			fclose(fp);
			break;
		}
		
		case 5:{
			
			int tmp_sno=0;
			printf("��������Ҫɾ��ѧ����ѧ��:> ");
			scanf("%d",&tmp_sno);

			int flag = DeleteList(DeletestuBysno,phead,tmp_sno);  
			
			if(flag==0){
				printf("ɾ��ʧ��(������)\n");
			}else{
				printf("ɾ���ɹ�\n");
				fp = fopen("student.dat", "w");
				Read_studentFromlist(phead,fp);
			
				n = CountFile_members(StuFile_members, fp);
				rewind(fp);
			
				fp = fopen("student.dat", "rb");
				phead=NULL;
				phead = CreateLinkedlist(phead, n, Read_studentFromfile, fp);
				Traverse(Printf_Student, phead);
			}
			
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

int CountFile_members(int(*ptr)(FILE*), FILE* fp)
{
	return ptr(fp);
}

int DeleteList(int(*ptr)(Node*,int),Node* phead ,int sno){
	return ptr(phead,sno);
}


int StuFile_members(FILE* fp)
{
	fseek(fp, 0, SEEK_END);

	return ftell(fp) / sizeof(Student);
}



void Read_studentFromfile(Node* pnew, FILE* fp)
{
	pnew->data = (Student*)malloc(sizeof(Student));
	fread(pnew->data, sizeof(Student), 1, fp);
}

void Write_studentFromstdin(Node* pnew, FILE* fp)
{
	Student* s = (Student*)malloc(sizeof(Student));
	pnew->data = s;
	
	input_student(pnew);

	fwrite(pnew->data, sizeof(Student), 1, fp);

}

void Read_studentFromlist(Node* phead,FILE* fp){
	Node* cur=phead;
	while(cur!=NULL){
		fwrite(cur->data,sizeof(Student),1,fp);
		cur = cur->next;
	}
}


Node* CreateLinkedlist(Node* phead, int n, void(*ptr)(Node*, FILE*), FILE* fp)
{
	Node* pnew = NULL;

	for (int i = 0; i < n; i++)
	{
		pnew = (Node*)malloc(sizeof(Node));

		ptr(pnew, fp);
		pnew->next = phead;
		phead = pnew;
	}

	return phead;
}

void input_student(Node* p)
{

	Student* s = (Student*)malloc(sizeof(Student));
	p->data = s;

	printf("\nѧ��:>"); scanf("%d", &s->num);
	printf("����:>"); scanf("%s", &s->name);
	printf("�Ա�:>"); scanf("%s", &s->gender);
	printf("����:>"); scanf("%d", &s->age);

}

void Traverse(void(*ptr)(Node*), Node* phead)
{
	if(phead==NULL) return;
	Node* p = phead;
	while (p)
	{
		ptr(p);
		p = p->next;
	}
}


void Printf_Student(Node* p)
{

	Node* cur = p;
	Student* tmp = NULL;
	tmp = (Student*)cur->data;

	printf("\n   ѧ�ţ�%d", tmp->num);
	printf("   ������%s", tmp->name);
	printf("   �Ա�%s", tmp->gender);
	printf("   ���䣺%d\n", tmp->age);

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

int DeletestuBysno(Node* phead,int findSno)
{
	if(phead==NULL) return 0;
	
	Node* tail=phead;
	Node* prev=phead;
	
	while(tail){
		if( ((Student*) tail->data)->num ==findSno){
			if(phead==tail){
				Node* tmp=phead;
				phead=phead->next;
				free(tmp->data);
				free(tmp);
				return 1;
			}else{
				prev->next=tail->next;
				free(tail->data);
				free(tail);
				return 1;
			}
			
		}
		
		prev=tail;
		tail=tail->next;	
	}
	
	return 0;
		
}


//�������
void SortList(void(*ptr)(Node*, Node*),Node* phead)
{
	Node* cur = phead;
	while (cur->next)
	{
		cur = cur->next;
	}

	ptr(phead, cur);

}


void Quicksort_Stunum(Node* low, Node* high)//ѧ������
{
	if (low == NULL || low->next == NULL || low == high)
		return;

	int pivot = ((Student*)low->data)->num;

	Node* i = low->next;
	Node* j = low->next;
	Node* i_pre = low;

	while (j != high->next)
	{
		if (pivot > ((Student*)j->data)->num)
		{
			Swap_StuNode(i, j);

			i_pre = i;
			i = i->next;
		}

		j = j->next;
	}

	Swap_StuNode(low, i_pre);
	Quicksort_Stunum(low, i_pre);
	Quicksort_Stunum(i, high);

}

void Quicksort_Stuage(Node* low, Node* high)//��������
{
	if (low == NULL || low->next == NULL || low == high)
		return;

	int pivot = ((Student*)low->data)->age;

	Node* i = low->next;
	Node* j = low->next;
	Node* i_pre = low;

	while (j != high->next)
	{
		if (pivot > ((Student*)j->data)->age)
		{
			Swap_StuNode(i, j);

			i_pre = i;
			i = i->next;
		}

		j = j->next;
	}

	Swap_StuNode(low, i_pre);
	Quicksort_Stuage(low, i_pre);
	Quicksort_Stuage(i, high);

}

void Quicksort_Stuname(Node* low, Node* high)//��������
{
	if (low == NULL || low->next == NULL || low == high)
		return;

	char pivot[20];
	strcpy(pivot, (((Student*)low->data)->name));
	Node* i = low->next;
	Node* j = low->next;
	Node* i_pre = low;

	while (j != high->next)
	{
		if (strcmp(pivot, ((Student*)j->data)->name)>0)
		{
			Swap_StuNode(i, j);

			i_pre = i;
			i = i->next;
		}

		j = j->next;
	}

	Swap_StuNode(low, i_pre);
	Quicksort_Stuname(low, i_pre);
	Quicksort_Stuname(i, high);
	
}



void Swap_StuNode(Node* i, Node* j)
{
	Student* tmp = (Student*)i->data;
	i->data = j->data;
	j->data = tmp;

}




