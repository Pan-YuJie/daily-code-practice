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

typedef struct position {//玩家
	int x;
	int y;
}position;
typedef struct eposition {//敌机
	double x;
	double y;
	int type;
	double extraspeed;
	int life;
}eposition;
typedef struct bposition {//子弹
	double x;
	double y;
	int pr;//攻击方式
	int bullettype;
	int enemytype;
}bposition;
typedef struct rposition {//残骸
	double x;
	double y;
	int dietype;
	int time;
}rposition;
typedef struct awardposition {//子弹包
	double x;
	double y;
}awardposition;
typedef struct playerhit {//玩家击中敌机特效
	double x;
	double y;
	int delaytime;
}playerhit;
typedef struct boss {
	double x;
	double y;
	int attackstatu;//boss攻击方式
	int eixt;//boss是否存在
	int isdefeat;//boss是否被打败
	int curblood;//现在的血量
	int allblood;//初始化血量
	int xdirection;//横向移动方向
	int ydirection;//纵向移动速度
	int isready;	//boss到位
}boss;



void start();//初始化
void updatewithinput();//与输出有关
void updatewithoutinput();//与输出无关
void show();//显示画面