#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

//����
void CON();
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col,int A);
void ComputerMove(char board[ROW][COL],int row,int col);

//��������������Ϸ״̬
//���Ӯ - '*'
//����Ӯ - '#'
//ƽ��   - 'Q'
//����   - 'C'
char IsWin(char board[ROW][COL],int row,int col);