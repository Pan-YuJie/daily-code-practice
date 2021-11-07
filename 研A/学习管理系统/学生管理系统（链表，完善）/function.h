#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

enum Sex_type
{
    boy = 0,  // ������0
    girl = 1, //Ů����1
};

typedef struct StuLink
{
    int xh;               //ѧ��ѧ�ţ���ϵͳ�Զ����ɣ�
    char xm[20];          //ѧ������
    enum Sex_type xb;     //ѧ���Ա�ö������)
    int cj;               //ѧ���ɼ���0-100֮�䣩
    char dj;              //ѧ���ȼ�
    int mc;               //ѧ������
    struct StuLink *next; //��������next���ָ����һλѧ��
} StuLink;

//��������
//����:�������ļ������ж�ȡѧ����Ϣ����ѧ����������ͷָ�롣
StuLink *ReadFromFile(FILE *fp, StuLink *head);
//���ܣ��Ƚ�ѧ������ѧ�����������ٽ�ѧ�������е��������б��浽�����ļ���
void SaveToFile(FILE *fp, StuLink *head);
//���ܣ�������β����һ���½�㣬����ͷָ��
StuLink *InsertNode(StuLink *head);
//�޸�������ָ��ѧ�ŵĽ�㣨ѧ�Ų����޸ģ��ɼ�������[0,100]�������������
void EditNode(StuLink *head, int num);
//���ܣ�ɾ��������ָ��ѧ�ŵĽ�㣬����ͷָ�롣
StuLink *DeleteNode(StuLink *head, int num);
//���ܣ���ѯ������ָ��ѧ�ŵĽ�㣬����ʾ��ѯ���
void QueryNode(StuLink *head, int num);
//���ܣ���ѯ�����в���������н�㣬����ʾ��ѯ���
void QueryLink(StuLink *head);
//���ܣ�����������ÿ���������Ρ�
void RankLink(StuLink *head);
//���ܣ�ͳ�Ʋ����ظ��ȼ�������
void AnalysisLink(StuLink *head);
//���ܣ���ָ���������˳���ѧ�������������
void SortLink(StuLink *head, int choose);
//���ܣ���ָ���������˳�����ѧ���ɼ������ȼ�������
void OutputLink_1(StuLink *head, int choose);
//���ܣ���ҳ��ʾȫ��ѧ������Ϣ��
void OutputLink_2(StuLink *head, int num);
//���ܣ�ƥ��ȼ�
void dj_change(StuLink *p);
//���ܣ�ȷ��ѧ��
void xh_define(StuLink *p, StuLink *head);
//���ܣ���������
int count(StuLink *head);
//���ܣ���ʼ�˵�
void start_menu();
//���ܣ���ʾ�����˵�������ͷָ��
StuLink *menu(int choose1, StuLink *head);
//���ܣ���������ѧ����˳��
void exchange(StuLink *p1, StuLink *p2);
//���ܣ�������ʾ10��ѧ����Ϣ
void OutputLink_only10(StuLink *head, int start);

#endif