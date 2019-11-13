#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
#include<stdlib.h>

int color(int c) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),c);//更改文字颜色

	return 0;	

}
/**
*获取屏幕光标位置
*/
void gotoxy(int x,int y) {
	//COORD 是一个结构体
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
void title() {

	color(15);
	gotoxy(35, 3);
	printf("Tetris"); //标题


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
void test_ascll() {
	for (int i = 0; i < 255;i++) {
		printf("%d %c\t", i,i);
		if (i % 5 == 0) {
			printf("\n");
		}

	}

}