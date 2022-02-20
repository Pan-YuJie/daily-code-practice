#include"标头.h"
#pragma comment(lib,"winmm.lib")//引用Windows Multimedia API

IMAGE startbackground;					    	//开始时背景图
IMAGE startbutton, startbutton_p;				//开始按钮
IMAGE startbutton_x, startbutton_x_p;			//开始按钮旋转
IMAGE background;								//背景图片
IMAGE enemy_q1, enemy_p1,bomenemy_q1,bomenemy_p1;	//敌机1图片
IMAGE enemy_q2, enemy_p2, bomenemy_q2, bomenemy_p2;	//敌机2图片
IMAGE enemy_q3, enemy_p3, bomenemy_q3, bomenemy_p3;	//敌机3图片
IMAGE bullet_q, bullet_p;						//玩家飞机子弹图片
IMAGE enbullet_q, enbullet_p;					//敌机子弹
IMAGE remain_q, remain_p,remain_q2,remain_p2,remain_q3,remain_p3;//残骸图片
IMAGE reward_q, reward_p;						//子弹包图片
IMAGE reward_2q, reward_2p;						//子弹包2图片
IMAGE supplyhelp_q, supplyhelp_p;				//补给包图片
IMAGE player_q0, player_p0;						//玩家飞机图片
IMAGE bulleteffect_q, bulleteffect_p;			//玩家子弹击中效果图
IMAGE boss_q, boss_p;							//boss图
IMAGE bossbt1_q, bossbt1_p;						//boss子弹1图
IMAGE bossbt3_q, bossbt3_p;						//3


position play;				//玩家坐标
eposition enemy[size];	//敌机----修改数量
int enemynum = 0;			//敌机数量
double enemyspeed = 0.5;	//敌机速度
int enemyappearinterval[size];//敌机位置刷新间隔记录
int enemyappearspeed = 3;	//敌机出现间隔
bposition bullet[size * 3];	//当前子弹存在数---修改数量30
int bulletinterval = delayedtime * 2;//玩家子弹发射间隔
bposition enemybullet[size * 2];//敌机当前子弹存在数---修改数量
int enemyattackinterval[size * 2] = { 0 };//敌机攻击间隔
int score = 0;				//得分数
int bulletnum = 0;			//画面中的玩家子弹数
int enemybulletnum = 0;		//画面中敌机的子弹数
double bulletspeed = 1;		//子弹速度
int firepower = 1;			//飞机火力
int firerows = 1;			//飞机火力排数
int valueoflife = blood;	//玩家生命值
awardposition reward[3];				//子弹包坐标
int havehelped = 0;			//补给包只给一次
int isrewardsave[3] = { 0 };		//炸药包存在 则 置1
int ishurt = 0;				//玩家飞机被击短时间显示
rposition enemydietime[size];//敌机残骸数目数组
playerhit hiteffect[size * 3];		//玩家击中敌机特效位置存储
int score10 = 10, score15 = 15, score50 = 50, score70 = 70;	//得分触发
boss last;//BOSS
int bossstackinterval;//boss子弹攻击间隔
bposition bossbullet[size * 2];//boss子弹
int bossbulletnum = size * 2;//boss子弹数
int bosssuperatack = 0;//boss大招是否在释放
int superatacklast = 0;//boss大招持续时间中
int superatackready = 20 * size;//大招前的缓冲


void startinterface();				//显示游戏开始界面
void isdie();						//重新设置敌机位置
void updatebullet(int pr);			//子弹数组内部位置重置
void drawscore(int);				//显示分数
void gameover();					//游戏结束处理
void addenemy();					//增加一个敌机
void updateenemyposition(int i);	//更新损毁的敌机位置
void enemyexplodevoice();			//敌机爆炸声效
void updateenemybullet(int pr);		//更新敌机子弹数组内位置
void isenemyattack(int j, int type);//判断敌机是否攻击 敌机数组的下标 敌机种类
void drawblood();					//显示玩家血条
void drawenemyblood(int i);			//显示敌机血条
void drawbulletnum(); 				//显示子弹缓冲
void initboos();					//初始化boss
void bossevent();					//boss事件
void drawbossblood();				//BOSS血条
void isbossbehit();					//BOSS是否中弹
void bossatack();					//boss是否攻击
void bosshitplayer();				//boss击中玩家

