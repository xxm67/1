#include "game.h"

//打印菜单
void menu() {
	printf("---------------------------------\n");
	printf("--------1.开始游戏      ---------\n");
	printf("--------0.退出游戏      ---------\n");
	printf("---------------------------------\n");
}

//游戏的实现
void game() {
	//定义棋盘
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	//初始化棋盘
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//打印棋盘
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//布置雷
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	
	//排查雷
	FindMine(mine, show, ROW, COL);
	
}
int main(){
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
		case 0:
			printf("退出成功");
			break;
		default:
			printf("输入错误，请重新输入\n");
		}
	} while (input);
}

