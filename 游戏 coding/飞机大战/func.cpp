#include"��ͷ.h"
#pragma comment(lib,"winmm.lib")//����Windows Multimedia API

IMAGE startbackground;					    	//��ʼʱ����ͼ
IMAGE startbutton, startbutton_p;				//��ʼ��ť
IMAGE startbutton_x, startbutton_x_p;			//��ʼ��ť��ת
IMAGE background;								//����ͼƬ
IMAGE enemy_q1, enemy_p1,bomenemy_q1,bomenemy_p1;	//�л�1ͼƬ
IMAGE enemy_q2, enemy_p2, bomenemy_q2, bomenemy_p2;	//�л�2ͼƬ
IMAGE enemy_q3, enemy_p3, bomenemy_q3, bomenemy_p3;	//�л�3ͼƬ
IMAGE bullet_q, bullet_p;						//��ҷɻ��ӵ�ͼƬ
IMAGE enbullet_q, enbullet_p;					//�л��ӵ�
IMAGE remain_q, remain_p,remain_q2,remain_p2,remain_q3,remain_p3;//�к�ͼƬ
IMAGE reward_q, reward_p;						//�ӵ���ͼƬ
IMAGE reward_2q, reward_2p;						//�ӵ���2ͼƬ
IMAGE supplyhelp_q, supplyhelp_p;				//������ͼƬ
IMAGE player_q0, player_p0;						//��ҷɻ�ͼƬ
IMAGE bulleteffect_q, bulleteffect_p;			//����ӵ�����Ч��ͼ
IMAGE boss_q, boss_p;							//bossͼ
IMAGE bossbt1_q, bossbt1_p;						//boss�ӵ�1ͼ
IMAGE bossbt3_q, bossbt3_p;						//3


position play;				//�������
eposition enemy[size];	//�л�----�޸�����
int enemynum = 0;			//�л�����
double enemyspeed = 0.5;	//�л��ٶ�
int enemyappearinterval[size];//�л�λ��ˢ�¼����¼
int enemyappearspeed = 3;	//�л����ּ��
bposition bullet[size * 3];	//��ǰ�ӵ�������---�޸�����30
int bulletinterval = delayedtime * 2;//����ӵ�������
bposition enemybullet[size * 2];//�л���ǰ�ӵ�������---�޸�����
int enemyattackinterval[size * 2] = { 0 };//�л��������
int score = 0;				//�÷���
int bulletnum = 0;			//�����е�����ӵ���
int enemybulletnum = 0;		//�����ел����ӵ���
double bulletspeed = 1;		//�ӵ��ٶ�
int firepower = 1;			//�ɻ�����
int firerows = 1;			//�ɻ���������
int valueoflife = blood;	//�������ֵ
awardposition reward[3];				//�ӵ�������
int havehelped = 0;			//������ֻ��һ��
int isrewardsave[3] = { 0 };		//ըҩ������ �� ��1
int ishurt = 0;				//��ҷɻ�������ʱ����ʾ
rposition enemydietime[size];//�л��к���Ŀ����
playerhit hiteffect[size * 3];		//��һ��ел���Чλ�ô洢
int score10 = 10, score15 = 15, score50 = 50, score70 = 70;	//�÷ִ���
boss last;//BOSS
int bossstackinterval;//boss�ӵ��������
bposition bossbullet[size * 2];//boss�ӵ�
int bossbulletnum = size * 2;//boss�ӵ���
int bosssuperatack = 0;//boss�����Ƿ����ͷ�
int superatacklast = 0;//boss���г���ʱ����
int superatackready = 20 * size;//����ǰ�Ļ���


void startinterface();				//��ʾ��Ϸ��ʼ����
void isdie();						//�������õл�λ��
void updatebullet(int pr);			//�ӵ������ڲ�λ������
void drawscore(int);				//��ʾ����
void gameover();					//��Ϸ��������
void addenemy();					//����һ���л�
void updateenemyposition(int i);	//������ٵĵл�λ��
void enemyexplodevoice();			//�л���ը��Ч
void updateenemybullet(int pr);		//���µл��ӵ�������λ��
void isenemyattack(int j, int type);//�жϵл��Ƿ񹥻� �л�������±� �л�����
void drawblood();					//��ʾ���Ѫ��
void drawenemyblood(int i);			//��ʾ�л�Ѫ��
void drawbulletnum(); 				//��ʾ�ӵ�����
void initboos();					//��ʼ��boss
void bossevent();					//boss�¼�
void drawbossblood();				//BOSSѪ��
void isbossbehit();					//BOSS�Ƿ��е�
void bossatack();					//boss�Ƿ񹥻�
void bosshitplayer();				//boss�������

