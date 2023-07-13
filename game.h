#pragma once
//头文件的包含
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//符号的定义
#define ROW 3
#define COL 3

typedef struct info {
	char user[20];
	char mima[20];
}user;
user u;

//函数的声明
//初始化棋盘
void InitBoard(char board[ROW][COL], int row, int col);
//打印棋盘
void DayinBoard(char board[ROW][COL], int row, int col);
//玩家下棋
void Player1Move(char board[ROW][COL], int row, int col);
void Player2Move(char board[ROW][COL], int row, int col);
//电脑下棋
void ComMove(char board[ROW][COL], int row, int col);
//是否赢得游戏
char IsWin(char board[ROW][COL], int row, int col);

//用户信息管理
//注册
void zhuce();
//登录
void denglu();
//写入用户信息
void write();