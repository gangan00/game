#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int color(int c) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);//����������ɫ

	return 0;	

}
/**
*��ȡ��Ļ���λ��
*/
void gotoxy(int x,int y) {
	//COORD ��һ���ṹ��
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
void title() {

	color(15);
	gotoxy(35, 3);
	printf("Tetris"); //����


	color(11);
	gotoxy(18, 5);
	printf("%c", 254);
	gotoxy(18, 6);
	printf("%c", 254);
	printf("%c", 254);
	gotoxy(18, 7);
	printf("%c", 254);
	
	color(14);
	gotoxy(26, 6);
	printf("%c", 254);
	printf("%c", 254);
	gotoxy(28, 7);
	printf("%c", 254);
	printf("%c", 254);

	color(10);
	gotoxy(36, 6);
	printf("%c", 254);
	printf("%c", 254);
	gotoxy(36, 7);
	printf("%c", 254);
	printf("%c", 254);

	color(13);
	gotoxy(45, 5);
	printf("%c", 254);
	gotoxy(45, 6);
	printf("%c", 254);
	gotoxy(45, 7);
	printf("%c", 254);
	gotoxy(45, 8);
	printf("%c", 254);

	color(12);
	gotoxy(56, 6);
	printf("%c", 254);
	gotoxy(56, 7);
	printf("%c", 254);
	printf("%c", 254);
	printf("%c", 254);
	printf("\n\n\n\n\n\n\n\n\n");

	
}
/*
*�����ַ���
*/
void flower() {

	gotoxy(66, 11); //ȷ����Ļ��Ҫ�����λ��
	color(12);
	printf("(_)");//��ɫС����

	gotoxy(64, 12); 
	printf("(_)");

	gotoxy(68, 12);
	printf("(_)");

	gotoxy(66,13);
	printf("(_)");

	gotoxy(67,12);
	printf("(_)");

	gotoxy(67,12);
	color(6); 
	printf("@");

	gotoxy(72, 10);
	color(13);
	printf("(_)");

	gotoxy(76, 10);
	printf("(_)");

	gotoxy(74, 9);
	printf("(_)");

	gotoxy(74, 11);
	printf("(_)");

	gotoxy(75, 10);
	color(6);
	printf("@");

	gotoxy(71,12);
	printf("(_)");
	printf("|"); //���仨֮�������

	gotoxy(72,11);
	printf("/");

	gotoxy(70, 13);
	printf("\\|");//��Ҫת�� \

	gotoxy(70, 14);
	printf("`|/");

	gotoxy(70, 15);
	printf("\\|");

	gotoxy(71, 16);
	printf("| /");

	gotoxy(67,17);
	color(10);
	printf("\\\\\\\\\\\\\\\\\\\\");

	gotoxy(73,17);
	printf("//");

	gotoxy(67,18);
	color(2);
	printf("^^^^^^^^^^^\n");


	gotoxy(65,19);
	color(5);
	printf("ni mi gan");

	gotoxy(68,20);
	printf("shuai de mao bao\n");

}
void test_ascll() {
	for (int i = 0; i < 255;i++) {
		printf("%d %c\t", i,i);
		if (i % 5 == 0) {
			printf("\n");
		}

	}

}