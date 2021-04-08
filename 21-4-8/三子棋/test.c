#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("****** 1-开始 0-退出 ******\n");
	printf("***************************\n");
}

void game()//游戏实现算法
{
	int A = 0;
	char ret = 0;
	char board[ROW][COL] = {0};//全部空格
	InitBoard(board,ROW,COL);//初始化棋盘
	DisplayBoard(board,ROW,COL);//打印棋盘
	
	while(1)//下棋
	{
		PlayerMove(board,ROW,COL,A);//玩家下棋
		A++;
		Sleep(1000);
		system("cls");
		DisplayBoard(board,ROW,COL);
		ret = IsWin(board,ROW,COL);//判断玩家是否赢
		if(ret!='C')
		{
			break;
		}
		ComputerMove(board,ROW,COL);//电脑下棋
		Sleep(1000);
		system("cls");
		DisplayBoard(board,ROW,COL);
		ret = IsWin(board,ROW,COL);//判断电脑是否赢
		if(ret!='C')
		{
			break;
		}
	}
	if(ret == '*')
	{
		printf("玩家赢!\n");
		Sleep(2000);
		system("cls");
	}
	else if(ret == '#')
	{
		printf("电脑赢!\n");
		Sleep(2000);
		system("cls");
	}
	else
	{
		printf("平局!");
		Sleep(2000);
		system("cls");
	}
}

void test()//游戏框架
{
	int a = 0;
	int count = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",&a);
		Sleep(1000);
		system("cls");
		if(count==0 && a!=0 &&a==1)
		{	
			CON();//游戏介绍	
		}

		if(a==1)
		{
			printf("\n          三子棋\n\n");
			printf("         游戏开始!\n");
			Sleep(1000);
			system("cls");
			game();//调用游戏函数
			count++;
		}
		else if(a==0)
		{
			printf("        游戏退出!\n");
			Sleep(1000);
			system("cls");
			break;
		}
		else
		{
			printf("输入错误，请重新输入!");
			Sleep(1000);
			system("cls");
			count++;
		}
	}while(a!=0);
}

int main()
{
	test();
	return 0;
}