#pragma once
//ͷ�ļ��İ���
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//���ŵĶ���
#define ROW 3
#define COL 3

typedef struct info {
	char user[20];
	char mima[20];
}user;
user u;

//����������
//��ʼ������
void InitBoard(char board[ROW][COL], int row, int col);
//��ӡ����
void DayinBoard(char board[ROW][COL], int row, int col);
//�������
void Player1Move(char board[ROW][COL], int row, int col);
void Player2Move(char board[ROW][COL], int row, int col);
//��������
void ComMove(char board[ROW][COL], int row, int col);
//�Ƿ�Ӯ����Ϸ
char IsWin(char board[ROW][COL], int row, int col);

//�û���Ϣ����
//ע��
void zhuce();
//��¼
void denglu();
//д���û���Ϣ
void write();