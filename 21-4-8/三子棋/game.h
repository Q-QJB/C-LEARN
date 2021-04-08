#include <stdio.h>
#include <stdio.h>
#include <time.h>
#include <windows.h>
#include <stdlib.h>

#define ROW 3
#define COL 3

//声明
void CON();
void InitBoard(char board[ROW][COL],int row,int col);
void DisplayBoard(char board[ROW][COL],int row,int col);
void PlayerMove(char board[ROW][COL],int row,int col,int A);
void ComputerMove(char board[ROW][COL],int row,int col);

//告诉我们四种游戏状态
//玩家赢 - '*'
//电脑赢 - '#'
//平局   - 'Q'
//继续   - 'C'
char IsWin(char board[ROW][COL],int row,int col);