void loadimg() {					//加载图片
	loadimage(&startbackground, "飞机大战图片音乐素材\\first.jpg");		//开始界面
	loadimage(&startbutton, "飞机大战图片音乐素材\\resume.jpg");		//三角形按钮
	loadimage(&startbutton_p, "飞机大战图片音乐素材\\resume3.jpg");		
	loadimage(&startbutton_x, "飞机大战图片音乐素材\\resume_x.jpg");	//旋转三角形按钮
	loadimage(&startbutton_x_p, "飞机大战图片音乐素材\\resume2_x.jpg");
	loadimage(&background, "飞机大战图片音乐素材\\background2.jpg");	//游戏背景
	loadimage(&player_q0, "飞机大战图片音乐素材\\player_0.jpg");		//玩家飞机
	loadimage(&player_p0, "飞机大战图片音乐素材\\player_00.jpg");
	loadimage(&enemy_q1, "飞机大战图片音乐素材\\enemyPlane2.jpg");		//敌人飞机1
	loadimage(&enemy_p1, "飞机大战图片音乐素材\\enemyPlane1.jpg");
	loadimage(&bomenemy_q1, "飞机大战图片音乐素材\\npc_3.jpg");		//敌人飞机1残骸
	loadimage(&bomenemy_p1, "飞机大战图片音乐素材\\npc_33.jpg");
	loadimage(&enemy_q2, "飞机大战图片音乐素材\\enemy1.jpg");		//敌人飞机2
	loadimage(&enemy_p2, "飞机大战图片音乐素材\\enemy11.jpg");
	loadimage(&bomenemy_q2, "飞机大战图片音乐素材\\enemy1die_1.jpg");		//敌人飞机2残骸
	loadimage(&bomenemy_p2, "飞机大战图片音乐素材\\enemy1die_11.jpg");
	loadimage(&enemy_q3, "飞机大战图片音乐素材\\enemy2.jpg");		//敌人飞机3
	loadimage(&enemy_p3, "飞机大战图片音乐素材\\enemy22.jpg");
	loadimage(&bomenemy_q3, "飞机大战图片音乐素材\\enemy2die_1.jpg");		//敌人飞机3残骸
	loadimage(&bomenemy_p3, "飞机大战图片音乐素材\\enemy2die_11.jpg");
	loadimage(&bullet_q, "飞机大战图片音乐素材\\bullet44.jpg");			//子弹1
	loadimage(&bullet_p, "飞机大战图片音乐素材\\bullet33.jpg");
	loadimage(&enbullet_q, "飞机大战图片音乐素材\\bullet22.jpg");			//子弹1
	loadimage(&enbullet_p, "飞机大战图片音乐素材\\bullet11.jpg");
	loadimage(&reward_q, "飞机大战图片音乐素材\\award_1.jpg");			//子弹包
	loadimage(&reward_p, "飞机大战图片音乐素材\\award_1p.jpg");
	loadimage(&reward_2q, "飞机大战图片音乐素材\\award_2.jpg");			//子弹包2
	loadimage(&reward_2p, "飞机大战图片音乐素材\\award_2p.jpg");
	loadimage(&supplyhelp_q, "飞机大战图片音乐素材\\补给包.jpg");			//补给包
	loadimage(&supplyhelp_p, "飞机大战图片音乐素材\\补给包_p.jpg");
	loadimage(&remain_q2, "飞机大战图片音乐素材\\player_1.jpg");		//玩家飞机损毁1
	loadimage(&remain_p2, "飞机大战图片音乐素材\\player_11.jpg");
	loadimage(&remain_q3, "飞机大战图片音乐素材\\player_2.jpg");		//玩家飞机损毁2
	loadimage(&remain_p3, "飞机大战图片音乐素材\\player_22.jpg");
	loadimage(&remain_q, "飞机大战图片音乐素材\\player_3.jpg");			//玩家飞机损毁3
	loadimage(&remain_p, "飞机大战图片音乐素材\\player_33.jpg");
	loadimage(&bulleteffect_q, "飞机大战图片音乐素材\\子弹效果.jpg");			//玩家飞机损毁3
	loadimage(&bulleteffect_p, "飞机大战图片音乐素材\\子弹效果_p.jpg");
	loadimage(&boss_q, "飞机大战图片音乐素材\\boss.jpg");			//boss
	loadimage(&boss_p, "飞机大战图片音乐素材\\boss_p.jpg");
	loadimage(&bossbt1_q, "飞机大战图片音乐素材\\bossbullet1.jpg");			//boss子弹1
	loadimage(&bossbt1_p, "飞机大战图片音乐素材\\bossbullet1_p.jpg");
	loadimage(&bossbt3_q, "飞机大战图片音乐素材\\bossbullet3.jpg");			//boss子弹3
	loadimage(&bossbt3_p, "飞机大战图片音乐素材\\bossbullet3_p.jpg");
	BeginBatchDraw();
}

