#pragma once
#include<graphics.h>
#include<conio.h>
#include<time.h>
#include<Windows.h>
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

#define width 400
#define high 600
#define size 10
#define blood 6
#define delayedtime 60

typedef struct position {//���
	int x;
	int y;
}position;
typedef struct eposition {//�л�
	double x;
	double y;
	int type;
	double extraspeed;
	int life;
}eposition;
typedef struct bposition {//�ӵ�
	double x;
	double y;
	int pr;//������ʽ
	int bullettype;
	int enemytype;
}bposition;
typedef struct rposition {//�к�
	double x;
	double y;
	int dietype;
	int time;
}rposition;
typedef struct awardposition {//�ӵ���
	double x;
	double y;
}awardposition;
typedef struct playerhit {//��һ��ел���Ч
	double x;
	double y;
	int delaytime;
}playerhit;
typedef struct boss {
	double x;
	double y;
	int attackstatu;//boss������ʽ
	int eixt;//boss�Ƿ����
	int isdefeat;//boss�Ƿ񱻴��
	int curblood;//���ڵ�Ѫ��
	int allblood;//��ʼ��Ѫ��
	int xdirection;//�����ƶ�����
	int ydirection;//�����ƶ��ٶ�
	int isready;	//boss��λ
}boss;



void start();//��ʼ��
void updatewithinput();//������й�
void updatewithoutinput();//������޹�
void show();//��ʾ����