#include<stdio.h>
#include<time.h>//随机种子来出现食物
#include<conio.h>//监听键盘输入
#include<windows.h>//为了使用gotoxy(光标移动函数)
//■(创建地图、食物) ⊙(蛇头) ●(蛇身)
#define MAP_MODE "■"
#define SNAKE_HEAD "⊙"
#define SNAKE_BODY "●"
#define MAP_WIDTH 80
#define MAP_HEIGHT 30
#define MOVE_CENTER 12
#define INITLEN 3
#define MAXLEN 30
void createMap();
void createFood();
void initSnake();
void moveSnake();
int statement();
void gotoxy(int x, int y);
struct Food{//食物结构体
	int x;
	int y;
}food;
struct Snake{//蛇的结构体
	int x[MAXLEN];
	int y[MAXLEN];
	int currentLen;//当前蛇的长度 x[0],y[0] ->蛇头
}snake;
int direct = 'a';
int flag = 1;//是否需要生成食物
int main(){
	createMap();
	//createFood();
	while (1){
		/*createFood();*/
		Sleep(300);
		if (flag){
			createFood();
		}
		moveSnake();
		if (statement()){
			gotoxy(MAP_WIDTH / 2, MAP_HEIGHT / 2);
			printf("Game Over!\n");
			//改变光标位置，使其不影响美观
			gotoxy(96, 0);
			exit(0);
		}
	}

	return 0;
}
void createMap(){
	for (int i = 0 + MOVE_CENTER; i <MAP_WIDTH + MOVE_CENTER; i += 2){//上下边
		gotoxy(i, 0);//改变x，y不变->最上面一条边
		printf(MAP_MODE);

		gotoxy(i, MAP_HEIGHT-1);//改变x，y不变->最下面一条边
		printf(MAP_MODE);
	}

	for (int i = 0; i <MAP_HEIGHT; i++){//上下边
		gotoxy(0 + MOVE_CENTER, i);//改变y，x不变->最左面一条边
		printf(MAP_MODE);

		gotoxy(MAP_WIDTH + MOVE_CENTER, i);//改变y，x不变->最右面一条边
		printf(MAP_MODE);
	}
	//改变光标位置，使其不影响美观
	gotoxy(96, 0);

	//初始化蛇
	initSnake();
}
void createFood(){
	//随机出现食物
	srand(time(NULL));//随机种子
	int isCreate = 1;//表示食物是否可以被创建
	food.x = rand() % (MAP_WIDTH - 4 + 2) + MOVE_CENTER;
	food.y = rand() % (MAP_HEIGHT - 1 + 1);

	if (food.x % 2 == 0){//满足x坐标为偶数
		//食物的坐标不能在蛇的身上
		for (int i = 0; i < snake.currentLen; i++){
			if (snake.x[i] == food.x && snake.y[i] == food.y){
				isCreate = 0;
			}

			if (isCreate){
				gotoxy(food.x, food.y);
				printf(MAP_MODE);
				flag = 0;
				//改变光标位置，使其不影响美观
				gotoxy(96, 0);
			}
		}
	}
}
void initSnake(){
	snake.currentLen = INITLEN;
	snake.x[0] = MAP_WIDTH / 2 + MOVE_CENTER;
	snake.y[0] = MAP_HEIGHT / 2;
	
	gotoxy(snake.x[0], snake.y[0]);
	printf(SNAKE_HEAD);

	//用循环打印出蛇身，蛇身接到蛇头的后面
	for (int i = 1; i < snake.currentLen; i++){
		snake.x[i] = snake.x[i - 1] + 2;
		snake.y[i] = snake.y[i - 1];

		gotoxy(snake.x[i], snake.y[i]);
		printf(SNAKE_BODY);
	}

	//改变光标位置，使其不影响美观
	gotoxy(96, 0);


}
void moveSnake(){

	if (_kbhit()){//监听键盘输入
		fflush(stdin);
		direct = _getch();
	}

	//擦除最后一节蛇尾
	gotoxy(snake.x[snake.currentLen - 1], snake.y[snake.currentLen - 1]);
	printf("  ");

	//开始替换坐标，移动蛇
	for (int i = snake.currentLen - 1; i > 0; i--){
		snake.x[i] = snake.x[i - 1];
		snake.y[i] = snake.y[i - 1];
		gotoxy(snake.x[i], snake.y[i]);
		printf(SNAKE_BODY);
	}

	switch (direct){
	case 'w':
	case 'W':
		snake.y[0]--;
		break;

	case 's':
	case 'S':
		snake.y[0]++;
		break;

	case 'a':
	case 'A':
		snake.x[0]-=2;
		break;

	case 'd':
	case 'D':
		snake.x[0] += 2;
		break;
	}

	//移动之后，新蛇头的位置
	gotoxy(snake.x[0], snake.y[0]);
	printf(SNAKE_HEAD);

	//改变光标位置，使其不影响美观
	gotoxy(96, 0);

	//判断蛇头的坐标是否和食物相等
	if (snake.x[0] == food.x && snake.y[0] == food.y){
		snake.currentLen++;
		flag = 1;
	}

}
int statement(){//判断游戏当前的状态
	//判断蛇头是否撞到墙壁
	if (snake.x[0] == 0 + MOVE_CENTER || snake.x[0] == MAP_WIDTH + MOVE_CENTER || snake.y[0] == 0 || snake.y[0] == MAP_HEIGHT - 1){
		return 1;
	}
	//蛇头吃到自己身体的任意部位

	for (int i = 1; i < snake.currentLen; i++){
		if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i]){
			return 1;
		}
	}
	return 0;
}
void gotoxy(int x, int y){//系统辅助函数
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}