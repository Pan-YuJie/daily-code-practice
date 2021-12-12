#define _CRT_SECURE_NO_WARNINGS 1
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>
#include  <assert.h>
#include <windows.h> 

FILE* fp ;

typedef struct student
{
	int sno;
	char sname[10];
	char gender[5];  //ֵΪ��F��M
	char nation[10];  //����  
	int age;
}student;

typedef struct Node
{
	student data;
	Node* next;
}Node;


void Pushback(Node**, student);
void Pushfront(Node**, student);
Node* CreatNode(student);
void Printf(Node*);
void Reverse(Node**);
void Destory(Node**);
Node* Readfile(Node**);//��
void WriteFile(Node*);//д
Node* Sort(Node*&);
Node* Modify(Node*&,int);
Node* Erase(Node*&,int);
Node* Find_sno(Node*, int);
Node* Find_sname(Node*, char*);
int* Count_sex(Node* phead);


int main()
{
	

	Node* phead = NULL;
	student data;

	phead= Readfile(&phead);//��
	int option = 0;

	while (1)
	{
		system("cls");
		printf("\n\t**********��ӭ����ѧ������ϵͳ**********\n\n");
		printf("\n\t\t    (1) ѧ���������\n");
		printf("\n\t\t    (2) ѧ����ѯ\n");
		printf("\n\t\t    (3) ͳ����Ů����\n");
		printf("\n\t\t    (4) �������\n");
		printf("\n\t\t    (5) ѧ�������޸�\n");
		printf("\n\t\t    (6) ѧ������ɾ��\n");
		printf("\n\t\t    (7) ��ѧ������\n");
		printf("\n\t\t    (0) �˳�\n");
		printf("\n\t*****************************************\n\n");
		printf("������ָ�0~6��:");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
		{
			while (1)
			{
				printf("\nѧ��:>");
				scanf("%d", &data.sno);
				while (Find_sno(phead, data.sno) != NULL)
				{
					printf("ѧ���Ѵ���,����������\n");
					scanf("%d", &data.sno);
				}
				printf("����:>");
				scanf("%s", &data.sname);

				printf("�Ա���(F/M)��ʾ:>");
				scanf("%s", &data.gender);
				while (strcmp(data.gender, "M") != 0 && strcmp(data.gender, "F") != 0)
				{
					printf("\n�Ա�������������������Ա�!��M�������� F����Ů����\n");
					scanf("%s", &data.gender);
				}


				printf("����:>");
				scanf("%s", &data.nation);

				printf("����:>");
				scanf("%d", &data.age);
				fflush(stdin);

				Pushback(&phead, data);
				WriteFile(phead);

				char op;
				printf("�Ƿ�������� (y/n)\n");
				scanf("%s", &op);

				while (op != 'n' && op != 'y')
				{
					printf("�����������������\n");
					scanf("%s", &op);
				}

				if (op == 'n')
					break;

			}
			break;
		}

		case 2:
		{
			int tmp_sno=0,op=0;
			char tmp_sname[10];
			printf("\n��ѡ��1����ѧ�Ų�ѯ  (2)��������ѯ\n");
			scanf("%d", &op);

			if (op == 1)
			{
				printf("������Ҫ���ҵ�ѧ��:>");
				scanf("%d", &tmp_sno);

				Node* p = Find_sno(phead, tmp_sno);
				if (p == NULL)
					printf("ѧ�Ų�����\n");

				else
				{
					printf("\n\tѧ��\t����\t�Ա�\t����\t����\n");
					printf("\t*****************************************");
					printf("\n\t %d\t %s\t %s\t %s\t %d\n\n\n", p->data.sno, p->data.sname, p->data.gender, p->data.nation, p->data.age);

				}

			}

			else if (op == 2)
			{
				printf("������Ҫ���ҵ�����:>");
				scanf("%s", &tmp_sname);

				Node* p = Find_sname(phead, tmp_sname);
				if (p == NULL)
					printf("����������\n");

				else
				{
					printf("\n\tѧ��\t����\t�Ա�\t����\t����\n");
					printf("\t*****************************************");
					printf("\n\t %d\t %s\t %s\t %s\t %d\n\n\n", p->data.sno, p->data.sname, p->data.gender, p->data.nation, p->data.age);

				}

			}	
			break;
		}

		case 3:
		{
			int* p = Count_sex(phead);
			printf("Ů��һ����%d��\n", p[0]);
			printf("����һ����%d��\n\n", p[1]);

			break;
		}

		case 4:
		{
			Printf(phead);
			break;
		}

		case 5:
		{
			int tmp_sno = 0;
			int choose=0;
			printf("\n����������Ҫ�޸�ѧ����ѧ��:>"); 
			scanf("%d", &tmp_sno);

			Node* p=Find_sno(phead,tmp_sno);

			printf("\n��Ҫ�޸�ѧ����Ϣ����:\n");
			printf("\tѧ��\t����\t�Ա�\t����\t����\n");
			printf("\t %d\t%s\t %s\t %s\t %d\n ", p->data.sno, p->data.sname, p->data.gender, p->data.nation, p->data.age);
			
			printf("\n   (1)����   (2)�Ա�   (3)����  (4)ѧ��   (5)����  (6)���� \n");
			printf("\n��������Ҫ�޸ĵ�ѡ��:>");
			scanf("%d", &choose);
			printf("\n������Ҫ�޸ĵ����ݣ�>");

			Modify(*&p,choose);
			printf("\n�޸ĳɹ�\n");

			break;
		}

		case 6:
		{
			int tmp_sno = 0;
			printf("\n������Ҫɾ��ѧ����ѧ�ţ�>");
			scanf("%d", &tmp_sno);
			Erase(*&phead, tmp_sno);
			printf("\nɾ���ɹ�\n");
			break;
		}

		case 7:
		{
			phead=Sort(*&phead);
			printf("����ɹ�\n");
			Printf(phead);
			break;
		}


		case 0:
			return 0;
			break;

		default:
			printf("ѡ�����������ѡ��\n");
	
		}

		system("pause");
		WriteFile(phead);

	}
	
}