void loadimg() {					//����ͼƬ
	loadimage(&startbackground, "�ɻ���սͼƬ�����ز�\\first.jpg");		//��ʼ����
	loadimage(&startbutton, "�ɻ���սͼƬ�����ز�\\resume.jpg");		//�����ΰ�ť
	loadimage(&startbutton_p, "�ɻ���սͼƬ�����ز�\\resume3.jpg");		
	loadimage(&startbutton_x, "�ɻ���սͼƬ�����ز�\\resume_x.jpg");	//��ת�����ΰ�ť
	loadimage(&startbutton_x_p, "�ɻ���սͼƬ�����ز�\\resume2_x.jpg");
	loadimage(&background, "�ɻ���սͼƬ�����ز�\\background2.jpg");	//��Ϸ����
	loadimage(&player_q0, "�ɻ���սͼƬ�����ز�\\player_0.jpg");		//��ҷɻ�
	loadimage(&player_p0, "�ɻ���սͼƬ�����ز�\\player_00.jpg");
	loadimage(&enemy_q1, "�ɻ���սͼƬ�����ز�\\enemyPlane2.jpg");		//���˷ɻ�1
	loadimage(&enemy_p1, "�ɻ���սͼƬ�����ز�\\enemyPlane1.jpg");
	loadimage(&bomenemy_q1, "�ɻ���սͼƬ�����ز�\\npc_3.jpg");		//���˷ɻ�1�к�
	loadimage(&bomenemy_p1, "�ɻ���սͼƬ�����ز�\\npc_33.jpg");
	loadimage(&enemy_q2, "�ɻ���սͼƬ�����ز�\\enemy1.jpg");		//���˷ɻ�2
	loadimage(&enemy_p2, "�ɻ���սͼƬ�����ز�\\enemy11.jpg");
	loadimage(&bomenemy_q2, "�ɻ���սͼƬ�����ز�\\enemy1die_1.jpg");		//���˷ɻ�2�к�
	loadimage(&bomenemy_p2, "�ɻ���սͼƬ�����ز�\\enemy1die_11.jpg");
	loadimage(&enemy_q3, "�ɻ���սͼƬ�����ز�\\enemy2.jpg");		//���˷ɻ�3
	loadimage(&enemy_p3, "�ɻ���սͼƬ�����ز�\\enemy22.jpg");
	loadimage(&bomenemy_q3, "�ɻ���սͼƬ�����ز�\\enemy2die_1.jpg");		//���˷ɻ�3�к�
	loadimage(&bomenemy_p3, "�ɻ���սͼƬ�����ز�\\enemy2die_11.jpg");
	loadimage(&bullet_q, "�ɻ���սͼƬ�����ز�\\bullet44.jpg");			//�ӵ�1
	loadimage(&bullet_p, "�ɻ���սͼƬ�����ز�\\bullet33.jpg");
	loadimage(&enbullet_q, "�ɻ���սͼƬ�����ز�\\bullet22.jpg");			//�ӵ�1
	loadimage(&enbullet_p, "�ɻ���սͼƬ�����ز�\\bullet11.jpg");
	loadimage(&reward_q, "�ɻ���սͼƬ�����ز�\\award_1.jpg");			//�ӵ���
	loadimage(&reward_p, "�ɻ���սͼƬ�����ز�\\award_1p.jpg");
	loadimage(&reward_2q, "�ɻ���սͼƬ�����ز�\\award_2.jpg");			//�ӵ���2
	loadimage(&reward_2p, "�ɻ���սͼƬ�����ز�\\award_2p.jpg");
	loadimage(&supplyhelp_q, "�ɻ���սͼƬ�����ز�\\������.jpg");			//������
	loadimage(&supplyhelp_p, "�ɻ���սͼƬ�����ز�\\������_p.jpg");
	loadimage(&remain_q2, "�ɻ���սͼƬ�����ز�\\player_1.jpg");		//��ҷɻ����1
	loadimage(&remain_p2, "�ɻ���սͼƬ�����ز�\\player_11.jpg");
	loadimage(&remain_q3, "�ɻ���սͼƬ�����ز�\\player_2.jpg");		//��ҷɻ����2
	loadimage(&remain_p3, "�ɻ���սͼƬ�����ز�\\player_22.jpg");
	loadimage(&remain_q, "�ɻ���սͼƬ�����ز�\\player_3.jpg");			//��ҷɻ����3
	loadimage(&remain_p, "�ɻ���սͼƬ�����ز�\\player_33.jpg");
	loadimage(&bulleteffect_q, "�ɻ���սͼƬ�����ز�\\�ӵ�Ч��.jpg");			//��ҷɻ����3
	loadimage(&bulleteffect_p, "�ɻ���սͼƬ�����ز�\\�ӵ�Ч��_p.jpg");
	loadimage(&boss_q, "�ɻ���սͼƬ�����ز�\\boss.jpg");			//boss
	loadimage(&boss_p, "�ɻ���սͼƬ�����ز�\\boss_p.jpg");
	loadimage(&bossbt1_q, "�ɻ���սͼƬ�����ز�\\bossbullet1.jpg");			//boss�ӵ�1
	loadimage(&bossbt1_p, "�ɻ���սͼƬ�����ز�\\bossbullet1_p.jpg");
	loadimage(&bossbt3_q, "�ɻ���սͼƬ�����ز�\\bossbullet3.jpg");			//boss�ӵ�3
	loadimage(&bossbt3_p, "�ɻ���սͼƬ�����ز�\\bossbullet3_p.jpg");
	BeginBatchDraw();
}

void loadmsc() {				//��������open C:\\Users\\lenovo\\Desktop
	mciSendString("open �ɻ���սͼƬ�����ز�\\game_music.mp3 alias bkmusic", NULL, 0, NULL);
	mciSendString("play bkmusic repeat", NULL, 0, NULL);
}
	
void initplay() {				
	int i;//ѭ������
	play.x = width / 2;	//��ʼ�����
	play.y = high / 2;
	for (i = 0; i < size; i++)	//��ʼ���л��к�����ʱ��
		enemydietime[i].time = 0;
	for (i = 0; i < size * 3; i++) {	//��ʼ����һ��ел���Ч���ڱ��
		hiteffect[i].delaytime = 0;
	}

	last.isdefeat = 0;//BOSS״̬��ʼ��
	last.x = rand() % 230;
	last.y = -400;
	last.eixt = 0;
	for (i = 0; i < bossbulletnum; i++)
		bossbullet[i].pr = 0;

	reward[0].y = reward[1].y = reward[2].y = -200;	//�ӵ�����ʼ������ʾ
	addenemy();					//��ʼ��һ���л�
};

void start() {						//��ʼ��
	loadmsc();						//��������
	srand((unsigned int)time(NULL));//ʱ���������
	initgraph(width, high);			//��ʼ������
	loadimg();						//װ����ͼ
	initplay();						//��ʼ�����
	startinterface();				//��ʼ����
}

