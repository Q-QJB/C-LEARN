#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("          猜数游戏\n");
	printf("*******************************\n");
	printf("******  1.开始   0.退出  ******\n");
	printf("*******************************\n");
}

int main()
{  //猜数字游戏
	int a = 0;
	int number = 0;
	int i = 0;
	do
	{
		menu();
		printf("请选择>");
		scanf("%d",&a);
		system("cls");

		if(a==1)
		{
			srand(time(0));
			number=rand()%100+1;
			printf("游戏开始!");
			Sleep(1000);
			system("cls");
			printf("现在电脑以为你想好了一个数\n");
			do
			{	printf("请猜一个数>");
				scanf("%d",&i);
		if(i>number)
		{	printf("猜大了!");
			Sleep(1000);
			system("cls");
		}	
		if(i<number)
		{	printf("猜小了!");
			Sleep(1000);
			system("cls");
		}
	}while(i!=number);
	printf("恭喜你猜对了!\n");
	Sleep(1000);
	system("cls");

		}
		else if(a!=1&&a!=0)
		{
			printf("输入错误，请重新输入!\n");
			Sleep(1000);
			system("cls");
		}

	}while(a!=0);
	printf("退出游戏!\n");
	Sleep(1000);
	system("cls");


	return 0;
}	