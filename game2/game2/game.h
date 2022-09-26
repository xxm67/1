
//头文件
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//定义变量
#define ROWS 11
#define COLS 11
#define ROW 9
#define COL 9
#define Easy_Count 10

//函数的声明

//初始化棋盘
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);

//打印棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);

//布置雷
void SetMine(char board[ROWS][COLS], int row, int col);

//排查雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);