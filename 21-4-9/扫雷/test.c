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
	//�׵���Ϣ�洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = { 0 };//11*11
	//2.�Ų�����׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	printf("           ��Ϸ��ʼ!\n");
	Sleep(1000);
	system("cls");
	//��ʼ��;
	InitBoard(mine,ROWS,COLS,'0');
	InitBoard(show,ROWS,COLS,'*');
	//��ӡ����
	//DisPlayboard(mine,ROW,COL);
	//������
	SetMine(mine,ROW,COL);
	/*DisPlayboard(mine,ROW,COL);*/
	//ɨ��
	FindMine(mine,show,ROW,COL);

}

void test()
{
	int input = 0;
	srand((unsigned)time(NULL));
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d",& input);
		system("cls");

		switch(input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("��Ϸ�˳�!\n");
			Sleep(1000);
			system("cls");
			break;
		default:
			printf("ѡ���������ѡ��!\n");
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