#include"game.h"

void InitBoard(char board[ROW][COL], int row, int col) {
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DayinBoard(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
				printf("|");
		}
		printf("\n");
		if (i < row - 1)
		{
			for (int j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
}

void Player1Move(char board[ROW][COL], int row, int col) {
	int x, y;
	printf("���1��>\n");
	while (1)
	{
		printf("������һ������(x y)���꣺>");
		//�ж�����Ϸ���
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����
			//�����Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'o';
				break;
			}
			else
			{
				printf("������ռ�ã�����������\n");
			}
		}
		else
		{
			printf("�Ƿ����꣬���������룬�����겻Ӧ����%d,�����겻Ӧ����%d\n", ROW, COL);
		}
	}
}

void Player2Move(char board[ROW][COL], int row, int col) {
	int x, y;
	printf("���2��>\n");
	while (1)
	{
		printf("������һ������(x y)���꣺>");
		//�ж�����Ϸ���
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//����
			//�����Ƿ�ռ��
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("������ռ�ã�����������\n");
			}
		}
		else
		{
			printf("�Ƿ����꣬���������룬�����겻Ӧ����%d,�����겻Ӧ����%d\n",ROW,COL);
		}
	}
}

void ComMove(char board[ROW][COL], int row, int col)
{
	while (1) {
		int x = rand() % row, y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = 'x';
			break;
		}
	}
}

int IsFull(char board[ROW][COL], int row, int col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	//�ж�����
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	//�ж�����
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
			return board[1][j];
	}
	//�Խ���
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//�ж�ƽ��
	//���˷���1�����򷵻�0
	int ret = IsFull(board, row, col);
	if (ret == 1)
		return 'Q';
	return 'c';
}