void loadmsc() {				//加载音乐open C:\\Users\\lenovo\\Desktop
	mciSendString("open 飞机大战图片音乐素材\\game_music.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);
}
	
void initplay() {				
	int i;//循环变量
	play.x = width / 2;	//初始化玩家
	play.y = high / 2;
	for (i = 0; i < size; i++)	//初始化敌机残骸存在时间
		enemydietime[i].time = 0;
	for (i = 0; i < size * 3; i++) {	//初始化玩家击中敌机特效存在标记
		hiteffect[i].delaytime = 0;
	}

	last.isdefeat = 0;//BOSS状态初始化
	last.x = rand() % 230;
	last.y = -400;
	last.eixt = 0;
	for (i = 0; i < bossbulletnum; i++)
		bossbullet[i].pr = 0;

	reward[0].y = reward[1].y = reward[2].y = -200;	//子弹包初始化不显示
	addenemy();					//初始化一个敌机
};

void start() {						//初始化
	loadmsc();						//背景音乐
	srand((unsigned int)time(NULL));//时间种子随机
	initgraph(width, high);			//初始化画布
	loadimg();						//装背景图
	initplay();						//初始化玩家
	startinterface();				//开始界面
}

void show() {						//显示画布
	int i;
	putimage(0, 0, &background);	//显示背景图
	if (ishurt <= 0) {//飞机原图
		putimage(play.x - 50, play.y - 50, &player_p0, NOTSRCERASE);	//飞机遮罩图
		putimage(play.x - 50, play.y - 50, &player_q0, SRCINVERT);	//飞机原图
	}
	else {//飞机受轻伤
		putimage(play.x - 48, play.y - 50, &remain_p2, NOTSRCERASE);		//飞机受轻伤遮罩图
		putimage(play.x - 48, play.y - 50, &remain_q2, SRCINVERT);		//飞机受轻伤原图
	}
	if (isrewardsave[0] != 0) {//子弹包1
		putimage((int)reward[0].x, (int)reward[0].y, &reward_p, NOTSRCERASE);	//子弹包遮罩图
		putimage((int)reward[0].x, (int)reward[0].y, &reward_q, SRCINVERT);	//子弹包原图
	}
	if (isrewardsave[1] != 0) {//子弹包2
		putimage((int)reward[1].x, (int)reward[1].y, &reward_2p, NOTSRCERASE);	//子弹包2遮罩图
		putimage((int)reward[1].x, (int)reward[1].y, &reward_2q, SRCINVERT);	//子弹包2原图
	}
	if (isrewardsave[2] != 0) {//补给包
		putimage((int)reward[2].x, (int)reward[2].y, &supplyhelp_p, NOTSRCERASE);	//子弹包2遮罩图
		putimage((int)reward[2].x, (int)reward[2].y, &supplyhelp_q, SRCINVERT);	//子弹包2原图
	}
	for (i = 0; i < enemynum; i++) {//显示所有敌机   
		drawenemyblood(i);				//显示敌机血条
		if (enemyappearinterval[i] > 0) {	//被消灭的短时间不出现
			enemyappearinterval[i]--;
			if (enemyappearinterval[i] == 0)
				updateenemyposition(i);
			else
				continue;
		}
		switch (enemy[i].type) {
		case 1: {
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_p1, NOTSRCERASE);	//敌机遮罩图
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_q1, SRCINVERT);	//敌机原图
			break;
		}
		case 2: {
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_p2, NOTSRCERASE);	//敌机遮罩图
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_q2, SRCINVERT);	//敌机原图
			break;
		}
		case 3: {
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_p3, NOTSRCERASE);	//敌机遮罩图
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_q3, SRCINVERT);	//敌机原图
			break;
		}
		}
		
	}
	for (i = 0; i < size; i++) {	//显示所有敌机残骸
		if (enemydietime[i].time > 0) {
			switch (enemydietime[i].dietype) {
			case 1: {
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_p1, NOTSRCERASE);//敌机残骸遮罩图
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_q1, SRCINVERT);
				break;
			}
			case 2: {
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_p2, NOTSRCERASE);//敌机残骸遮罩图
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_q2, SRCINVERT);
				break;
			}
			case 3: {
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_p3, NOTSRCERASE);//敌机残骸遮罩图
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_q3, SRCINVERT);
				break;
			}
			}
		}
	}
	for (i = 0; i < size * 3; i++) {//显示子弹击中敌机特效
		if (hiteffect[i].delaytime > 0) {
			putimage((int)hiteffect[i].x - 34, (int)hiteffect[i].y - 98, &bulleteffect_p, NOTSRCERASE);		//飞机受轻伤遮罩图
			putimage((int)hiteffect[i].x - 34, (int)hiteffect[i].y - 98, &bulleteffect_q, SRCINVERT);		//飞机受轻伤原图
		}
	}
	for (i = 0; i < bulletnum; i++) {	//显示所有玩家子弹
		putimage((int)bullet[i].x - 3, (int)bullet[i].y - 60, &bullet_p, NOTSRCERASE);//子弹遮罩图
		putimage((int)bullet[i].x - 3, (int)bullet[i].y - 60, &bullet_q, SRCINVERT);//子弹原图
	}
	int width_1, high_1;
	for (i = 0; i < enemybulletnum; i++) {//显示所有敌机子弹
		switch (enemybullet[i].enemytype) {	//针对不同敌机 不同的子弹识别区域
		case 1:width_1 = 50, high_1 = 150; break;
		case 2:width_1 = 22, high_1 = 40; break;
		case 3:width_1 = 33, high_1 = 90; break;
		}
		putimage((int)enemybullet[i].x + width_1, (int)enemybullet[i].y + high_1, &enbullet_p, NOTSRCERASE);//子弹遮罩图
		putimage((int)enemybullet[i].x + width_1, (int)enemybullet[i].y + high_1, &enbullet_q, SRCINVERT);//子弹原图
	}
	if (last.eixt == 1) {		//显示boss
		drawbossblood();//显示血条
		putimage((int)last.x, (int)last.y, &boss_p, NOTSRCERASE);//boss遮罩图
		putimage((int)last.x, (int)last.y, &boss_q, SRCINVERT);//boss原图
		int i;
		for (i = 0; i < bossbulletnum; i++) {//显示boss子弹
			if (bossbullet[i].pr == 0)
				continue;
			switch (bossbullet[i].bullettype) {
			case 1: {//1
				putimage((int)bossbullet[i].x, (int)bossbullet[i].y, &bossbt1_p, NOTSRCERASE);//boss子弹1遮罩图
				putimage((int)bossbullet[i].x, (int)bossbullet[i].y, &bossbt1_q, SRCINVERT);//boss子弹1原图
				break;
			}
			case 3: {//3。大招
				if (superatacklast > 0) {
					putimage((int)bossbullet[i].x, (int)bossbullet[i].y, &bossbt3_p, NOTSRCERASE);//boss子弹2遮罩图
					putimage((int)bossbullet[i].x, (int)bossbullet[i].y, &bossbt3_q, SRCINVERT);//boss子弹2原图
				}
				break;
			}
			}
		}
	}
	drawscore(score);						//显示分数
	drawblood();							//显示玩家生命值
	drawbulletnum();						//显示玩家子弹缓存
	FlushBatchDraw();						//刷新画布
	Sleep(3);								//画面刷新间隔
}

void updatewithoutinput() {			//和玩家 输入 无关
	int i;//用于循环
	if (ishurt>0)		//玩家飞机被击短时间显示
		ishurt--;

	//BOSS出场
	if (last.eixt == 1 && last.y < 10 && last.isready==0) {
		last.y += 0.3;
		if (last.y >= 10)
			last.isready = 1;
	}
	if (last.eixt == 1) {
		if (bossstackinterval > 0)//boss攻击间隔
			bossstackinterval--;
		bossevent();//boss活动
		isbossbehit();//boss是否中弹
		bossatack();	//boss攻击
		bosshitplayer();//boss击中玩家
		for (int i = 0; i < bossbulletnum; i++) {
			if (bossbullet[i].pr == 0 || bossbullet[i].bullettype == 3)
				continue;
			if (bossbullet[i].y < 650)	//boss子弹下落
				bossbullet[i].y+=1.2;
			if (bossbullet[i].y >= 650)	//boss子弹出界
				bossbullet[i].pr = 0;
		}
		if (bosssuperatack == 1) {
			superatacklast--;
			if (superatacklast == 0) {
				bosssuperatack = 0;
				superatacklast = -1;//已经放过了
			}
		}
	}

	for (i = 0; i < 3; i++) {	//补给包掉落 —— 3种
		if (isrewardsave[i] != 0)
			reward[i].y++;
	}
	for (i = 0; i < enemynum; i++) {//敌机移动
		if (enemyappearinterval[i] == 0)
			enemy[i].y = enemy[i].y + enemy[i].extraspeed + enemyspeed;	
	}
	for (i = 0; i < bulletnum; i++) {
		bullet[i].y -= bulletspeed;			//玩家子弹移动
		bullet[i].x += bullet[i].pr*0.3;	//根据子弹数目形成散弹_散射参数
	}
	for (i = 0; i < enemybulletnum; i++)//敌机子弹移动
		enemybullet[i].y += (bulletspeed*0.7 + enemyspeed + enemy[i].extraspeed);
	for (i = 0; i < enemynum; i++)	//对每个敌机判定是否发射子弹
		if (enemyappearinterval[i] == 0 && enemy[i].type != 2)
			isenemyattack(i, enemy[i].type);	//判断敌机是否攻击 敌机数组的下标 敌机种类
	for (i = 0; i < size; i++) 		//敌机残骸存在处理
		if (enemydietime[i].time > 0)
			enemydietime[i].time--;
	for (i = 0; i < enemynum; i++) {//敌机再次出现间隔处理
		if (enemyattackinterval[i] > 0)
			enemyattackinterval[i]--;
	}
	for (i = 0; i < size * 3; i++) {//玩家击中敌机特效出现处理
		if (hiteffect[i].delaytime>0)
			hiteffect[i].delaytime--;
	}

	isdie();						//重新设置 敌机、子弹、补给 位置
	gameover();						//游戏结束
}

