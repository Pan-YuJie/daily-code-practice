#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<windows.h>
#include<time.h>
#include<graphics.h>//图形文件
#include<mmsystem.h>//多媒体设备接口文件（音乐）

#pragma comment(lib,"winmm.lib")//加载多媒体设备接口文件（音乐）库
#define WIN_WIDTH 1000//画布长
#define WIN_HEIGHT 600//画布宽
#define SIZE 40//墙尺寸
#define ROW (WIN_HEIGHT/SIZE)
#define COL (WIN_WIDTH/SIZE)
#define BRICK_MUN 350//砖块数
#define NPC_NUM 5//怪物数
#define NUM_ENEMY 2//人机数


enum MAP //地图
{
	SPACE,
	WALL,
	BRICK
};
struct PLAYER {
	int x = 0;
	int y = 0;
	int Speed = 1;
	int  move = 0;
	int state = 1;
	int move_x = 0;
	int move_y = 0;
}player1, en[NUM_ENEMY];
struct NPC {
	int x = 0;
	int y = 0;
	int iskilled = 1;
	int Speed = 1;
	int move_x = 1;
	int move_y = 0;

}npc[NPC_NUM];
struct BOOM {
	int x = 0;
	int y = 0;
	int exist = 0;
}boom[NUM_ENEMY];
int MAP[ROW][COL] = { 0 };
time_t t1 = 0, t2 = 0;
int boom1_x = 0, boom1_y = 0, exist1 = 0;//炸弹有关
int over = 0;
int X = 0, Y = 0;//随机位置
int choose = 0;
int count = 0;

IMAGE bk;
IMAGE Brick;
IMAGE Wall;
IMAGE chara[2];
IMAGE monster[2];
IMAGE explore[2];
IMAGE gameover[2];
IMAGE enemy[2];
void welcome();
void GameInit();
void GameDraw();
void UpdateWithInput();
void UpdateWithoutInput();
void NPC();
void GameOver();
void Enemy();