void show() {						//��ʾ����
	int i;
	putimage(0, 0, &background);	//��ʾ����ͼ
	if (ishurt <= 0) {//�ɻ�ԭͼ
		putimage(play.x - 50, play.y - 50, &player_p0, NOTSRCERASE);	//�ɻ�����ͼ
		putimage(play.x - 50, play.y - 50, &player_q0, SRCINVERT);	//�ɻ�ԭͼ
	}
	else {//�ɻ�������
		putimage(play.x - 48, play.y - 50, &remain_p2, NOTSRCERASE);		//�ɻ�����������ͼ
		putimage(play.x - 48, play.y - 50, &remain_q2, SRCINVERT);		//�ɻ�������ԭͼ
	}
	if (isrewardsave[0] != 0) {//�ӵ���1
		putimage((int)reward[0].x, (int)reward[0].y, &reward_p, NOTSRCERASE);	//�ӵ�������ͼ
		putimage((int)reward[0].x, (int)reward[0].y, &reward_q, SRCINVERT);	//�ӵ���ԭͼ
	}
	if (isrewardsave[1] != 0) {//�ӵ���2
		putimage((int)reward[1].x, (int)reward[1].y, &reward_2p, NOTSRCERASE);	//�ӵ���2����ͼ
		putimage((int)reward[1].x, (int)reward[1].y, &reward_2q, SRCINVERT);	//�ӵ���2ԭͼ
	}
	if (isrewardsave[2] != 0) {//������
		putimage((int)reward[2].x, (int)reward[2].y, &supplyhelp_p, NOTSRCERASE);	//�ӵ���2����ͼ
		putimage((int)reward[2].x, (int)reward[2].y, &supplyhelp_q, SRCINVERT);	//�ӵ���2ԭͼ
	}
	for (i = 0; i < enemynum; i++) {//��ʾ���ел�   
		drawenemyblood(i);				//��ʾ�л�Ѫ��
		if (enemyappearinterval[i] > 0) {	//������Ķ�ʱ�䲻����
			enemyappearinterval[i]--;
			if (enemyappearinterval[i] == 0)
				updateenemyposition(i);
			else
				continue;
		}
		switch (enemy[i].type) {
		case 1: {
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_p1, NOTSRCERASE);	//�л�����ͼ
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_q1, SRCINVERT);	//�л�ԭͼ
			break;
		}
		case 2: {
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_p2, NOTSRCERASE);	//�л�����ͼ
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_q2, SRCINVERT);	//�л�ԭͼ
			break;
		}
		case 3: {
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_p3, NOTSRCERASE);	//�л�����ͼ
			putimage((int)enemy[i].x, (int)enemy[i].y, &enemy_q3, SRCINVERT);	//�л�ԭͼ
			break;
		}
		}
		
	}
	for (i = 0; i < size; i++) {	//��ʾ���ел��к�
		if (enemydietime[i].time > 0) {
			switch (enemydietime[i].dietype) {
			case 1: {
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_p1, NOTSRCERASE);//�л��к�����ͼ
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_q1, SRCINVERT);
				break;
			}
			case 2: {
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_p2, NOTSRCERASE);//�л��к�����ͼ
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_q2, SRCINVERT);
				break;
			}
			case 3: {
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_p3, NOTSRCERASE);//�л��к�����ͼ
				putimage((int)enemydietime[i].x, (int)enemydietime[i].y, &bomenemy_q3, SRCINVERT);
				break;
			}
			}
		}
	}
	for (i = 0; i < size * 3; i++) {//��ʾ�ӵ����ел���Ч
		if (hiteffect[i].delaytime > 0) {
			putimage((int)hiteffect[i].x - 34, (int)hiteffect[i].y - 98, &bulleteffect_p, NOTSRCERASE);		//�ɻ�����������ͼ
			putimage((int)hiteffect[i].x - 34, (int)hiteffect[i].y - 98, &bulleteffect_q, SRCINVERT);		//�ɻ�������ԭͼ
		}
	}
	for (i = 0; i < bulletnum; i++) {	//��ʾ��������ӵ�
		putimage((int)bullet[i].x - 3, (int)bullet[i].y - 60, &bullet_p, NOTSRCERASE);//�ӵ�����ͼ
		putimage((int)bullet[i].x - 3, (int)bullet[i].y - 60, &bullet_q, SRCINVERT);//�ӵ�ԭͼ
	}
	int width_1, high_1;
	for (i = 0; i < enemybulletnum; i++) {//��ʾ���ел��ӵ�
		switch (enemybullet[i].enemytype) {	//��Բ�ͬ�л� ��ͬ���ӵ�ʶ������
		case 1:width_1 = 50, high_1 = 150; break;
		case 2:width_1 = 22, high_1 = 40; break;
		case 3:width_1 = 33, high_1 = 90; break;
		}
		putimage((int)enemybullet[i].x + width_1, (int)enemybullet[i].y + high_1, &enbullet_p, NOTSRCERASE);//�ӵ�����ͼ
		putimage((int)enemybullet[i].x + width_1, (int)enemybullet[i].y + high_1, &enbullet_q, SRCINVERT);//�ӵ�ԭͼ
	}
	if (last.eixt == 1) {		//��ʾboss
		drawbossblood();//��ʾѪ��
		putimage((int)last.x, (int)last.y, &boss_p, NOTSRCERASE);//boss����ͼ
		putimage((int)last.x, (int)last.y, &boss_q, SRCINVERT);//bossԭͼ
		int i;
		for (i = 0; i < bossbulletnum; i++) {//��ʾboss�ӵ�
			if (bossbullet[i].pr == 0)
				continue;
			switch (bossbullet[i].bullettype) {
			case 1: {//1
				putimage((int)bossbullet[i].x, (int)bossbullet[i].y, &bossbt1_p, NOTSRCERASE);//boss�ӵ�1����ͼ
				putimage((int)bossbullet[i].x, (int)bossbullet[i].y, &bossbt1_q, SRCINVERT);//boss�ӵ�1ԭͼ
				break;
			}
			case 3: {//3������
				if (superatacklast > 0) {
					putimage((int)bossbullet[i].x, (int)bossbullet[i].y, &bossbt3_p, NOTSRCERASE);//boss�ӵ�2����ͼ
					putimage((int)bossbullet[i].x, (int)bossbullet[i].y, &bossbt3_q, SRCINVERT);//boss�ӵ�2ԭͼ
				}
				break;
			}
			}
		}
	}
	drawscore(score);						//��ʾ����
	drawblood();							//��ʾ�������ֵ
	drawbulletnum();						//��ʾ����ӵ�����
	FlushBatchDraw();						//ˢ�»���
	Sleep(3);								//����ˢ�¼��
}