Node* Sort(Node*& phead)
{
	if (phead == NULL || phead->next == NULL) 
		return phead;

	Node* p = phead; 
	Node* helper = (Node*)malloc(sizeof(Node));
	helper->next = NULL;
	Node* pre = NULL; 
	Node* temp = NULL; 

	while (p)
	{
		temp = p->next; 
		pre = helper;
		
		while (pre->next && pre->next->data.sno < p->data.sno)
			pre = pre->next;

		p->next = pre->next;
		pre->next = p;

		p = temp;
	}

	return helper->next;
}




void Pushback(Node** phead, student data)
{
	Node* newnode = CreatNode(data);

	if (*phead == NULL)
	{
		*phead = newnode;
	}

	else
	{
		Node* tail = *phead;

		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}

}

void WriteFile(Node* phead)//д�ļ� 
{
	Node* p = phead;

	if ((fp = fopen("student.txt", "wb+")) == NULL)
	{
		fclose(fp);
		fp = NULL;
		perror("fp");
		return;
	}

	while (p != NULL)
	{
		fwrite(&p->data, sizeof(student), 1, fp);
		p = p->next;
	}

	fclose(fp);
	free(p);

}

Node* Readfile(Node** phead)//���ļ�
{

	if ((fp = fopen("student.txt", "rb")) == NULL)
	{
		fp = fopen("student.txt", "r");
		//�ж��Ƿ��������ļ���ʹָ���ļ�
		fp = NULL;
		perror("fp");
		exit(0);
	}

	student data;
	memset(&data, 0, sizeof(student));


	while (fread(&data, sizeof(student), 1, fp))
	{
		if (feof(fp))
		{
			break;
		}

		Pushback(phead, data);

	}

	fclose(fp);
	fp = NULL;

	return *phead;
}

Node* CreatNode(student newdata)
{

	Node* newnode = (Node*)malloc(sizeof(Node));

	newnode->next = NULL;

	newnode->data.sno = newdata.sno;
	newnode->data.age = newdata.age;

	strcpy(newnode->data.sname, newdata.sname);
	strcpy(newnode->data.gender, newdata.gender);
	strcpy(newnode->data.nation, newdata.nation);

	return newnode;
}