int main()
{
	initgraph(WIN_WIDTH, WIN_HEIGHT);
	welcome();
	GameInit();
	BeginBatchDraw();
	do {
		if (over == -1) {
			for (int i = 0; i < ROW; i++) {
				for (int j = 0; j < COL; j++) {
					MAP[i][j] = SPACE;
				}
			}
			exist1 = 0;
			count = 0;
			GameOver();
			GameInit();
			BeginBatchDraw();
			over = 0;
		}
		FlushBatchDraw();
		GameDraw();
		UpdateWithInput();
		UpdateWithoutInput();
		NPC();
		if (choose) {
			Enemy();
		}
	} while (over != 1);
	mciSendString("close MUSIC", 0, 0, 0);
	GameOver();
	return 0;
}
void welcome()
{
	loadimage(&bk, "./images/game_begin.jpg", WIN_WIDTH, WIN_HEIGHT);
	putimage(0, 0, &bk);
	mciSendString("open ./images/music.aac alias MUSIC", 0, 0, 0);
	mciSendString("play MUSIC repeat", 0, 0, 0);
	_getch();
	mciSendString("close MUSIC", 0, 0, 0);
}
void GameInit()
{
	mciSendString("open ./images/music.aac alias MUSIC", 0, 0, 0);
	mciSendString("play MUSIC repeat", 0, 0, 0);
	loadimage(&Wall, "./images/Wall.jpg", SIZE, SIZE);
	loadimage(&Brick, "./images/Brick.jpg", SIZE, SIZE);
	loadimage(&chara[0], "./images/char1.jpg");
	loadimage(&chara[1], "./images/char2.jpg");
	loadimage(&monster[0], "./images/monster1.jpg");
	loadimage(&monster[1], "./images/monster2.jpg");
	//墙的位置
	for (int i = 0; i < ROW; i++) {
		MAP[i][0] = WALL;
		MAP[i][COL - 1] = WALL;
	}
	for (int j = 0; j < COL; j++) {
		MAP[0][j] = WALL;
		MAP[ROW - 1][j] = WALL;
	}
	for (int i = 2; i < ROW - 1; i = i + 2) {
		for (int j = 2; j < COL - 1; j = j + 2) {
			MAP[i][j] = WALL;
		}
	}
	//砖的位置
	srand((unsigned int)time(0));
	for (int i = 0; i < BRICK_MUN; i++) {
		int x = rand() % ROW;
		int y = rand() % COL;
		if (MAP[x][y] == SPACE) {
			MAP[x][y] = BRICK;
		}
	}
	//玩家位置
	do {
		X = rand() % ROW;
		Y = rand() % COL;
		player1.x = Y * SIZE;
		player1.y = X * SIZE;
	} while (MAP[X][Y] != SPACE);
	if (MAP[X][Y + 1] == BRICK) {
		MAP[X][Y + 1] = SPACE;
	}
	if (MAP[X][Y - 1] == BRICK) {
		MAP[X][Y - 1] = SPACE;
	}
	if (MAP[X + 1][Y] == BRICK) {
		MAP[X + 1][Y] = SPACE;
	}
	if (MAP[X - 1][Y] == BRICK) {
		MAP[X - 1][Y] = SPACE;
	}
	//怪物位置
	for (int i = 0; i < NPC_NUM; i++) {
		do {
			X = rand() % ROW;
			Y = rand() % COL;
			npc[i].x = Y * SIZE;
			npc[i].y = X * SIZE;
		} while (MAP[X][Y] != SPACE || npc[i].x / SIZE == player1.x / SIZE || npc[i].y / SIZE == player1.y / SIZE);
	}
	for (int i = 0; i < NUM_ENEMY; i++) {
		do {
			X = rand() % ROW;
			Y = rand() % COL;
			en[i].x = Y * SIZE;
			en[i].y = X * SIZE;
		} while (MAP[X][Y] != SPACE || en[i].x / SIZE == player1.x / SIZE || en[i].y / SIZE == player1.y / SIZE);
	}
}
void GameDraw()
{
	setbkcolor(RGB(80, 160, 1));//背景颜色
	cleardevice();
	//生成地图
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COL; j++) {
			switch (MAP[i][j]) {
			case WALL:
				putimage(j * SIZE, i * SIZE, &Wall);
				break;
			case BRICK:
				putimage(j * SIZE, i * SIZE, &Brick);
				break;
			}
		}
	}
	switch (player1.state) {
	case 0: {
		putimage(player1.x, player1.y, 30, 30, &chara[1], 0, 0, NOTSRCERASE);
		putimage(player1.x, player1.y, 30, 30, &chara[0], 0, 0, SRCINVERT);
		break;
	}
	case 1: {
		putimage(player1.x, player1.y, 30, 30, &chara[1], 0, 30, NOTSRCERASE);
		putimage(player1.x, player1.y, 30, 30, &chara[0], 0, 30, SRCINVERT);
		break;
	}
	case 2: {
		putimage(player1.x, player1.y, 30, 30, &chara[1], 0, 60, NOTSRCERASE);
		putimage(player1.x, player1.y, 30, 30, &chara[0], 0, 60, SRCINVERT);
		break;
	}
	case 3: {
		putimage(player1.x, player1.y, 30, 30, &chara[1], 0, 150, NOTSRCERASE);
		putimage(player1.x, player1.y, 30, 30, &chara[0], 0, 150, SRCINVERT);
		break;
	}
	}
}
void UpdateWithInput()
{
	if (GetAsyncKeyState(VK_UP) && 0x8000) {
		if (MAP[(player1.y - player1.Speed) / SIZE][player1.x / SIZE] == SPACE && MAP[(player1.y - player1.Speed) / SIZE][(player1.x + 30) / SIZE] == SPACE)
			player1.y -= player1.Speed;
		player1.state = 1;
		player1.move++;
		putimage(player1.x, player1.y, 30, 30, &chara[1], player1.move * 30, 30, NOTSRCERASE);
		putimage(player1.x, player1.y, 30, 30, &chara[0], player1.move * 30, 30, SRCINVERT);
		Sleep(1);
		if (player1.move == 3)
			player1.move = 0;
	}
	if (GetAsyncKeyState(VK_DOWN) && 0x8000) {
		if (MAP[(player1.y + player1.Speed + 30) / SIZE][player1.x / SIZE] == SPACE && MAP[(player1.y + player1.Speed + 30) / SIZE][(player1.x + 30) / SIZE] == SPACE)
			player1.y += player1.Speed;
		player1.state = 0;
		player1.move++;
		putimage(player1.x, player1.y, 30, 30, &chara[1], player1.move * 30, 0, NOTSRCERASE);
		putimage(player1.x, player1.y, 30, 30, &chara[0], player1.move * 30, 0, SRCINVERT);
		Sleep(1);
		if (player1.move == 3)
			player1.move = 0;
	}
	if (GetAsyncKeyState(VK_LEFT) && 0x8000) {
		if (MAP[player1.y / SIZE][(player1.x - player1.Speed) / SIZE] == SPACE && MAP[(player1.y + 30) / SIZE][(player1.x - player1.Speed) / SIZE] == SPACE)
			player1.x -= player1.Speed;
		player1.state = 2;
		player1.move++;
		putimage(player1.x, player1.y, 30, 30, &chara[1], player1.move * 30, 60, NOTSRCERASE);
		putimage(player1.x, player1.y, 30, 30, &chara[0], player1.move * 30, 60, SRCINVERT);
		Sleep(1);
		if (player1.move == 3)
			player1.move = 0;
	}
	if (GetAsyncKeyState(VK_RIGHT) && 0x8000) {
		if (MAP[player1.y / SIZE][(player1.x + player1.Speed + 30) / SIZE] == SPACE && MAP[(player1.y + 30) / SIZE][(player1.x + player1.Speed + 30) / SIZE] == SPACE)
			player1.x += player1.Speed;
		player1.state = 3;
		player1.move++;
		putimage(player1.x, player1.y, 30, 30, &chara[1], player1.move * 30, 150, NOTSRCERASE);
		putimage(player1.x, player1.y, 30, 30, &chara[0], player1.move * 30, 150, SRCINVERT);
		Sleep(1);
		if (player1.move == 3)
			player1.move = 0;
	}
	if (GetAsyncKeyState(VK_SPACE) && 0x8000) {
		if (exist1 == 0) {
			exist1 = 1;
			boom1_x = player1.x;
			boom1_y = player1.y;
			t1 = time(NULL);
		}
	}
	Sleep(5);
}
void UpdateWithoutInput()
{
	//炸弹爆炸判定
	loadimage(&explore[0], "./images/explore1.jpg");
	loadimage(&explore[1], "./images/explore2.jpg");
	t2 = time(NULL);
	if (exist1 == 1) {
		switch (t2 - t1) {
		case 0: {
			putimage(boom1_x + 5, boom1_y, 23, 33, &explore[1], 0, 0, NOTSRCERASE);
			putimage(boom1_x + 5, boom1_y, 23, 33, &explore[0], 0, 0, SRCINVERT);
			break;
		}
		case 1: {
			putimage(boom1_x + 6, boom1_y, 24, 33, &explore[1], 23, 0, NOTSRCERASE);
			putimage(boom1_x + 6, boom1_y, 24, 33, &explore[0], 23, 0, SRCINVERT);
			break;
		}
		case 2: {
			putimage(boom1_x + 7, boom1_y, 24, 33, &explore[1], 47, 0, NOTSRCERASE);
			putimage(boom1_x + 7, boom1_y, 24, 33, &explore[0], 47, 0, SRCINVERT);
			break;
		}
		case 3: {
			putimage(boom1_x + 8, boom1_y - 1, 23, 30, &explore[1], 0, 33, NOTSRCERASE);
			putimage(boom1_x + 8, boom1_y - 1, 23, 30, &explore[0], 0, 33, SRCINVERT);
			if (MAP[boom1_y / SIZE + 1][boom1_x / SIZE] != WALL && MAP[boom1_y / SIZE + 1][(boom1_x + 23) / SIZE] != WALL) {
				putimage(boom1_x + 8, boom1_y + 39, 23, 30, &explore[1], 0, 33, NOTSRCERASE);
				putimage(boom1_x + 8, boom1_y + 39, 23, 30, &explore[0], 0, 33, SRCINVERT);
				MAP[boom1_y / SIZE + 1][boom1_x / SIZE] = SPACE;
			}
			if (MAP[boom1_y / SIZE - 1][boom1_x / SIZE] != WALL && MAP[boom1_y / SIZE - 1][(boom1_x + 23) / SIZE] != WALL) {
				putimage(boom1_x + 8, boom1_y - SIZE - 1, 23, 30, &explore[1], 0, 33, NOTSRCERASE);
				putimage(boom1_x + 8, boom1_y - SIZE - 1, 23, 30, &explore[0], 0, 33, SRCINVERT);
				MAP[boom1_y / SIZE - 1][boom1_x / SIZE] = SPACE;
			}
			if (MAP[boom1_y / SIZE][boom1_x / SIZE + 1] != WALL && MAP[(boom1_y + 30) / SIZE][boom1_x / SIZE + 1] != WALL) {
				putimage(boom1_x + SIZE + 8, boom1_y - 1, 23, 30, &explore[1], 0, 33, NOTSRCERASE);
				putimage(boom1_x + SIZE + 8, boom1_y - 1, 23, 30, &explore[0], 0, 33, SRCINVERT);
				MAP[boom1_y / SIZE][boom1_x / SIZE + 1] = SPACE;
			}
			if (MAP[boom1_y / SIZE][boom1_x / SIZE - 1] != WALL && MAP[(boom1_y + 30) / SIZE][boom1_x / SIZE - 1] != WALL) {
				putimage(boom1_x - SIZE + 8, boom1_y - 1, 23, 30, &explore[1], 0, 33, NOTSRCERASE);
				putimage(boom1_x - SIZE + 8, boom1_y - 1, 23, 30, &explore[0], 0, 33, SRCINVERT);
				MAP[boom1_y / SIZE][boom1_x / SIZE - 1] = SPACE;
			}
			break;
		}
		case 4: {
			exist1 = 0;
			break;
		}
		}
		//npc死亡判定
		for (int i = 0; i < NPC_NUM; i++) {
			if (t2 - t1 == 3) {
				if (boom1_y / SIZE + 1 == npc[i].y / SIZE && boom1_x / SIZE == npc[i].x / SIZE) {
					npc[i].iskilled = 0;
				}
				if (boom1_y / SIZE - 1 == npc[i].y / SIZE && boom1_x / SIZE == npc[i].x / SIZE) {
					npc[i].iskilled = 0;
				}
				if (boom1_y / SIZE == npc[i].y / SIZE && boom1_x / SIZE + 1 == npc[i].x / SIZE) {
					npc[i].iskilled = 0;
				}
				if (boom1_y / SIZE == npc[i].y / SIZE && boom1_x / SIZE + 1 == npc[i].x / SIZE) {
					npc[i].iskilled = 0;
				}
				if (boom1_y / SIZE == npc[i].y / SIZE && boom1_x / SIZE == npc[i].x / SIZE) {
					npc[i].iskilled = 0;
				}
			}
		}
		if (choose) {
			if (t2 - t1 == 3) {
				for (int i = 0; i < NUM_ENEMY; i++) {
					if (boom1_y / SIZE + 1 == en[i].y / SIZE && boom1_x / SIZE == en[i].x / SIZE) {
						en[i].state = 0;
					}
					if (boom1_y / SIZE - 1 == en[i].y / SIZE && boom1_x / SIZE == en[i].x / SIZE) {
						en[i].state = 0;
					}
					if (boom1_y / SIZE == en[i].y / SIZE && boom1_x / SIZE + 1 == en[i].x / SIZE) {
						en[i].state = 0;
					}
					if (boom1_y / SIZE == en[i].y / SIZE && boom1_x / SIZE + 1 == en[i].x / SIZE) {
						en[i].state = 0;
					}
					if (boom1_y / SIZE == npc[i].y / SIZE && boom1_x / SIZE == npc[i].x / SIZE) {
						en[i].state = 0;
					}
				}
			}
		}
		//人物与炸弹有关的死亡判定
		if (t2 - t1 == 3) {
			if (boom1_y / SIZE == player1.y / SIZE && boom1_x / SIZE == player1.x / SIZE) {
				over = -1;
			}
			if (boom1_y / SIZE + 1 == player1.y / SIZE && boom1_x / SIZE == player1.x / SIZE) {
				over = -1;
			}
			if (boom1_y / SIZE - 1 == player1.y / SIZE && boom1_x / SIZE == player1.x / SIZE) {
				over = -1;
			}
			if (boom1_x / SIZE - 1 == player1.x / SIZE && boom1_y / SIZE == player1.y / SIZE) {
				over = -1;
			}
			if (boom1_x / SIZE + 1 == player1.x / SIZE && boom1_y / SIZE == player1.y / SIZE) {
				over = -1;
			}
		}
	}
	//人物与敌人有关的死亡判定
	for (int i = 0; i < NPC_NUM; i++) {
		if (npc[i].iskilled) {
			if (npc[i].x / SIZE == player1.x / SIZE && npc[i].y / SIZE == player1.y / SIZE) {
				over = -1;
			}
		}
	}

	if (choose) {
		for (int i = 0; i < NUM_ENEMY; i++) {
			if (en[i].state) {
				if (en[i].x / SIZE == player1.x / SIZE && en[i].y / SIZE == player1.y / SIZE) {
					over = -1;
				}
			}
		}
	}
	//胜利判定
	int npcdeathnumber = 0;
	for (int i = 0; i < NPC_NUM; i++) {
		if (npc[i].iskilled == 0) {
			npcdeathnumber++;
		}
	}
	if (npcdeathnumber == NPC_NUM - 3) {
		choose = 1;
	}
	if (npcdeathnumber == NPC_NUM) {
		over = 1;
	}
}
void NPC()
{
	loadimage(&monster[0], "./images/monster1.jpg");
	loadimage(&monster[1], "./images/monster2.jpg");
	srand((unsigned int)time(0));
	for (int i = 0; i < NPC_NUM; i++) {
		if (npc[i].iskilled) {
			putimage(npc[i].x + 10, npc[i].y + 8, 19, 24, &monster[1], 0, 33, NOTSRCERASE);
			putimage(npc[i].x + 10, npc[i].y + 8, 19, 24, &monster[0], 0, 33, SRCINVERT);
			while (MAP[(npc[i].y + 8 + npc[i].move_y) / SIZE][(npc[i].x + 10 + npc[i].move_x) / SIZE] != SPACE || MAP[(npc[i].y + 8 + npc[i].move_y + 24) / SIZE][(npc[i].x + 10 + npc[i].move_x) / SIZE] != SPACE || MAP[(npc[i].y + 8 + npc[i].move_y + 24) / SIZE][(npc[i].x + 10 + npc[i].move_x + 19) / SIZE] != SPACE || MAP[(npc[i].y + 8 + npc[i].move_y) / SIZE][(npc[i].x + 10 + npc[i].move_x + 19) / SIZE] != SPACE) {
				int direction = rand() % 4;
				switch (direction) {
				case 0: {
					npc[i].move_x = 1;
					npc[i].move_y = 0;
					break;
				}
				case 1: {
					npc[i].move_x = -1;
					npc[i].move_y = 0;
					break;
				}
				case 2: {
					npc[i].move_x = 0;
					npc[i].move_y = 1;
					break;
				}
				case 3: {
					npc[i].move_x = 0;
					npc[i].move_y = -1;
					break;
				}
				}
			}
			npc[i].x += npc[i].move_x;
			npc[i].y += npc[i].move_y;
		}
	}

}
void Enemy()
{
	loadimage(&enemy[0], "./images/enemy1.jpg", SIZE, SIZE);
	loadimage(&enemy[1], "./images/enemy2.jpg", SIZE, SIZE);
	count++;
	for (int i = 0; i < NUM_ENEMY; i++) {
		if (en[i].state) {
			putimage(en[i].x, en[i].y, &enemy[1], NOTSRCERASE);
			putimage(en[i].x, en[i].y, &enemy[0], SRCINVERT);
			if (count % 2) {
				do {
					if (en[i].x % SIZE == 0 && en[i].y % SIZE == 0) {
						int direction = rand() % 2;
						if (direction) {
							if (en[i].x > player1.x) {
								en[i].move_x = -1;
								en[i].move_y = 0;
							}
							else if (en[i].x < player1.x) {
								en[i].move_x = 1;
								en[i].move_y = 0;
							}
							else {
								if (en[i].y > player1.y) {
									en[i].move_x = 0;
									en[i].move_y = -1;
								}
								else if (en[i].y < player1.y) {
									en[i].move_x = 0;
									en[i].move_y = 1;
								}
							}
						}
						else {
							if (en[i].y > player1.y) {
								en[i].move_x = 0;
								en[i].move_y = -1;
							}
							else if (en[i].y < player1.y) {
								en[i].move_x = 0;
								en[i].move_y = 1;
							}
							else {
								if (en[i].x > player1.x) {
									en[i].move_x = -1;
									en[i].move_y = 0;
								}
								else if (en[i].x < player1.x) {
									en[i].move_x = 1;
									en[i].move_y = 0;
								}
							}
						}
					}
				} while (MAP[(en[i].y + en[i].move_y) / SIZE][(en[i].x + en[i].move_x) / SIZE] == WALL || MAP[(en[i].y + en[i].move_y + 39) / SIZE][(en[i].x + en[i].move_x) / SIZE] == WALL || MAP[(en[i].y + en[i].move_y) / SIZE][(en[i].x + en[i].move_x + 39) / SIZE] == WALL || MAP[(en[i].y + en[i].move_y + 39) / SIZE][(en[i].x + en[i].move_x + 39) / SIZE] == WALL);
				en[i].x += en[i].move_x;
				en[i].y += en[i].move_y;
			}
		}
	}

}

void GameOver()
{
	EndBatchDraw();
	loadimage(&gameover[0], "./images/win.jpg", WIN_WIDTH, WIN_HEIGHT);
	loadimage(&gameover[1], "./images/fail.jpg", WIN_WIDTH, WIN_HEIGHT);
	if (over == 1) {
		putimage(0, 0, &gameover[0]);
		Sleep(5000);
	}

	else if (over == -1) {
		putimage(0, 0, &gameover[1]);
		Sleep(5000);
	}
}