void updatewithoutinput() {			//����� ���� �޹�
	int i;//����ѭ��
	if (ishurt>0)		//��ҷɻ�������ʱ����ʾ
		ishurt--;

	//BOSS����
	if (last.eixt == 1 && last.y < 10 && last.isready==0) {
		last.y += 0.3;
		if (last.y >= 10)
			last.isready = 1;
	}
	if (last.eixt == 1) {
		if (bossstackinterval > 0)//boss�������
			bossstackinterval--;
		bossevent();//boss�
		isbossbehit();//boss�Ƿ��е�
		bossatack();	//boss����
		bosshitplayer();//boss�������
		for (int i = 0; i < bossbulletnum; i++) {
			if (bossbullet[i].pr == 0 || bossbullet[i].bullettype == 3)
				continue;
			if (bossbullet[i].y < 650)	//boss�ӵ�����
				bossbullet[i].y+=1.2;
			if (bossbullet[i].y >= 650)	//boss�ӵ�����
				bossbullet[i].pr = 0;
		}
		if (bosssuperatack == 1) {
			superatacklast--;
			if (superatacklast == 0) {
				bosssuperatack = 0;
				superatacklast = -1;//�Ѿ��Ź���
			}
		}
	}

	for (i = 0; i < 3; i++) {	//���������� ���� 3��
		if (isrewardsave[i] != 0)
			reward[i].y++;
	}
	for (i = 0; i < enemynum; i++) {//�л��ƶ�
		if (enemyappearinterval[i] == 0)
			enemy[i].y = enemy[i].y + enemy[i].extraspeed + enemyspeed;	
	}
	for (i = 0; i < bulletnum; i++) {
		bullet[i].y -= bulletspeed;			//����ӵ��ƶ�
		bullet[i].x += bullet[i].pr*0.3;	//�����ӵ���Ŀ�γ�ɢ��_ɢ�����
	}
	for (i = 0; i < enemybulletnum; i++)//�л��ӵ��ƶ�
		enemybullet[i].y += (bulletspeed*0.7 + enemyspeed + enemy[i].extraspeed);
	for (i = 0; i < enemynum; i++)	//��ÿ���л��ж��Ƿ����ӵ�
		if (enemyappearinterval[i] == 0 && enemy[i].type != 2)
			isenemyattack(i, enemy[i].type);	//�жϵл��Ƿ񹥻� �л�������±� �л�����
	for (i = 0; i < size; i++) 		//�л��к����ڴ���
		if (enemydietime[i].time > 0)
			enemydietime[i].time--;
	for (i = 0; i < enemynum; i++) {//�л��ٴγ��ּ������
		if (enemyattackinterval[i] > 0)
			enemyattackinterval[i]--;
	}
	for (i = 0; i < size * 3; i++) {//��һ��ел���Ч���ִ���
		if (hiteffect[i].delaytime>0)
			hiteffect[i].delaytime--;
	}

	isdie();						//�������� �л����ӵ������� λ��
	gameover();						//��Ϸ����
}

void updatewithinput() {					//����� ���� �й�
	static int time = 50;				//�ӵ�������������ֹ�����ʼ��ĵ�һ���ӵ�
	MOUSEMSG m;
	while (MouseHit()) {
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE) {		//�ɻ��ƶ�
			play.x = m.x;
			play.y = m.y;
		}
		else if (m.uMsg = WM_LBUTTONDOWN && time < 1 && (bulletnum + firepower*firerows < size * 3)) {//�����ӵ� ��� �ӵ�δ��
			mciSendString("close fgmusic", NULL, 0, NULL);
			mciSendString("open �ɻ���սͼƬ�����ز�\\f_gun.mp3 alias fgmusic", NULL, 0, NULL);
			mciSendString("play fgmusic", NULL, 0, NULL);
			double y = 0;//���y���� 0.5 -1 1.5 -2 2.5...��ȡ�� �� ��ʾ�Էɻ�Ϊ���ĵ������ӵ�
			for (int i = 0; i < firepower; i++) {
				y = fabs(y) + 0.5;//�ӵ����䷽������
				if (i % 2 == 1)
					y *= -1;
				else
					y = fabs(y);
				for (int row = 0; row < firerows; row++) {
					bullet[bulletnum].pr = (int)y;		//�����ӵ����򹥻�����
					if (firepower % 2 == 0)//ż��
						if ((int)y >= 0)
							bullet[bulletnum].pr += 1;	//ż���ӵ�ɢ����ʽ
					bullet[bulletnum].x = play.x + 10 * (int)y;		//ɢ��
					bullet[bulletnum++].y = play.y + row * 20;		//����
				}
			}
			time = bulletinterval;	//�ӵ�����������Ϊͨ��ֵ
		}
	}
	time--;							//�ӵ�������
}

void scoretoaction() {						//����һ�ܷɻ� �� ��������ָ���� ���� ��ض���
	if (score >= 180 && last.eixt == 0) {//BOSS���ַ�������
		initboos();//��ʼ��BOSS
	}
	if (score <= 0)
		return;
	if (score >=score10) {
		if (enemyspeed < 1.0)	//�����ٶȸ���
			enemyspeed += 0.10;									
		if (enemyappearspeed > 2)	//�л����ָ���
			enemyappearspeed--;
		score10 *= 2;
	}
	if (score >= score50) {
		if (enemynum < 4 && last.eixt==0)
			addenemy();//����һ���л�
		score50 *= 2;
	}
	if (score >= score15) {					//----����----�޸�
		if (bulletinterval > 40)
			bulletinterval -= 10;				//�ӵ�����������
		if (isrewardsave[0] == 0 && firepower <5) {			//�����ӵ���1_ɢ��_�޸�����
			isrewardsave[0] = 1;
			reward[0].x = rand() % 350;
			reward[0].y = -(rand() % 100 + 100);
		}
		if (bulletspeed != 5)
			bulletspeed += 0.5;					//�ӵ��ٶȸ���
		score15 *= 2;
	}
	if (score >= score70) {
		if (isrewardsave[1] == 0 && firerows < 2) {				//�����ӵ���2_����_�޸�����
			isrewardsave[1] = 1;
			reward[1].x = rand() % 350;
			reward[1].y = -(rand() % 100 + 100);
		}
//		mciSendString("close lemusic", NULL, 0, NULL);
		mciSendString("open �ɻ���սͼƬ�����ز�\\����.mp3 alias lemusic", NULL, 0, NULL);
		mciSendString("play lemusic", NULL, 0, NULL);
		score70 *= 2;
	}
	if (isrewardsave[2] == 0 && valueoflife	<=3 && havehelped == 0) {			//���䲹��_�޸�����
		havehelped = 1;
		isrewardsave[2] = 1;
		reward[2].x = rand() % 350;
		reward[2].y = -(rand() % 100 + 100);
	}
}

