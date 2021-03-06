#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("********************************\n");
	printf("*********    1.PLAY    *********\n");
	printf("*********    0.EXIT    *********\n");
	printf("********************************\n");
}

void game()
{
	//雷的信息存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.排查出的雷的信息
	char show[ROWS][COLS] = { 0 };
	printf("           游戏开始!\n");
	Sleep(1000);
	system("cls");
	//初始化;
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//打印棋盘
	//DisPlayboard(mine,ROW,COL);
	//布置雷
	SetMine(mine,ROW,COL);
	/*DisPlayboard(mine,ROW,COL);*/
	//扫雷
	FindMine(mine,show,ROW,COL);

}

void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d",& input);
		system("cls");

		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("游戏退出!\n");
			Sleep(1000);
			system("cls");
			break;
		default:
			printf("选择错误，重新选择!\n");
			Sleep(1000);
			system("cls");
			break;
		}

	}while(input);
}
int main()
{
	test();
	return 0;
}