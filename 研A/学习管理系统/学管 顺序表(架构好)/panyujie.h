#ifndef PANYUJIE_H
#define PANYUJIE_H

typedef struct stud_type
{
	struct stud_type* a;
	int size;// 有效数据 
	int cacpcity; //容量 
	
    char num[20]; //学号 
    char name[10];//姓名 
    char sex[20]; //F 、 M
    char age[10]; //年龄 
}student;

void Menu();   /*菜单*/ 
void Init(student*);/*初始化*/
void Input(student*);  /*输入信息*/
void Putout(student*); /*输出信息*/
int Query(student*);  /*查询信息*/
void Sort(student*);   /*排序*/
float Averge(student*); /*平均值*/ 
void Count_sex(student*,int*);/*计算男女个数*/ 
void Delete(student*,int*); /*删除学生*/ 
void Printf(student*);/*打印信息*/ 

#endif