void isdie() {									//�������� �л� �� �ӵ� �� �ӵ���λ��
	int ismissbullet;							//����ӵ��Ƿ���ʧ
	int ismissenemybullet;						//�л��ӵ��Ƿ���ʧ
	int i, k;
	for (i = 0; i < enemynum; i++) {		//�л� ���紦��
		if (enemy[i].y > 660) {		
			//���ݻٵл���һ�γ��ּ���趨
			enemyappearinterval[i] = delayedtime * enemyappearspeed;
			enemy[i].y = -300;//���ݻٵл���ʱ��Żر�ĵط�
			enemy[i].x = -300;
			valueoflife--;			//��������
		}
	}
	for (i = 0; i < enemybulletnum; i++) {	//�л� �ӵ���ʧ ����	
		//�жϵл���ʧ�������������ӵ�Խ��
		ismissenemybullet = 0;
		if (enemybullet[i].y > 650) {			//�л��ӵ���ʧ�ж�����
			updateenemybullet(i);				//���µл��ӵ� �����ڲ���λ��
			enemybulletnum--;					//�л��ӵ�����һ
			ismissenemybullet++;				//ȷʵ�����л��ӵ���ʧ
		}
		if (ismissenemybullet > 0) {	//�˸�
			i--;
			continue;
		}
		//�жϵл���ʧ����������������е�	
		int width_1, high_1;
		switch (enemybullet[i].enemytype) {	//��Բ�ͬ�л� ��ͬ���ӵ�ʶ������
		case 1:width_1 = 50, high_1 = 150; break;
		case 2:width_1 = 22, high_1 = 40; break;
		case 3:width_1 = 33, high_1 = 90; break;
		}
		if (enemybullet[i].x + width_1 > play.x - 35 && enemybullet[i].x + width_1 < play.x + 35 && enemybullet[i].y + high_1>play.y - 35 && enemybullet[i].y + high_1< play.y + 35) {
			mciSendString("close playerhurtmusic", NULL, 0, NULL);
			mciSendString("open �ɻ���սͼƬ�����ز�\\�ӵ�����.mp3 alias playerhurtmusic", NULL, 0, NULL);
			mciSendString("play playerhurtmusic", NULL, 0, NULL);
			putimage(play.x - 48, play.y - 50, &remain_p2, NOTSRCERASE);	//�ɻ���������ͼ
			putimage(play.x - 48, play.y - 50, &remain_q2, SRCINVERT);		//�ɻ�����ԭͼ
			ishurt = delayedtime * 2;			//��ҷɻ�������ʱ����ʾ
			valueoflife--;						//�е���������
			updateenemybullet(i);				//���µл��ӵ� �����ڲ���λ��
			enemybulletnum--;					//�л��ӵ�����һ
			ismissenemybullet++;				//ȷʵ�����л��ӵ���ʧ
		}
		if (ismissenemybullet > 0) {	//�˸�
			i--;
			continue;
		}
	}
	//i������ӵ�  k�ǵ���   t�ǵ��˲к�
	int width_1, high_1;
	for (i = 0; i < bulletnum; i++)	{		//��� �ӵ���ʧ ����
		ismissbullet = 0;
		for (k = 0; k < enemynum; k++) {//�ӵ����ел�
			switch (enemy[k].type) {	//��Բ�ͬ�л� ��ͬ���ӵ�ʶ������
			case 1:width_1 = 100, high_1 = 180; break;
			case 2:width_1 = 50, high_1 = 90; break;
			case 3:width_1 = 77, high_1 = 130; break;
			}
			//+6��Ϊ�˺�ͼ�� ʵ��λ�� ����
			if (bullet[i].x + 6 > enemy[k].x && bullet[i].x + 6 < enemy[k].x + width_1 && bullet[i].y > enemy[k].y && bullet[i].y < enemy[k].y + high_1) {
				//��ʾ�ӵ���Ч����
				for (int hitenemy = 0; hitenemy < size * 3; hitenemy++) {
					if (hiteffect[hitenemy].delaytime == 0) {
						hiteffect[hitenemy].delaytime = delayedtime * 1;
						hiteffect[hitenemy].x = bullet[i].x;
						hiteffect[hitenemy].y = bullet[i].y;
						break;//������
					}
				}
				updatebullet(i);					//�����ӵ� �����ڲ���λ��
				bulletnum--;						//�ӵ�����һ
				ismissbullet++;						//ȷʵ��������ӵ���ʧ
				enemy[k].life--;		//�����е� ��������1
				if (enemy[k].life != 0) {//�������û�� �ͷ���������Ч ��������  ȥ������ը��Ч
					mciSendString("close hitenemymusic", NULL, 0, NULL);
					mciSendString("open �ɻ���սͼƬ�����ز�\\�л��е�.mp3 alias hitenemymusic", NULL, 0, NULL);
					mciSendString("play hitenemymusic", NULL, 0, NULL);
					goto aim2;//�ӵ����ел� �л����˱����ӵ��жϽ��� ��ת1
				}
				for (int t = 0; t < size; t++)	//�ҵ������һ�γ��ֵл������λ��_��ʾ�л��к�
				{
					if (enemydietime[t].time == 0) {
						enemydietime[t].x = enemy[k].x;//����λ�� ���� ���˲к�����
						enemydietime[t].y = enemy[k].y;
						enemydietime[t].dietype = enemy[k].type;
						enemydietime[t].time = delayedtime;//�ӳ�ʱ��
						break;//������
					}
				}
				enemyexplodevoice();			//�л���ը��Ч
				//���ݻٵл���һ�γ��ּ���趨
				enemyappearinterval[k] = delayedtime * enemyappearspeed;
				enemy[k].y = -300;				//���ݻٵл���ʱ��Żر�ĵط�
				enemy[k].x = -300;
				switch (enemy[k].type) {		//��ҵ÷�
				case 1:score += 3; break;
				case 2:score++; break;
				case 3:score += 2; break;
				}
				scoretoaction();				//��������ָ���� ���� ��ض���
				goto aim2;//�ӵ����ел� �л���ը �����ӵ��жϽ��� ��ת2
			}
		}
		if (bullet[i].y < -10) {	//����ӵ���ʧ��������Խ��
			updatebullet(i);					//�����ӵ� �����ڲ���λ��
			bulletnum--;						//�ӵ�����һ
			ismissbullet++;						//ȷʵ��������ӵ���ʧ
		}
aim2:		;//��ת
		if(ismissbullet>0)
			i--;			//�˻�ȥ
	}
	//�ӵ� �ӵ��� ��ǿ��ҩ ���� �ӵ����Զ����ջ�
	for (i = 0; i < 3; i++) {
		if ((((play.x) - (reward[i].x + 33))*((play.x) - (reward[i].x + 33)) + ((play.y) - (reward[i].y + 45))*((play.y) - (reward[i].y + 45)) < 4500) || reward[i].y>650) {
			if (reward[i].y <= 650) {	//�ӵ��ӵ��� ǿ���ӵ�Ч��
				switch (i){	
				case 0:firepower++; break;
				case 1:firerows++; break;
				case 2:valueoflife += 3; break;
				}
				mciSendString("close rewardmusic", NULL, 0, NULL);
				mciSendString("open �ɻ���սͼƬ�����ز�\\gotreward.mp3 alias rewardmusic", NULL, 0, NULL);
				mciSendString("play rewardmusic", NULL, 0, NULL);
			}
			reward[i].y = -200;	//�ӵ���λ������
			isrewardsave[i] = 0;//��������
		}
	}
}

