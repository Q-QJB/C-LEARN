#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void InitBoard(char board[ROWS][COLS],int rows,int cols,char set)//初始化
{
	int i = 0;
	int j = 0;
	for(i=0;i<rows;i++)
	{
		for(j=0;j<cols;j++)
		{
			board[i][j] = set;
		}
	}
}

void DisPlayboard(char board[ROWS][COLS],int row,int col)//打印
{
	int i = 0;
	int j = 0;
	//打印列号
	for(i=0;i<=row;i++)
	{	
		if(i==0)
				printf("       ");
		printf("%d ",i);
	}
	printf("\n");
	for(i =1;i<=row;i++)
	{
		for(j=1;j<=col;j++)
		{
			if(j==1)
			{	
				printf("       ");
				printf("%d ",i);
			}
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}

void SetMine(char board[ROWS][COLS],int row,int col)//布置雷
{
	int count = EASY_COUNT;

	while(count)
	{
		int x =rand()%row+1;
		int y =rand()%col+1;
		if(board[x][y]=='0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

int get_mine_count(char mine[ROWS][COLS],int x,int y)//算该点周围雷数
{
	return mine[x-1][y]+
	mine[x-1][y-1]+
	mine[x][y-1]+
	mine[x+1][y-1]+
	mine[x+1][y]+
	mine[x+1][y+1]+
	mine[x][y+1]+
	mine[x-1][y+1]-8*'0';

}

void FindMine(char mine[ROWS][COLS],char show[ROWS][COLS],int row,int col)//排雷
{
	int a = 0;
	int x = 0;
	int y = 0;
	while(1)
	{
		DisPlayboard(show,ROW,COL);
		printf("请输入排雷坐标:>");
		scanf("%d%d",&x,&y);
		if(x>=1 && x<=row && y>=1 && y<=col)
		{
			if(mine[x][y]=='1')
			{
				system("cls");
				DisPlayboard(mine,row,col);
				printf("很遗憾，你被炸死了");
				Sleep(3000);
				system("cls");
				break;
			}
			else if(show[x][y]=='*')
			{
				//计算x,y坐标周围有几个雷
				int count= get_mine_count(mine,x,y);
				show[x][y]=count+'0';
				a++;
				system("cls");
			}
			else
			{
				printf("该位置已排完，请重新输入!");
				Sleep(2000);
				system("cls");
			}
		}
		else
		{
			printf("输入错误,请重新输入!\n");
			Sleep(1000);
			system("cls");
		}
		if(a==row*col-EASY_COUNT)
		{
			DisPlayboard(mine,row,col);
			printf("恭喜你,排雷成功!");
			Sleep(3000);
			system("cls");
			break;
		}
	}

}