void updatewithinput() {					//和玩家 输入 有关
	static int time = 50;				//子弹发射间隔——防止点击开始后的第一发子弹
	MOUSEMSG m;
	while (MouseHit()) {
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE) {		//飞机移动
			play.x = m.x;
			play.y = m.y;
		}
		else if (m.uMsg = WM_LBUTTONDOWN && time < 1 && (bulletnum + firepower*firerows < size * 3)) {//发射子弹 间隔 子弹未满
			mciSendString("close fgmusic", NULL, 0, NULL);
			mciSendString("open 飞机大战图片音乐素材\\f_gun.mp3 alias fgmusic", NULL, 0, NULL);
			mciSendString("play fgmusic", NULL, 0, NULL);
			double y = 0;//这个y按照 0.5 -1 1.5 -2 2.5...再取整 以 显示以飞机为中心的两旁子弹
			for (int i = 0; i < firepower; i++) {
				y = fabs(y) + 0.5;//子弹发射方向种类
				if (i % 2 == 1)
					y *= -1;
				else
					y = fabs(y);
				for (int row = 0; row < firerows; row++) {
					bullet[bulletnum].pr = (int)y;		//决定子弹横向攻击类型
					if (firepower % 2 == 0)//偶数
						if ((int)y >= 0)
							bullet[bulletnum].pr += 1;	//偶数子弹散弹形式
					bullet[bulletnum].x = play.x + 10 * (int)y;		//散弹
					bullet[bulletnum++].y = play.y + row * 20;		//排数
				}
			}
			time = bulletinterval;	//子弹发射间隔重置为通用值
		}
	}
	time--;							//子弹发射间隔
}

void scoretoaction() {						//击落一架飞机 且 分数到达指定点 触发 相关动作
	if (score >= 180 && last.eixt == 0) {//BOSS出现分数条件
		initboos();//初始化BOSS
	}
	if (score <= 0)
		return;
	if (score >=score10) {
		if (enemyspeed < 1.0)	//敌人速度更快
			enemyspeed += 0.10;									
		if (enemyappearspeed > 2)	//敌机出现更快
			enemyappearspeed--;
		score10 *= 2;
	}
	if (score >= score50) {
		if (enemynum < 4 && last.eixt==0)
			addenemy();//增加一个敌机
		score50 *= 2;
	}
	if (score >= score15) {					//----奖励----修改
		if (bulletinterval > 40)
			bulletinterval -= 10;				//子弹发射间隔缩短
		if (isrewardsave[0] == 0 && firepower <5) {			//掉落子弹包1_散弹_修改限制
			isrewardsave[0] = 1;
			reward[0].x = rand() % 350;
			reward[0].y = -(rand() % 100 + 100);
		}
		if (bulletspeed != 5)
			bulletspeed += 0.5;					//子弹速度更快
		score15 *= 2;
	}
	if (score >= score70) {
		if (isrewardsave[1] == 0 && firerows < 2) {				//掉落子弹包2_排数_修改限制
			isrewardsave[1] = 1;
			reward[1].x = rand() % 350;
			reward[1].y = -(rand() % 100 + 100);
		}
//		mciSendString("close lemusic", NULL, 0, NULL);
		mciSendString("open 飞机大战图片音乐素材\\超神.mp3 alias lemusic", NULL, 0, NULL);
		mciSendString("play lemusic", NULL, 0, NULL);
		score70 *= 2;
	}
	if (isrewardsave[2] == 0 && valueoflife	<=3 && havehelped == 0) {			//掉落补给_修改限制
		havehelped = 1;
		isrewardsave[2] = 1;
		reward[2].x = rand() % 350;
		reward[2].y = -(rand() % 100 + 100);
	}
}