void updatebullet(int pr) {						//�����ӵ� �����ڲ���λ��
	for (int i = pr; i < bulletnum - 1; i++)
		bullet[i] = bullet[i + 1];
}

void updateenemybullet(int pr) {				//���µл��ӵ� �����ڵ�λ��
	for (int i = pr; i < enemybulletnum - 1; i++)
		enemybullet[i] = enemybullet[i + 1];
}

void gameover() {						//��Ϸ��������
	int width_1, high_1, length_1;
	for (int i = 0; i < enemynum; i++) {//�жϷ��� ��ײ
		switch (enemy[i].type) {	//��Բ�ͬ�л� ��ͬ����ײʶ������
		case 1:width_1 = 50, high_1 = 80; length_1 = 7400; break;
		case 2:width_1 = 25, high_1 = 20; length_1 = 2700; break;
		case 3:width_1 = 33, high_1 = 47; length_1 = 4700; break;
		}
		if (((enemy[i].x + width_1) - (play.x))*((enemy[i].x + width_1) - (play.x)) + ((enemy[i].y + high_1) - (play.y))*((enemy[i].y + high_1) - (play.y)) < length_1) {
			if (enemy[i].type == 2)
			{
				//��forѭ��������ʾײ����ҵ�С�ɻ��к� �Լ� ˢ���´�λ��
				for (int t = 0; t < size; t++)	//�ҵ������һ�γ��ֵл������λ��_��ʾ�л��к�
				{
					if (enemydietime[t].time == 0) {
						enemydietime[t].x = enemy[i].x;
						enemydietime[t].y = enemy[i].y;
						enemydietime[t].dietype = enemy[i].type;
						enemydietime[t].time = delayedtime;//�ӳ�ʱ��
						enemyexplodevoice();			//�л���ը��Ч
						enemyappearinterval[i] = delayedtime * enemyappearspeed;
						enemy[i].y = -300;				//���ݻٵл���ʱ��Żر�ĵط�
						enemy[i].x = -300;
						break;
					}
				}
				valueoflife -= 3;			//ײ��С�ɻ�
				ishurt = delayedtime * 4;					//��ײ��ʾ
			}
			else
				valueoflife = 0;			//���Ѫ��
		}	
	}
	if (valueoflife <= 0)												//ʧ��---���ݻ�
	{
		TCHAR s[size * 2];
		mciSendString("close bkmusic", NULL, 0, NULL);					//�ر�����
		drawblood();								//��ʾ��Ѫ��
													//��ײ�ٻ���Ч
		mciSendString("open �ɻ���սͼƬ�����ز�\\explode.mp3 alias exmusic", NULL, 0, NULL);
		mciSendString("play exmusic", NULL, 0, NULL);
		putimage(play.x - 48, play.y - 50, &remain_p2, NOTSRCERASE);		//�ɻ��к�����ͼ1
		putimage(play.x - 48, play.y - 50, &remain_q2, SRCINVERT);		//�ɻ��к�ԭͼ1
		FlushBatchDraw();
		Sleep(80);
		putimage(play.x - 47, play.y - 48, &remain_p3, NOTSRCERASE);		//�ɻ��к�����ͼ2
		putimage(play.x - 47, play.y - 48, &remain_q3, SRCINVERT);		//�ɻ��к�ԭͼ2
		FlushBatchDraw();				//ˢ�»���
		Sleep(210);
		putimage(play.x - 48, play.y - 50, &remain_p, NOTSRCERASE);		//�ɻ��к�����ͼ3
		putimage(play.x - 48, play.y - 50, &remain_q, SRCINVERT);		//�ɻ��к�ԭͼ3
		FlushBatchDraw();

		Sleep(1000);						//��ͣ����
		putimage(0, 0, &background);	//��ʾ����ͼ
		mciSendString("open �ɻ���սͼƬ�����ز�\\ս��(defeat).mp3 alias demusic", NULL, 0, NULL);
		mciSendString("play demusic", NULL, 0, NULL);
		settextcolor(RGB(188, 143, 143));									//���������
		settextstyle(50, 22, _T("����"));					//
		sprintf_s(s, size * 2, "��Ϸ����.����:%-3d", score);	//
		outtextxy(20, high / 2 - 100 , s);					//
		EndBatchDraw();				//ˢ�»���
		Sleep(2000);				//��ʱ����
		closegraph();				//�رջ���
		exit(0);					//����
	}
	if (last.isdefeat == 1) {				//-------ʤ��-------------------�޸���Ϸ��������
		setfillcolor(BLACK);
		bar(0, 0, 400, 600);		//��������
		mciSendString("open �ɻ���սͼƬ�����ز�\\ʤ��(victory).mp3 alias vimusic", NULL, 0, NULL);
		mciSendString("play vimusic", NULL, 0, NULL);
		TCHAR s[size]="You Win!";
		putimage(0, 0, &background);//��ʾ����ͼ
		settextcolor(RGB(0, 255, 127));		//���������
		settextstyle(50, 22, _T("����"));//
		outtextxy(120, high / 2 - 100, s);//
		EndBatchDraw();				//ˢ�»���
		Sleep(5000);				//��ʱ����
		closegraph();				//�رջ���
		exit(0);					//����
	}
}

