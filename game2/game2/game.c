#include "game.h"
//函数的实现

//初始化棋盘
//mine-----'0'
//show-----'*'
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set) {
	int i = 0, j = 0;
	printf("\n");
	for (i = 0; i < ROWS; i++) {
		for (j = 0; j < COLS ; j++) {
			board[i][j] = set;//如果是'set'打印出来是t,上面已定义set是char类型的
		}
	}
}


//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col) {
	int i = 0, j = 0;
	for (i = 0; i <= row; i++) {
		printf("%d   ", i);
	}
	printf("\n");
	for (i = 1; i <= row; i++) {
		printf("%d |", i);
		for (j = 1; j <= col; j++) {
			printf("_%c_|", board[i][j]);
			if (j == row) {
				printf("\b|");
			}
		}
		printf("\n");
	}
	printf("\n");
}

//布置雷
//有雷------'1'
//无雷------'0'
void SetMine(char board[ROWS][COLS], int row, int col) {
	int cnt = Easy_Count;
	while (cnt > 0) {
		int x = rand() % row + 1;
		int y = rand() % col + 1;
		if (board[x][y] == '0') {
			board[x][y] = '1';
			 cnt--;
		}
	}

}

//剩余雷数
int get_mine_count(char mine[ROWS][COLS], int x, int y) {
	return
		mine[x - 1][y - 1] + mine[x - 1][y] +
		mine[x - 1][y + 1] + mine[x][y - 1] +
		mine[x][y + 1] + mine[x + 1][y - 1] +
		mine[x + 1][y] + mine[x + 1][y + 1] - 8 * '0';//结果是一个整数, 不是字符
}

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col) {
	int x = 0;
	int y = 0;
	int cnt = 0;
	while (1) {
		printf("请输入坐标;>");
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col) {
			if (mine[x][y] == '1') {
				printf("\n很遗憾, 你被炸死了!\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else {
				show[x][y] = get_mine_count(mine, x, y) + 48;//+48把整数转换为字符
				DisplayBoard(show, ROW, COL);
				cnt++;
			}
		}
		else {
			printf("\n输入错误, 请重新输入\n");
		}
		if (cnt == row * col - Easy_Count) {
			printf("恭喜你, 扫雷成功!\n");
			break;
		}
	}
}

