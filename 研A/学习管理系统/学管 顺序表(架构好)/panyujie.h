#ifndef PANYUJIE_H
#define PANYUJIE_H

typedef struct stud_type
{
	struct stud_type* a;
	int size;// ��Ч���� 
	int cacpcity; //���� 
	
    char num[20]; //ѧ�� 
    char name[10];//���� 
    char sex[20]; //F �� M
    char age[10]; //���� 
}student;

void Menu();   /*�˵�*/ 
void Init(student*);/*��ʼ��*/
void Input(student*);  /*������Ϣ*/
void Putout(student*); /*�����Ϣ*/
int Query(student*);  /*��ѯ��Ϣ*/
void Sort(student*);   /*����*/
float Averge(student*); /*ƽ��ֵ*/ 
void Count_sex(student*,int*);/*������Ů����*/ 
void Delete(student*,int*); /*ɾ��ѧ��*/ 
void Printf(student*);/*��ӡ��Ϣ*/ 

#endif