void enemyexplodevoice() {			//�л���ը��Ч
	mciSendString("close enemyexplodemusic", NULL, 0, NULL);
	mciSendString("open �ɻ���սͼƬ�����ز�\\�л���ը.mp3 alias enemyexplodemusic", NULL, 0, NULL);
	mciSendString("play enemyexplodemusic", NULL, 0, NULL);
}

void drawscore(int sco) {	//��ʾ����
	TCHAR s[size];
	setbkmode(TRANSPARENT);			//�������屳����ɫ
	settextcolor(RGB(65, 105, 225));//������ɫ
	sprintf_s(s, size, "����:%-3d", sco);
	outtextxy(width / 3 + 35, high - 30, s);
}

void addenemy() {					//����һ���л�
	enemy[enemynum].type = rand() % 3 + 1;
	switch (enemy[enemynum].type) {
	case 1: {enemy[enemynum].extraspeed = 0; enemy[enemynum].life = 4; break; }//�����ٶ� 
	case 2: {enemy[enemynum].extraspeed = 1.4; enemy[enemynum].life = 1; break; }//�����ٶ� 
	case 3: {enemy[enemynum].extraspeed = 0.4; enemy[enemynum].life = 2; break; }//�����ٶ� 
	}
	enemy[enemynum].y = -(rand() % 200 + 100);
	enemy[enemynum++].x = rand() % 350;
}

void updateenemyposition(int i) {	//������ٵĵл�λ��  ����л��±�
	enemy[i].type = rand() % 3 + 1;
	switch (enemy[i].type) {
	case 1: {enemy[i].extraspeed = 0; enemy[i].life = 4; break; }//�����ٶ� 
	case 2: {enemy[i].extraspeed = 1.4; enemy[i].life = 1; break; }//�����ٶ� 
	case 3: {enemy[i].extraspeed = 0.4; enemy[i].life = 2; break; }//�����ٶ� 
	}
	enemy[i].y = -(rand() % 200 + 100);
	enemy[i].x = rand() % 350;
}

void isenemyattack(int j,int type) {	//�жϵл��Ƿ񹥻� �л�������±� �л�����
	int is;//j : �л��������е��±� type : �л�������
	is = rand() % 300 + 1;
	//�ڶ��ࣺС�ɻ� �����乥��
	if (is == 66 && enemyattackinterval[j] == 0) {
		//�л������ӵ�--------------------
	//	mciSendString("close enemyattackmusic", NULL, 0, NULL);
	//	mciSendString("open C:\\Users\\lenovo\\Desktop\\�ɻ���սͼƬ�����ز�\\��ǹ.mp3 alias enemyattackmusic", NULL, 0, NULL);
	//	mciSendString("play enemyattackmusic", NULL, 0, NULL);
		enemyattackinterval[j] = delayedtime * 3;//�л������������
		enemybullet[enemybulletnum].enemytype = type;//�л�����
		enemybullet[enemybulletnum].x = enemy[j].x;//�ӵ�����
		enemybullet[enemybulletnum++].y = enemy[j].y;
		
	}
}

