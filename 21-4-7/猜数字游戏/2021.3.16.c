#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <stdlib.h>
#include <time.h>

void menu()
{
	printf("          ������Ϸ\n");
	printf("*******************************\n");
	printf("******  1.��ʼ   0.�˳�  ******\n");
	printf("*******************************\n");
}

int main()
{  //��������Ϸ
	int a = 0;
	int number = 0;
	int i = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d",&a);
		system("cls");

		if(a==1)
		{
			srand(time(0));
			number=rand()%100+1;
			printf("��Ϸ��ʼ!");
			Sleep(1000);
			system("cls");
			printf("���ڵ�����Ϊ�������һ����\n");
			do
			{	printf("���һ����>");
				scanf("%d",&i);
		if(i>number)
		{	printf("�´���!");
			Sleep(1000);
			system("cls");
		}	
		if(i<number)
		{	printf("��С��!");
			Sleep(1000);
			system("cls");
		}
	}while(i!=number);
	printf("��ϲ��¶���!\n");
	Sleep(1000);
	system("cls");

		}
		else if(a!=1&&a!=0)
		{
			printf("�����������������!\n");
			Sleep(1000);
			system("cls");
		}

	}while(a!=0);
	printf("�˳���Ϸ!\n");
	Sleep(1000);
	system("cls");


	return 0;
}	