void isdie() {									//重新设置 敌机 和 子弹 和 子弹包位置
	int ismissbullet;							//玩家子弹是否消失
	int ismissenemybullet;						//敌机子弹是否消失
	int i, k;
	for (i = 0; i < enemynum; i++) {		//敌机 出界处理
		if (enemy[i].y > 660) {		
			//被摧毁敌机下一次出现间隔设定
			enemyappearinterval[i] = delayedtime * enemyappearspeed;
			enemy[i].y = -300;//被摧毁敌机短时间放回别的地方
			enemy[i].x = -300;
			valueoflife--;			//生命减少
		}
	}
	for (i = 0; i < enemybulletnum; i++) {	//敌机 子弹消失 处理	
		//判断敌机消失——————子弹越界
		ismissenemybullet = 0;
		if (enemybullet[i].y > 650) {			//敌机子弹消失判定条件
			updateenemybullet(i);				//更新敌机子弹 数组内部的位置
			enemybulletnum--;					//敌机子弹数减一
			ismissenemybullet++;				//确实发生敌机子弹消失
		}
		if (ismissenemybullet > 0) {	//退格
			i--;
			continue;
		}
		//判断敌机消失——————玩家中弹	
		int width_1, high_1;
		switch (enemybullet[i].enemytype) {	//针对不同敌机 不同的子弹识别区域
		case 1:width_1 = 50, high_1 = 150; break;
		case 2:width_1 = 22, high_1 = 40; break;
		case 3:width_1 = 33, high_1 = 90; break;
		}
		if (enemybullet[i].x + width_1 > play.x - 35 && enemybullet[i].x + width_1 < play.x + 35 && enemybullet[i].y + high_1>play.y - 35 && enemybullet[i].y + high_1< play.y + 35) {
			mciSendString("close playerhurtmusic", NULL, 0, NULL);
			mciSendString("open 飞机大战图片音乐素材\\子弹擦边.mp3 alias playerhurtmusic", NULL, 0, NULL);
			mciSendString("play playerhurtmusic", NULL, 0, NULL);
			putimage(play.x - 48, play.y - 50, &remain_p2, NOTSRCERASE);	//飞机受伤遮罩图
			putimage(play.x - 48, play.y - 50, &remain_q2, SRCINVERT);		//飞机受伤原图
			ishurt = delayedtime * 2;			//玩家飞机被击短时间显示
			valueoflife--;						//中弹生命减少
			updateenemybullet(i);				//更新敌机子弹 数组内部的位置
			enemybulletnum--;					//敌机子弹数减一
			ismissenemybullet++;				//确实发生敌机子弹消失
		}
		if (ismissenemybullet > 0) {	//退格
			i--;
			continue;
		}
	}
	//i是玩家子弹  k是敌人   t是敌人残骸
	int width_1, high_1;
	for (i = 0; i < bulletnum; i++)	{		//玩家 子弹消失 处理
		ismissbullet = 0;
		for (k = 0; k < enemynum; k++) {//子弹命中敌机
			switch (enemy[k].type) {	//针对不同敌机 不同的子弹识别区域
			case 1:width_1 = 100, high_1 = 180; break;
			case 2:width_1 = 50, high_1 = 90; break;
			case 3:width_1 = 77, high_1 = 130; break;
			}
			//+6是为了和图像 实际位置 契合
			if (bullet[i].x + 6 > enemy[k].x && bullet[i].x + 6 < enemy[k].x + width_1 && bullet[i].y > enemy[k].y && bullet[i].y < enemy[k].y + high_1) {
				//显示子弹特效处理
				for (int hitenemy = 0; hitenemy < size * 3; hitenemy++) {
					if (hiteffect[hitenemy].delaytime == 0) {
						hiteffect[hitenemy].delaytime = delayedtime * 1;
						hiteffect[hitenemy].x = bullet[i].x;
						hiteffect[hitenemy].y = bullet[i].y;
						break;//别忘了
					}
				}
				updatebullet(i);					//更新子弹 数组内部的位置
				bulletnum--;						//子弹数减一
				ismissbullet++;						//确实发生玩家子弹消失
				enemy[k].life--;		//敌人中弹 生命减少1
				if (enemy[k].life != 0) {//敌人如果没死 就发出击中音效 否则跳过  去发出爆炸音效
					mciSendString("close hitenemymusic", NULL, 0, NULL);
					mciSendString("open 飞机大战图片音乐素材\\敌机中弹.mp3 alias hitenemymusic", NULL, 0, NULL);
					mciSendString("play hitenemymusic", NULL, 0, NULL);
					goto aim2;//子弹击中敌机 敌机受伤本次子弹判断结束 跳转1
				}
				for (int t = 0; t < size; t++)	//找到存放下一次出现敌机数组的位置_显示敌机残骸
				{
					if (enemydietime[t].time == 0) {
						enemydietime[t].x = enemy[k].x;//敌人位置 赋给 敌人残骸坐标
						enemydietime[t].y = enemy[k].y;
						enemydietime[t].dietype = enemy[k].type;
						enemydietime[t].time = delayedtime;//延迟时段
						break;//别忘了
					}
				}
				enemyexplodevoice();			//敌机爆炸音效
				//被摧毁敌机下一次出现间隔设定
				enemyappearinterval[k] = delayedtime * enemyappearspeed;
				enemy[k].y = -300;				//被摧毁敌机短时间放回别的地方
				enemy[k].x = -300;
				switch (enemy[k].type) {		//玩家得分
				case 1:score += 3; break;
				case 2:score++; break;
				case 3:score += 2; break;
				}
				scoretoaction();				//分数到达指定点 触发 相关动作
				goto aim2;//子弹击中敌机 敌机爆炸 本次子弹判断结束 跳转2
			}
		}
		if (bullet[i].y < -10) {	//玩家子弹消失————越界
			updatebullet(i);					//更新子弹 数组内部的位置
			bulletnum--;						//子弹数减一
			ismissbullet++;						//确实发生玩家子弹消失
		}
aim2:		;//跳转
		if(ismissbullet>0)
			i--;			//退回去
	}
	//加到 子弹包 增强弹药 或是 子弹包自动被收回
	for (i = 0; i < 3; i++) {
		if ((((play.x) - (reward[i].x + 33))*((play.x) - (reward[i].x + 33)) + ((play.y) - (reward[i].y + 45))*((play.y) - (reward[i].y + 45)) < 4500) || reward[i].y>650) {
			if (reward[i].y <= 650) {	//加到子弹包 强化子弹效果
				switch (i){	
				case 0:firepower++; break;
				case 1:firerows++; break;
				case 2:valueoflife += 3; break;
				}
				mciSendString("close rewardmusic", NULL, 0, NULL);
				mciSendString("open 飞机大战图片音乐素材\\gotreward.mp3 alias rewardmusic", NULL, 0, NULL);
				mciSendString("play rewardmusic", NULL, 0, NULL);
			}
			reward[i].y = -200;	//子弹包位置重置
			isrewardsave[i] = 0;//重新置零
		}
	}
}

void updatebullet(int pr) {						//更新子弹 数组内部的位置
	for (int i = pr; i < bulletnum - 1; i++)
		bullet[i] = bullet[i + 1];
}

