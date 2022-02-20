#include<stdio.h>
#include<time.h>//�������������ʳ��
#include<conio.h>//������������
#include<windows.h>//Ϊ��ʹ��gotoxy(����ƶ�����)
//��(������ͼ��ʳ��) ��(��ͷ) ��(����)
#define MAP_MODE "��"
#define SNAKE_HEAD "��"
#define SNAKE_BODY "��"
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
struct Food{//ʳ��ṹ��
	int x;
	int y;
}food;
struct Snake{//�ߵĽṹ��
	int x[MAXLEN];
	int y[MAXLEN];
	int currentLen;//��ǰ�ߵĳ��� x[0],y[0] ->��ͷ
}snake;
int direct = 'a';
int flag = 1;//�Ƿ���Ҫ����ʳ��
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
			//�ı���λ�ã�ʹ�䲻Ӱ������
			gotoxy(96, 0);
			exit(0);
		}
	}

	return 0;
}
void createMap(){
	for (int i = 0 + MOVE_CENTER; i <MAP_WIDTH + MOVE_CENTER; i += 2){//���±�
		gotoxy(i, 0);//�ı�x��y����->������һ����
		printf(MAP_MODE);

		gotoxy(i, MAP_HEIGHT-1);//�ı�x��y����->������һ����
		printf(MAP_MODE);
	}

	for (int i = 0; i <MAP_HEIGHT; i++){//���±�
		gotoxy(0 + MOVE_CENTER, i);//�ı�y��x����->������һ����
		printf(MAP_MODE);

		gotoxy(MAP_WIDTH + MOVE_CENTER, i);//�ı�y��x����->������һ����
		printf(MAP_MODE);
	}
	//�ı���λ�ã�ʹ�䲻Ӱ������
	gotoxy(96, 0);

	//��ʼ����
	initSnake();
}
void createFood(){
	//�������ʳ��
	srand(time(NULL));//�������
	int isCreate = 1;//��ʾʳ���Ƿ���Ա�����
	food.x = rand() % (MAP_WIDTH - 4 + 2) + MOVE_CENTER;
	food.y = rand() % (MAP_HEIGHT - 1 + 1);

	if (food.x % 2 == 0){//����x����Ϊż��
		//ʳ������겻�����ߵ�����
		for (int i = 0; i < snake.currentLen; i++){
			if (snake.x[i] == food.x && snake.y[i] == food.y){
				isCreate = 0;
			}

			if (isCreate){
				gotoxy(food.x, food.y);
				printf(MAP_MODE);
				flag = 0;
				//�ı���λ�ã�ʹ�䲻Ӱ������
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

	//��ѭ����ӡ����������ӵ���ͷ�ĺ���
	for (int i = 1; i < snake.currentLen; i++){
		snake.x[i] = snake.x[i - 1] + 2;
		snake.y[i] = snake.y[i - 1];

		gotoxy(snake.x[i], snake.y[i]);
		printf(SNAKE_BODY);
	}

	//�ı���λ�ã�ʹ�䲻Ӱ������
	gotoxy(96, 0);


}
void moveSnake(){

	if (_kbhit()){//������������
		fflush(stdin);
		direct = _getch();
	}

	//�������һ����β
	gotoxy(snake.x[snake.currentLen - 1], snake.y[snake.currentLen - 1]);
	printf("  ");

	//��ʼ�滻���꣬�ƶ���
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

	//�ƶ�֮������ͷ��λ��
	gotoxy(snake.x[0], snake.y[0]);
	printf(SNAKE_HEAD);

	//�ı���λ�ã�ʹ�䲻Ӱ������
	gotoxy(96, 0);

	//�ж���ͷ�������Ƿ��ʳ�����
	if (snake.x[0] == food.x && snake.y[0] == food.y){
		snake.currentLen++;
		flag = 1;
	}

}
int statement(){//�ж���Ϸ��ǰ��״̬
	//�ж���ͷ�Ƿ�ײ��ǽ��
	if (snake.x[0] == 0 + MOVE_CENTER || snake.x[0] == MAP_WIDTH + MOVE_CENTER || snake.y[0] == 0 || snake.y[0] == MAP_HEIGHT - 1){
		return 1;
	}
	//��ͷ�Ե��Լ���������ⲿλ

	for (int i = 1; i < snake.currentLen; i++){
		if (snake.x[0] == snake.x[i] && snake.y[0] == snake.y[i]){
			return 1;
		}
	}
	return 0;
}
void gotoxy(int x, int y){//ϵͳ��������
	COORD pos = { x, y };
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleCursorPosition(hOut, pos);
}