void drawblood() {	//��ʾ���Ѫ��
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

void drawenemyblood(int num) {	//��ʾ����Ѫ��
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

void drawbulletnum() {	//��ʾ�ӵ�����
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

void startinterface() {	//��Ϸ��ʼ���洦��
	MOUSEMSG m;
	int time = 30;	//�� ��ͷ�仯 �� ���� ����Ȼ----�趨ʱ����
	putimage(0, 0, &startbackground);	//��ʾ��ʼ����ͼ
	putimage(width / 2 - 10, high / 2, &startbutton_p, NOTSRCERASE);//��ť����ͼ
	putimage(width / 2 - 10, high / 2, &startbutton, SRCINVERT);
	FlushBatchDraw();
	while (1)
	{
		time--;//��ͷ�仯Ƶ��
		m = GetMouseMsg();
		if (m.uMsg == WM_MOUSEMOVE) {		//�ɻ��ƶ�
			play.x = m.x;
			play.y = m.y;
		}
		if (play.x > width / 2 - 10 && play.x<width / 2 + 20 && play.y>high / 2 && play.y < high / 2 + 30) {
			if (time < 1) {		//����Ƶ���ͷ  ���� �� ͼƬ�仯
				putimage(0, 0, &startbackground);	//��ʾ��ʼ����ͼ
				putimage(width / 2 - 17, high / 2, &startbutton_x_p, NOTSRCERASE);//��ť����ͼ
				putimage(width / 2 - 17, high / 2, &startbutton_x, SRCINVERT);
				FlushBatchDraw();
				mciSendString("close mousemovemusic", NULL, 0, NULL);
				mciSendString("open �ɻ���սͼƬ�����ز�\\mouseover.wav alias mousemovemusic", NULL, 0, NULL);
				mciSendString("play mousemovemusic", NULL, 0, NULL);
				time = 30;
			}
			if (m.uMsg == WM_LBUTTONDOWN) {
				mciSendString("close buttonmusic", NULL, 0, NULL);
				mciSendString("open �ɻ���սͼƬ�����ز�\\mousedown.wav alias buttonmusic", NULL, 0, NULL);
				mciSendString("play buttonmusic", NULL, 0, NULL);
				break;
			}
		}
		else {		//��겻�ڼ�ͷ  ��ͷ�����
			putimage(0, 0, &startbackground);	//��ʾ��ʼ����ͼ
			putimage(width / 2 - 10, high / 2, &startbutton_p, NOTSRCERASE);//��ť����ͼ
			putimage(width / 2 - 10, high / 2, &startbutton, SRCINVERT);
			FlushBatchDraw();
		}
	}
}

void initboos() {	//��ʼ��boss
	last.eixt = 1;
	enemynum = 0;
	addenemy();//BOSS���ʱ������һ���л�
	last.isready = 0;
	last.allblood = last.curblood = 200;
	enemyappearspeed = 6;//�����Ѷ�
	last.xdirection = rand() % 2 + 1;//1�� 2��
	last.ydirection = 1;
	bossstackinterval = delayedtime;
}

void bossevent() {	//boss �ƶ�
	if (last.isready == 0 || superatacklast>0)
		return;
	double speed = 0.5;
	if (last.xdirection == 1 && last.x > -50) {
		last.x-= speed;
		if (last.x <= 127)//�м�λ��������
			last.y += speed*last.ydirection;
		else
			last.y -= speed*last.ydirection;
		if (last.x <= -50)//������
			last.xdirection = 2;
	}
	if (last.xdirection == 2 && last.x < 288) {
		last.x += speed;
		if (last.x >= 127)//�м�λ��������
			last.y += speed*last.ydirection;
		else
			last.y -= speed*last.ydirection;
		if (last.x >= 288)//������
			last.xdirection = 1;
	}
}

void drawbossblood() {	//��ʾBOSSѪ��
	int leftblood;
	int w = 5;
	int h = 0;
	setlinecolor(RED);
	setfillcolor(RED);
	leftblood = (int)(150*last.curblood / last.allblood);
	rectangle((int)(last.x + w), (int)(last.y + h), (int)(last.x + w + 150), (int)(last.y + h + 8));
	bar((int)(last.x + w), (int)(last.y + h + 2), (int)(last.x + w + leftblood), (int)(last.y + h + 8 - 2));
}

void isbossbehit() {	//BOSS�Ƿ��е�
	int i;
	int w, h;
	w = 160;
	h = 180;
	for (i = 0; i < bulletnum; i++) {
		if (bullet[i].x > last.x && bullet[i].x<last.x + w && bullet[i].y>last.y + 50 && bullet[i].y < last.y + h) {
			mciSendString("close hitenemymusic", NULL, 0, NULL);
			mciSendString("open �ɻ���սͼƬ�����ز�\\�л��е�.mp3 alias hitenemymusic", NULL, 0, NULL);
			mciSendString("play hitenemymusic", NULL, 0, NULL);
			//��ʾ�ӵ���Ч����
			for (int hitenemy = 0; hitenemy < size * 3; hitenemy++) {
				if (hiteffect[hitenemy].delaytime == 0) {
					hiteffect[hitenemy].delaytime = delayedtime * 1;
					hiteffect[hitenemy].x = bullet[i].x;
					hiteffect[hitenemy].y = bullet[i].y;
					break;//������
				}
			}
			updatebullet(i);					//�����ӵ� �����ڲ���λ��
			bulletnum--;						//�ӵ�����һ
			last.curblood--;
			i--;							//ȷʵ��������ӵ���ʧ_�˸�
			if (last.curblood == 0) {
				last.isdefeat = 1;
				return;
			}	
		}

	}
}

void bossatack() {	//boss����
	int atack1 = 0;
	int i;
	if ( last.isready == 0)
		return;
	if(bossstackinterval == 0){//�ӵ�1
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
	//����
	if (last.curblood <= last.allblood*1.0 / 5 && bosssuperatack == 0 && superatacklast != -1) {
		superatackready--;
		superatacklast = delayedtime * 5;//��Ϊ�˲�ʹboss�ڻ���ʱ�ƶ�
		if (superatackready != 0)//���л���
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

int isbosscrashplayer(double x, double y) {//�ж�boss��һ���� �ǲ��Ǻ�����ص�
	if (x > play.x - 40 && x<play.x + 40 && y>play.y - 40 && y < play.y + 40)
		return 1;
	return 0;
}

void bosshitplayer() {	//BOSS�������
	int w = 0;
	int h = 0;
	//bossײ����Ҵ���
	if (isbosscrashplayer(last.x + 20, last.y + 20) || isbosscrashplayer(last.x + 130, last.y + 20) || isbosscrashplayer(last.x + 30, last.y + 100) || isbosscrashplayer(last.x + 120, last.y + 100) || isbosscrashplayer(last.x + 75, last.y + 60))
		valueoflife = 0;
	//boss�ӵ����д���
	for (int i = 0; i < bossbulletnum; i++) {
		if (bossbullet[i].pr == 0)
			return;
		switch (bossbullet[i].bullettype) {
		case 1:w = 15; h = 45; break;
		case 3:w = 0; h = 0; break;
		}
		//�ȴ������ ���ӵ�3
		if (bossbullet[i].bullettype == 3 && bossbullet[i].x + 80 > play.x - 35 + w && bossbullet[i].x < play.x + 30 + w && bosssuperatack == 1 && bossbullet[i].y < play.y - 35) {
			ishurt = delayedtime * 2;			//��ҷɻ�������ʱ����ʾ	
			valueoflife--;						//�е���������
			continue;
		}//�����ӵ�1 �� 2
		if (bossbullet[i].x > play.x - 35 - w && bossbullet[i].x < play.x + 35 + w -3 && bossbullet[i].y > play.y - 35 - h && bossbullet[i].y < play.y + 35) {
			bossbullet[i].pr = 0;
			mciSendString("close playerhurtmusic", NULL, 0, NULL);
			mciSendString("open �ɻ���սͼƬ�����ز�\\�ӵ�����.mp3 alias playerhurtmusic", NULL, 0, NULL);
			mciSendString("play playerhurtmusic", NULL, 0, NULL);
			ishurt = delayedtime * 2;			//��ҷɻ�������ʱ����ʾ	
			valueoflife--;						//�е���������
		}
	}
}