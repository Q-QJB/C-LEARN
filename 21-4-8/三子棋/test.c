#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

void menu()
{
	printf("***************************\n");
	printf("****** 1-��ʼ 0-�˳� ******\n");
	printf("***************************\n");
}

void game()//��Ϸʵ���㷨
{
	int A = 0;
	char ret = 0;
	char board[ROW][COL] = {0};//ȫ���ո�
	InitBoard(board,ROW,COL);//��ʼ������
	DisplayBoard(board,ROW,COL);//��ӡ����
	
	while(1)//����
	{
		PlayerMove(board,ROW,COL,A);//�������
		A++;
		Sleep(1000);
		system("cls");
		DisplayBoard(board,ROW,COL);
		ret = IsWin(board,ROW,COL);//�ж�����Ƿ�Ӯ
		if(ret!='C')
		{
			break;
		}
		ComputerMove(board,ROW,COL);//��������
		Sleep(1000);
		system("cls");
		DisplayBoard(board,ROW,COL);
		ret = IsWin(board,ROW,COL);//�жϵ����Ƿ�Ӯ
		if(ret!='C')
		{
			break;
		}
	}
	if(ret == '*')
	{
		printf("���Ӯ!\n");
		Sleep(2000);
		system("cls");
	}
	else if(ret == '#')
	{
		printf("����Ӯ!\n");
		Sleep(2000);
		system("cls");
	}
	else
	{
		printf("ƽ��!");
		Sleep(2000);
		system("cls");
	}
}

void test()//��Ϸ���
{
	int a = 0;
	int count = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",&a);
		Sleep(1000);
		system("cls");
		if(count==0 && a!=0 &&a==1)
		{	
			CON();//��Ϸ����	
		}

		if(a==1)
		{
			printf("\n          ������\n\n");
			printf("         ��Ϸ��ʼ!\n");
			Sleep(1000);
			system("cls");
			game();//������Ϸ����
			count++;
		}
		else if(a==0)
		{
			printf("        ��Ϸ�˳�!\n");
			Sleep(1000);
			system("cls");
			break;
		}
		else
		{
			printf("�����������������!");
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