void Pushfront(Node** phead, student data)
{
	Node* newnode = CreatNode(data);

	newnode->next = *phead;
	*phead = newnode;

}


void Printf(Node* phead)
{
	Node* cur = phead;

	if (cur == NULL)
	{
		printf("(NULL)");
		return;
	}

	printf("\n\tѧ��\t����\t�Ա�\t����\t����\n");
	while (cur)
	{
		printf("\t %d\t%s\t %s\t %s\t %d\n ", cur->data.sno, cur->data.sname, cur->data.gender, cur->data.nation, cur->data.age);
		cur = cur->next;
	}
	puts("");
	free(cur);
}


void Destory(Node** phead)
{
	assert(*phead);

	Node* cur = *phead;
	Node* next = NULL;

	while (cur)
	{
		next = cur->next;
		free(cur);
		cur = next;
	}
	*phead = NULL;
}


void Reverse(Node** phead)
{
	Node* cur = *phead;
	Node* newhead = NULL;
	while (cur)
	{
		Node* next = cur->next;
		cur->next = newhead;
		newhead = cur;
		cur = next;
	}
	*phead = newhead;
}

Node* Find_sno(Node* phead, int f_sno)
{
	if (phead == NULL)
		return NULL;


	Node* cur = phead;

	while (cur != NULL)
	{
		if (cur->data.sno == f_sno)
		{
			return cur;
		}

		else if (cur->next == NULL)
		{
			return NULL;//�Ҳ��� 
		}

		cur = cur->next;
	}
	free(cur);
}

Node* Find_sname(Node* phead, char* f_sname)
{
	if (phead == NULL)
		return NULL;

	Node* cur = phead;

	while (cur != NULL)
	{
		if ( strcmp( cur->data.sname , f_sname)==0)
		{
			return cur;
		}

		else if (cur == NULL)
		{
			return NULL;//�Ҳ��� 
		}

		cur = cur->next;
	}
}


Node* Erase(Node*& phead, int e_sno)
{
	if (phead == NULL)
	{
		return NULL;
	}

	Node* cur = phead;
	Node* pre = NULL;

	while (cur->data.sno != e_sno && cur != NULL)
	{
		pre = cur;
		cur = cur->next;
	}

	if (cur->data.sno == e_sno && cur == phead)
	{
		phead = phead->next;
		free(cur);
	}

	else if (cur->data.sno == e_sno)
	{
		pre->next = cur->next;
		free(cur);
	}

	else
	{
		return NULL;
	}

	return phead;

}


Node* Modify(Node*& target,int choose)
{
	if (target == NULL)
	{
		return NULL;
	}

	int tmp_n;
	char tmp_s;

	switch (choose)
	{
	case 1:
		scanf("%s", &target->data.sname);
		break;

	case 2:
		printf("(M�������� F����Ů��)\n");
		scanf("%s", &target->data.gender);
		if (strcmp(target->data.gender, "M")!=0 && strcmp(target->data.gender, "F")!=0)
		{
			printf("\n�Ա�������������������Ա�!��M�������� F����Ů����\n\n");
			scanf("%s", &target->data.gender);
			
		}
		break;

	case 3:
		scanf("%d", &target->data.age);
		break;
	case 4:
		scanf("%d", &target->data.sno);
		while (Find_sno(target, target->data.sno) != NULL)
		{
			printf("ѧ���Ѵ���,����������\n");
			scanf("%d", &target->data.sno);
		}
		break;
	case 5:
		scanf("%s", &target->data.gender);
		break;
	case 6:
		return target;

	default:
		printf("\nѡ�����������ѡ��\n");
	}
	
}

int* Count_sex(Node* phead)
{
	Node* cur = phead;

	int* cnt = (int*)malloc(sizeof(int)*2);
	cnt[0] = 0;
	cnt[1] = 0;
	while (cur)
	{
		if (strcmp(cur->data.gender, "F")==0)
		{
			cnt[0]++;
		}
		
		else if (strcmp(cur->data.gender, "M")==0)
		{
			cnt[1]++;
		}

		cur = cur->next;
	}

	return cnt;

}