void updateenemybullet(int pr) {				//更新敌机子弹 数组内的位置
	for (int i = pr; i < enemybulletnum - 1; i++)
		enemybullet[i] = enemybullet[i + 1];
}

void gameover() {						//游戏结束处理
	int width_1, high_1, length_1;
	for (int i = 0; i < enemynum; i++) {//判断发生 碰撞
		switch (enemy[i].type) {	//针对不同敌机 不同的碰撞识别区域
		case 1:width_1 = 50, high_1 = 80; length_1 = 7400; break;
		case 2:width_1 = 25, high_1 = 20; length_1 = 2700; break;
		case 3:width_1 = 33, high_1 = 47; length_1 = 4700; break;
		}
		if (((enemy[i].x + width_1) - (play.x))*((enemy[i].x + width_1) - (play.x)) + ((enemy[i].y + high_1) - (play.y))*((enemy[i].y + high_1) - (play.y)) < length_1) {
			if (enemy[i].type == 2)
			{
				//此for循环用于显示撞到玩家的小飞机残骸 以及 刷新下次位置
				for (int t = 0; t < size; t++)	//找到存放下一次出现敌机数组的位置_显示敌机残骸
				{
					if (enemydietime[t].time == 0) {
						enemydietime[t].x = enemy[i].x;
						enemydietime[t].y = enemy[i].y;
						enemydietime[t].dietype = enemy[i].type;
						enemydietime[t].time = delayedtime;//延迟时段
						enemyexplodevoice();			//敌机爆炸音效
						enemyappearinterval[i] = delayedtime * enemyappearspeed;
						enemy[i].y = -300;				//被摧毁敌机短时间放回别的地方
						enemy[i].x = -300;
						break;
					}
				}
				valueoflife -= 3;			//撞到小飞机
				ishurt = delayedtime * 4;					//被撞显示
			}
			else
				valueoflife = 0;			//清空血条
		}	
	}
	if (valueoflife <= 0)												//失败---被摧毁
	{
		TCHAR s[size * 2];
		mciSendString("close bkmusic", NULL, 0, NULL);					//关闭音乐
		drawblood();								//显示空血条
													//碰撞毁坏音效
		mciSendString("open 飞机大战图片音乐素材\\explode.mp3 alias exmusic", NULL, 0, NULL);
		mciSendString("play exmusic", NULL, 0, NULL);
		putimage(play.x - 48, play.y - 50, &remain_p2, NOTSRCERASE);		//飞机残骸遮罩图1
		putimage(play.x - 48, play.y - 50, &remain_q2, SRCINVERT);		//飞机残骸原图1
		FlushBatchDraw();
		Sleep(80);
		putimage(play.x - 47, play.y - 48, &remain_p3, NOTSRCERASE);		//飞机残骸遮罩图2
		putimage(play.x - 47, play.y - 48, &remain_q3, SRCINVERT);		//飞机残骸原图2
		FlushBatchDraw();				//刷新画布
		Sleep(210);
		putimage(play.x - 48, play.y - 50, &remain_p, NOTSRCERASE);		//飞机残骸遮罩图3
		putimage(play.x - 48, play.y - 50, &remain_q, SRCINVERT);		//飞机残骸原图3
		FlushBatchDraw();

		Sleep(1000);						//暂停画面
		putimage(0, 0, &background);	//显示背景图
		mciSendString("open 飞机大战图片音乐素材\\战败(defeat).mp3 alias demusic", NULL, 0, NULL);
		mciSendString("play demusic", NULL, 0, NULL);
		settextcolor(RGB(188, 143, 143));									//输出结束语
		settextstyle(50, 22, _T("黑体"));					//
		sprintf_s(s, size * 2, "游戏结束.分数:%-3d", score);	//
		outtextxy(20, high / 2 - 100 , s);					//
		EndBatchDraw();				//刷新画布
		Sleep(2000);				//延时画面
		closegraph();				//关闭画布
		exit(0);					//结束
	}
	if (last.isdefeat == 1) {				//-------胜利-------------------修改游戏结束积分
		setfillcolor(BLACK);
		bar(0, 0, 400, 600);		//矩形清屏
		mciSendString("open 飞机大战图片音乐素材\\胜利(victory).mp3 alias vimusic", NULL, 0, NULL);
		mciSendString("play vimusic", NULL, 0, NULL);
		TCHAR s[size]="You Win!";
		putimage(0, 0, &background);//显示背景图
		settextcolor(RGB(0, 255, 127));		//输出结束语
		settextstyle(50, 22, _T("黑体"));//
		outtextxy(120, high / 2 - 100, s);//
		EndBatchDraw();				//刷新画布
		Sleep(5000);				//延时画面
		closegraph();				//关闭画布
		exit(0);					//结束
	}
}

void enemyexplodevoice() {			//敌机爆炸声效
	mciSendString("close enemyexplodemusic", NULL, 0, NULL);
	mciSendString("open 飞机大战图片音乐素材\\敌机爆炸.mp3 alias enemyexplodemusic", NULL, 0, NULL);
	mciSendString("play enemyexplodemusic", NULL, 0, NULL);
}

void drawscore(int sco) {	//显示分数
	TCHAR s[size];
	setbkmode(TRANSPARENT);			//消除字体背景黑色
	settextcolor(RGB(65, 105, 225));//字体颜色
	sprintf_s(s, size, "分数:%-3d", sco);
	outtextxy(width / 3 + 35, high - 30, s);
}

void addenemy() {					//增加一个敌机
	enemy[enemynum].type = rand() % 3 + 1;
	switch (enemy[enemynum].type) {
	case 1: {enemy[enemynum].extraspeed = 0; enemy[enemynum].life = 4; break; }//额外速度 
	case 2: {enemy[enemynum].extraspeed = 1.4; enemy[enemynum].life = 1; break; }//额外速度 
	case 3: {enemy[enemynum].extraspeed = 0.4; enemy[enemynum].life = 2; break; }//额外速度 
	}
	enemy[enemynum].y = -(rand() % 200 + 100);
	enemy[enemynum++].x = rand() % 350;
}

