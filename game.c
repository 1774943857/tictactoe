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
	printf("玩家1走>\n");
	while (1)
	{
		printf("请输入一个类似(x y)坐标：>");
		//判断坐标合法性
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//下棋
			//坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'o';
				break;
			}
			else
			{
				printf("坐标已占用，请重新输入\n");
			}
		}
		else
		{
			printf("非法坐标，请重新输入，横坐标不应大于%d,纵坐标不应大于%d\n", ROW, COL);
		}
	}
}

void Player2Move(char board[ROW][COL], int row, int col) {
	int x, y;
	printf("玩家2走>\n");
	while (1)
	{
		printf("请输入一个类似(x y)坐标：>");
		//判断坐标合法性
		scanf("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//下棋
			//坐标是否被占用
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = 'x';
				break;
			}
			else
			{
				printf("坐标已占用，请重新输入\n");
			}
		}
		else
		{
			printf("非法坐标，请重新输入，横坐标不应大于%d,纵坐标不应大于%d\n",ROW,COL);
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
	//判断三行
	for (int i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	//判断三列
	for (int j = 0; j < col; j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
			return board[1][j];
	}
	//对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')
		return board[1][1];
	//判断平局
	//满了返回1，否则返回0
	int ret = IsFull(board, row, col);
	if (ret == 1)
		return 'Q';
	return 'c';
}