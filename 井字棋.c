#include "game.h"

int rang = 1;

void menu() {
	printf("-----------------------------------\n");
	printf("========  tic tac toe   ===========\n");
	printf("########  1.one player  ###########\n");
	printf("########  2.two player  ###########\n");
	printf("########  0.exit        ###########\n");
	printf("-----------------------------------\n");
}

void game_one() {
	//�洢���� - ��ά����
	char board[ROW][COL];
	//��ʼ������-��ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);
	//��ӡ����-��ӡ��������
	DayinBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
	//�˻�����
	while (1) 
	{
		//�жϻغ�
		printf("RANGE %d\n",rang);
		//�������
		Player1Move(board,ROW,COL);
		DayinBoard(board, ROW, COL);
		//�ж�����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'c') 
			break;
		system("cls");
		//��������
		ComMove(board, ROW, COL);
		DayinBoard(board, ROW, COL);
		//�жϵ����Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		rang++;
	}
	if (ret == 'o')
		printf("���Ӯ��\n");
	else if (ret == 'x') 
		printf("����Ӯ��\n");
	else
		printf("ƽ��\n");
	system("pause");
	system("cls");
}

void game_two() {
	//�洢���� - ��ά����
	char board[ROW][COL];
	//��ʼ������-��ʼ��Ϊ�ո�
	InitBoard(board, ROW, COL);
	char ret = 0;//������Ϸ״̬
	//��ҶԴ�
	while (1)
	{
		// ��ӡ���� - ��ӡ��������
		DayinBoard(board, ROW, COL);
		//�жϻغ�
		printf("RANGE %d\n", rang);
		//���1����
		Player1Move(board, ROW, COL);
		DayinBoard(board, ROW, COL);
		//�ж����1�Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		//���2����
		Player2Move(board, ROW, COL);
		DayinBoard(board, ROW, COL);
		//�ж����2�Ƿ�Ӯ����Ϸ
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		system("cls");
		rang++;
	}
	if (ret == 'o')
		printf("���1Ӯ��\n");
	else if (ret == 'x')
		printf("���2Ӯ��\n");
	else
		printf("ƽ��\n");
	system("pause");
	system("cls");
}

int main(void) {
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		denglu();
		menu();
		printf("��ѡ��>");
		scanf("%d",&input);
		switch (input) 
		{
		case 1:
			game_one();
			break;
		case 2:
			game_two();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ���������ѡ��\n");
			break;
		}
	} while (input);
	return 0;
}