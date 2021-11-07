#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>

enum Sex_type
{
    boy = 0,  // 男生：0
    girl = 1, //女生：1
};

typedef struct StuLink
{
    int xh;               //学生学号（由系统自动生成）
    char xm[20];          //学生姓名
    enum Sex_type xb;     //学生性别（枚举类型)
    int cj;               //学生成绩（0-100之间）
    char dj;              //学生等级
    int mc;               //学生名次
    struct StuLink *next; //单向链表next结点指向下一位学生
} StuLink;

//函数声明
//功能:从数据文件中逐行读取学生信息生成学生链表，返回头指针。
StuLink *ReadFromFile(FILE *fp, StuLink *head);
//功能：先将学生链表按学号升序排序，再将学生链表中的数据逐行保存到数据文件。
void SaveToFile(FILE *fp, StuLink *head);
//功能：在链表尾插入一个新结点，返回头指针
StuLink *InsertNode(StuLink *head);
//修改链表中指定学号的结点（学号不能修改，成绩必须在[0,100]区间的整数）。
void EditNode(StuLink *head, int num);
//功能：删除链表中指定学号的结点，返回头指针。
StuLink *DeleteNode(StuLink *head, int num);
//功能：查询链表中指定学号的结点，并显示查询结果
void QueryNode(StuLink *head, int num);
//功能：查询链表中不及格的所有结点，并显示查询结果
void QueryLink(StuLink *head);
//功能：计算链表中每个结点的名次。
void RankLink(StuLink *head);
//功能：统计并返回各等级人数。
void AnalysisLink(StuLink *head);
//功能：按指定数据项的顺序对学生链表进行排序。
void SortLink(StuLink *head, int choose);
//功能：按指定数据项的顺序输出学生成绩表、各等级人数。
void OutputLink_1(StuLink *head, int choose);
//功能：分页显示全部学生的信息。
void OutputLink_2(StuLink *head, int num);
//功能：匹配等级
void dj_change(StuLink *p);
//功能：确定学号
void xh_define(StuLink *p, StuLink *head);
//功能：计算人数
int count(StuLink *head);
//功能：开始菜单
void start_menu();
//功能：显示二级菜单，返回头指针
StuLink *menu(int choose1, StuLink *head);
//功能：交换两个学生的顺序
void exchange(StuLink *p1, StuLink *p2);
//功能：单独显示10个学生信息
void OutputLink_only10(StuLink *head, int start);

#endif