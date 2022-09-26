#include "game.h"

//��ӡ�˵�
void menu() {
	printf("---------------------------------\n");
	printf("--------1.��ʼ��Ϸ      ---------\n");
	printf("--------0.�˳���Ϸ      ---------\n");
	printf("---------------------------------\n");
}

//��Ϸ��ʵ��
void game() {
	//��������
	char mine[ROWS][COLS];
	char show[ROWS][COLS];

	//��ʼ������
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');

	//��ӡ����
	//DisplayBoard(mine, ROW, COL);
	DisplayBoard(show, ROW, COL);

	//������
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	
	//�Ų���
	FindMine(mine, show, ROW, COL);
	
}
int main(){
	int input = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input) {
		case 1:
			game();
		case 0:
			printf("�˳��ɹ�");
			break;
		default:
			printf("�����������������\n");
		}
	} while (input);
}