void updateenemyposition(int i) {	//更新损毁的敌机位置  传入敌机下标
	enemy[i].type = rand() % 3 + 1;
	switch (enemy[i].type) {
	case 1: {enemy[i].extraspeed = 0; enemy[i].life = 4; break; }//额外速度 
	case 2: {enemy[i].extraspeed = 1.4; enemy[i].life = 1; break; }//额外速度 
	case 3: {enemy[i].extraspeed = 0.4; enemy[i].life = 2; break; }//额外速度 
	}
	enemy[i].y = -(rand() % 200 + 100);
	enemy[i].x = rand() % 350;
}

void isenemyattack(int j,int type) {	//判断敌机是否攻击 敌机数组的下标 敌机种类
	int is;//j : 敌机在数组中的下标 type : 敌机的累心
	is = rand() % 300 + 1;
	//第二类：小飞机 不发射攻击
	if (is == 66 && enemyattackinterval[j] == 0) {
		//敌机发射子弹--------------------
	//	mciSendString("close enemyattackmusic", NULL, 0, NULL);
	//	mciSendString("open C:\\Users\\lenovo\\Desktop\\飞机大战图片音乐素材\\冷枪.mp3 alias enemyattackmusic", NULL, 0, NULL);
	//	mciSendString("play enemyattackmusic", NULL, 0, NULL);
		enemyattackinterval[j] = delayedtime * 3;//敌机攻击间隔重置
		enemybullet[enemybulletnum].enemytype = type;//敌机类型
		enemybullet[enemybulletnum].x = enemy[j].x;//子弹坐标
		enemybullet[enemybulletnum++].y = enemy[j].y;
		
	}
}

void drawblood() {	//显示玩家血条
	setlinecolor(GREEN);
	rectangle(45, high - 28, 126, high - 14);
	int left = 48;
	setfillcolor(GREEN);
	for (int i = 0; i < blood; i++) {
		if (i < valueoflife)
			setfillcolor(GREEN);
		else
			setfillcolor(WHITE);
		bar(left, high - 26, left + 10, high - 16);
		left += 13;
	}
}

void drawenemyblood(int num) {	//显示敌人血量
	int w, h, bloodtype, leftblood, bloodlength;
	switch(enemy[num].type){
	case 1:w = 23; h = 10; bloodtype = 4;  bloodlength = 60; break;
	case 2:w = 8; h = -10; bloodtype = 1; bloodlength = 30; break;
	case 3:w = 10; h = 0; bloodtype = 2; bloodlength = 50; break;
	}
	setlinecolor(RED);
	setfillcolor(RED);
	leftblood = (int)(bloodlength / bloodtype)*enemy[num].life;
	rectangle((int)(enemy[num].x + w), (int)(enemy[num].y + h), (int)(enemy[num].x + w + bloodlength), (int)(enemy[num].y + h + 8));
	bar((int)(enemy[num].x + w), (int)(enemy[num].y + h + 2), (int)(enemy[num].x + w + leftblood), (int)(enemy[num].y + h + 8 - 2));
}

void drawbulletnum() {	//显示子弹缓冲
	int i, left=247;
	setlinecolor(RGB(255, 0, 0));
	rectangle(245, high - 28, 366, high - 14);
	for (i = 0; i < bulletnum; i++) {
		if (bulletnum <= 15)
			setfillcolor(RGB(255, 215, 0));
		else
			setfillcolor(RGB(105 + bulletnum * 5, 0, 0));
		bar(left, high - 26, left + 2, high - 16);
		left += 4;
	}
}

void startinterface() {	//游戏开始界面处理
	MOUSEMSG m;
	int time = 30;	//让 箭头变化 和 音乐 更自然----设定时间间隔
	putimage(0, 0, &startbackground);	//显示开始背景图
	putimage(width / 2 - 10, high / 2, &startbutton_p, NOTSRCERASE);//按钮遮罩图
	putimage(width / 2 - 10, high / 2, &startbutton, SRCINVERT);
	FlushBatchDraw();
	while (1)
	{
		time--;//箭头变化频率
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE) {		//飞机移动
			play.x = m.x;
			play.y = m.y;
		}
		if (play.x > width / 2 - 10 && play.x<width / 2 + 20 && play.y>high / 2 && play.y < high / 2 + 30) {
			if (time < 1) {		//鼠标移到箭头  音乐 和 图片变化
				putimage(0, 0, &startbackground);	//显示开始背景图
				putimage(width / 2 - 17, high / 2, &startbutton_x_p, NOTSRCERASE);//按钮遮罩图
				putimage(width / 2 - 17, high / 2, &startbutton_x, SRCINVERT);
				FlushBatchDraw();
				mciSendString("close mousemovemusic", NULL, 0, NULL);
				mciSendString("open 飞机大战图片音乐素材\\mouseover.wav alias mousemovemusic", NULL, 0, NULL);
				mciSendString("play mousemovemusic", NULL, 0, NULL);
				time = 30;
			}
			if (m.uMsg == WM_LBUTTONDOWN) {
				mciSendString("close buttonmusic", NULL, 0, NULL);
				mciSendString("open 飞机大战图片音乐素材\\mousedown.wav alias buttonmusic", NULL, 0, NULL);
				mciSendString("play buttonmusic", NULL, 0, NULL);
				break;
			}
		}
		else {		//鼠标不在箭头  箭头变回来
			putimage(0, 0, &startbackground);	//显示开始背景图
			putimage(width / 2 - 10, high / 2, &startbutton_p, NOTSRCERASE);//按钮遮罩图
			putimage(width / 2 - 10, high / 2, &startbutton, SRCINVERT);
			FlushBatchDraw();
		}
	}
}

void initboos() {	//初始化boss
	last.eixt = 1;
	enemynum = 0;
	addenemy();//BOSS存的时候增加一个敌机
	last.isready = 0;
	last.allblood = last.curblood = 200;
	enemyappearspeed = 6;//降低难度
	last.xdirection = rand() % 2 + 1;//1左 2右
	last.ydirection = 1;
	bossstackinterval = delayedtime;
}

