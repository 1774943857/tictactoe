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
	//存储数据 - 二维数组
	char board[ROW][COL];
	//初始化棋盘-初始化为空格
	InitBoard(board, ROW, COL);
	//打印棋盘-打印数组内容
	DayinBoard(board, ROW, COL);
	char ret = 0;//接收游戏状态
	//人机互动
	while (1) 
	{
		//判断回合
		printf("RANGE %d\n",rang);
		//玩家下棋
		Player1Move(board,ROW,COL);
		DayinBoard(board, ROW, COL);
		//判断玩家是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'c') 
			break;
		system("cls");
		//电脑下棋
		ComMove(board, ROW, COL);
		DayinBoard(board, ROW, COL);
		//判断电脑是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		rang++;
	}
	if (ret == 'o')
		printf("玩家赢了\n");
	else if (ret == 'x') 
		printf("电脑赢了\n");
	else
		printf("平局\n");
	system("pause");
	system("cls");
}

void game_two() {
	//存储数据 - 二维数组
	char board[ROW][COL];
	//初始化棋盘-初始化为空格
	InitBoard(board, ROW, COL);
	char ret = 0;//接收游戏状态
	//玩家对打
	while (1)
	{
		// 打印棋盘 - 打印数组内容
		DayinBoard(board, ROW, COL);
		//判断回合
		printf("RANGE %d\n", rang);
		//玩家1下棋
		Player1Move(board, ROW, COL);
		DayinBoard(board, ROW, COL);
		//判断玩家1是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		//玩家2下棋
		Player2Move(board, ROW, COL);
		DayinBoard(board, ROW, COL);
		//判断玩家2是否赢得游戏
		ret = IsWin(board, ROW, COL);
		if (ret != 'c')
			break;
		system("cls");
		rang++;
	}
	if (ret == 'o')
		printf("玩家1赢了\n");
	else if (ret == 'x')
		printf("玩家2赢了\n");
	else
		printf("平局\n");
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
		printf("请选择：>");
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
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}