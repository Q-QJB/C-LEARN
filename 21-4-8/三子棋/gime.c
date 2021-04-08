#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void CON()//游戏介绍
{
	printf("游戏介绍:\n");
	printf("本游戏为三子棋,根据棋盘坐\n标落子，直到三子相连为胜!");
	Sleep(6000);
	system("cls");
}

void InitBoard(char board[ROW][COL],int row,int col)//初始化棋盘(都为空格)
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			board[i][j] = ' ';
		}
	}
}

void DisplayBoard(char board[ROW][COL],int row,int col)//打印棋盘(边框)
{
	
	int i = 0;
	printf("\n");
	for(i=0;i<row;i++)
	{
		int j = 0;
		for(j=0;j<col;j++)
		{
			if(j==0)
				printf("      ");
			printf(" %c ",board[i][j]);
			if(j<col-1)
			{
				printf("|");
			}
		}
		printf("\n");
		if(i<row-1)
		{	
			for(j=0;j<col;j++)
			{
				if(j==0)
					printf("      ");
				printf("---");
				if(j<col-1)
					printf("|");
			}
		}
		printf("\n");
	}
}

void PlayerMove(char board[ROW][COL],int row,int col,int a)//玩家下棋
{
	int x = 0;
	int y = 0;

	while(1)
	{
		printf("玩家走\n");	
		if(a==0)
		{
			printf("请输入坐标(两数间空格隔开):>");
		}
		else
		{
			printf("请输入坐标:>");
		}
		scanf("%d%d",&x,&y);
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(board[x-1][y-1]==' ')
			{
				board[x-1][y-1] = '*';
				break;
			}
			else
			{
				printf("此处已下子,重新输入!\n");
				Sleep(2000);
				system("cls");
				DisplayBoard(board,ROW,COL);
			}
		}
		else
		{
			printf("输入错误请重新输入!");
			Sleep(1000);
			system("cls");
			DisplayBoard(board,ROW,COL);
		}
	}
}

void ComputerMove(char board[ROW][COL],int row,int col)//电脑下棋
{
	int x = 0;
	int y = 0;
	printf("电脑走:>\n");

	while(1)
	{	
		x = rand()%row;
		y = rand()%col;
		if(board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
	//DisplayBoard(board,ROW,COL);
}

int IsFull(char board[ROW][COL],int row,int col)//返回1表示满了，返回0表示没满
{
	int i = 0;
	int j = 0;
	for(i=0;i<row;i++)
	{
		for(j=0;j<col;j++)
		{
			if(board[i][j]==' ')
			{	
				return 0;
			}
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL],int row,int col)
{
	int i = 0;
	for(i=0;i<row;i++)//横三行
	{
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2] && board[i][1]!=' ')
		{
			return board[i][1];
		}
	}
	for(i=0;i<col;i++)//竖三列
	{
		if(board[0][i]==board[1][i] && board[1][i]==board[2][i] && board[1][i]!=' ')
		{
			return board[1][i];
		}
	}
	//两个对角线
	if(board[0][0]==board[1][1] &&board[1][1]==board[2][2] &&board[1][1]!=' ')
	{
		return board[1][1];
	}
	if(board[2][0]==board[1][1] &&board[1][1]==board[0][2] &&board[1][1]!=' ')
	{
		return board[1][1];
	}
	//判断平局
	if(1==IsFull(board,ROW,COL))
	{
		return 'Q';
	}
	return 'C';
}