void bossevent() {	//boss 移动
	if (last.isready == 0 || superatacklast>0)
		return;
	double speed = 0.5;
	if (last.xdirection == 1 && last.x > -50) {
		last.x-= speed;
		if (last.x <= 127)//中间位置纵向换向
			last.y += speed*last.ydirection;
		else
			last.y -= speed*last.ydirection;
		if (last.x <= -50)//横向换向
			last.xdirection = 2;
	}
	if (last.xdirection == 2 && last.x < 288) {
		last.x += speed;
		if (last.x >= 127)//中间位置纵向换向
			last.y += speed*last.ydirection;
		else
			last.y -= speed*last.ydirection;
		if (last.x >= 288)//横向换向
			last.xdirection = 1;
	}
}

void drawbossblood() {	//显示BOSS血条
	int leftblood;
	int w = 5;
	int h = 0;
	setlinecolor(RED);
	setfillcolor(RED);
	leftblood = (int)(150*last.curblood / last.allblood);
	rectangle((int)(last.x + w), (int)(last.y + h), (int)(last.x + w + 150), (int)(last.y + h + 8));
	bar((int)(last.x + w), (int)(last.y + h + 2), (int)(last.x + w + leftblood), (int)(last.y + h + 8 - 2));
}

void isbossbehit() {	//BOSS是否中弹
	int i;
	int w, h;
	w = 160;
	h = 180;
	for (i = 0; i < bulletnum; i++) {
		if (bullet[i].x > last.x && bullet[i].x<last.x + w && bullet[i].y>last.y + 50 && bullet[i].y < last.y + h) {
			mciSendString("close hitenemymusic", NULL, 0, NULL);
			mciSendString("open 飞机大战图片音乐素材\\敌机中弹.mp3 alias hitenemymusic", NULL, 0, NULL);
			mciSendString("play hitenemymusic", NULL, 0, NULL);
			//显示子弹特效处理
			for (int hitenemy = 0; hitenemy < size * 3; hitenemy++) {
				if (hiteffect[hitenemy].delaytime == 0) {
					hiteffect[hitenemy].delaytime = delayedtime * 1;
					hiteffect[hitenemy].x = bullet[i].x;
					hiteffect[hitenemy].y = bullet[i].y;
					break;//别忘了
				}
			}
			updatebullet(i);					//更新子弹 数组内部的位置
			bulletnum--;						//子弹数减一
			last.curblood--;
			i--;							//确实发生玩家子弹消失_退格
			if (last.curblood == 0) {
				last.isdefeat = 1;
				return;
			}	
		}

	}
}

void bossatack() {	//boss攻击
	int atack1 = 0;
	int i;
	if ( last.isready == 0)
		return;
	if(bossstackinterval == 0){//子弹1
		for (i = 0; i < bossbulletnum ; i++) {
			if (bossbullet[i].pr == 0) {
				bossbullet[i].bullettype = 1;
				bossbullet[i].x = last.x + 46 + 70*(atack1);
				bossbullet[i].y = last.y + 120;
				bossstackinterval = delayedtime * 3;
				bossbullet[i].pr = 1;
				atack1++;
				if (atack1 == 2)
					break;
			}	
		}
	}
	//大招
	if (last.curblood <= last.allblood*1.0 / 5 && bosssuperatack == 0 && superatacklast != -1) {
		superatackready--;
		superatacklast = delayedtime * 5;//仅为了不使boss在缓冲时移动
		if (superatackready != 0)//大招缓冲
			return;
		for (i = 0; i < bossbulletnum; i++) {
			if (bossbullet[i].pr == 0) {
				bossbullet[i].bullettype = 3;
				bossbullet[i].x = last.x + 38;
				bossbullet[i].y = last.y + 110;
				bossbullet[i].pr = 1;
				bosssuperatack = 1;
				break;
	     		}
		}
	}
}

int isbosscrashplayer(double x, double y) {//判断boss的一个角 是不是和玩家重叠
	if (x > play.x - 40 && x<play.x + 40 && y>play.y - 40 && y < play.y + 40)
		return 1;
	return 0;
}

void bosshitplayer() {	//BOSS击中玩家
	int w = 0;
	int h = 0;
	//boss撞击玩家处理
	if (isbosscrashplayer(last.x + 20, last.y + 20) || isbosscrashplayer(last.x + 130, last.y + 20) || isbosscrashplayer(last.x + 30, last.y + 100) || isbosscrashplayer(last.x + 120, last.y + 100) || isbosscrashplayer(last.x + 75, last.y + 60))
		valueoflife = 0;
	//boss子弹击中处理
	for (int i = 0; i < bossbulletnum; i++) {
		if (bossbullet[i].pr == 0)
			return;
		switch (bossbullet[i].bullettype) {
		case 1:w = 15; h = 45; break;
		case 3:w = 0; h = 0; break;
		}
		//先处理大招 ：子弹3
		if (bossbullet[i].bullettype == 3 && bossbullet[i].x + 80 > play.x - 35 + w && bossbullet[i].x < play.x + 30 + w && bosssuperatack == 1 && bossbullet[i].y < play.y - 35) {
			ishurt = delayedtime * 2;			//玩家飞机被击短时间显示	
			valueoflife--;						//中弹生命减少
			continue;
		}//处理子弹1 和 2
		if (bossbullet[i].x > play.x - 35 - w && bossbullet[i].x < play.x + 35 + w -3 && bossbullet[i].y > play.y - 35 - h && bossbullet[i].y < play.y + 35) {
			bossbullet[i].pr = 0;
			mciSendString("close playerhurtmusic", NULL, 0, NULL);
			mciSendString("open 飞机大战图片音乐素材\\子弹擦边.mp3 alias playerhurtmusic", NULL, 0, NULL);
			mciSendString("play playerhurtmusic", NULL, 0, NULL);
			ishurt = delayedtime * 2;			//玩家飞机被击短时间显示	
			valueoflife--;						//中弹生命减少
		}
	}
}