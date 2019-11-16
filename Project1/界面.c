#include<stdio.h>
#include<windows.h>//控制DOS界面（获取控制台上的坐标位置，设置字体颜色）
#include<conio.h>//接收键盘输入输出（kbhit()，getch())
#include<time.h>//用于获得随机数
#include<stdlib.h>
/*宏定义*/
#define FrameX 13 //游戏窗口左上角x轴坐标
#define FrameY 3 //游戏窗口左上角y轴坐标
#define Frame_height 20 //游戏窗口的高度
#define Frame_width 18 //游戏窗口的宽度

extern void DrwaGameFrame();



//标记游戏屏幕的图案：2,0,1分别表示该位置为游戏边框，方块，无图案；初始化为无图案
int color(int c) {

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);//更改文字颜色

	return 0;

}
/**
*获取屏幕光标位置
*/
void gotoxy(int x, int y) {
	//COORD 是一个结构体
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);

}
void title() {

	color(15);
	gotoxy(28, 3);
	printf("俄 罗 斯 方 块"); //标题


	color(11);
	gotoxy(18, 5);
	printf("■");
	gotoxy(18, 6);
	printf("■");
	printf("■");
	gotoxy(18, 7);
	printf("■");

	color(14);
	gotoxy(26, 6);
	printf("■");
	printf("■");
	gotoxy(28, 7);
	printf("■");
	printf("■");

	color(10);
	gotoxy(36, 6);
	printf("■");
	printf("■");
	gotoxy(36, 7);
	printf("■");
	printf("■");

	color(13);
	gotoxy(45, 5);
	printf("■");
	gotoxy(45, 6);
	printf("■");
	gotoxy(45, 7);
	printf("■");
	gotoxy(45, 8);
	printf("■");

	color(12);
	gotoxy(56, 6);
	printf("■");
	gotoxy(56, 7);
	printf("■");
	printf("■");
	printf("■");

	printf("\n\n\n\n\n\n\n\n\n");


}
/*
*绘制字符花
*/
void flower() {

	gotoxy(66, 11); //确定屏幕上要输出的位置
	color(12);
	printf("(_)");//红色小花瓣

	gotoxy(64, 12);
	printf("(_)");

	gotoxy(68, 12);
	printf("(_)");

	gotoxy(66, 13);
	printf("(_)");

	gotoxy(67, 12);
	printf("(_)");

	gotoxy(67, 12);
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

	gotoxy(71, 12);
	printf("(_)");
	printf("|"); //两朵花之间的连接

	gotoxy(72, 11);
	printf("/");

	gotoxy(70, 13);
	printf("\\|");//需要转义 \

	gotoxy(70, 14);
	printf("`|/");

	gotoxy(70, 15);
	printf("\\|");

	gotoxy(71, 16);
	printf("| /");

	gotoxy(67, 17);
	color(10);
	printf("\\\\\\\\\\\\\\\\\\\\");

	gotoxy(73, 17);
	printf("//");

	gotoxy(67, 18);
	color(2);
	printf("^^^^^^^^^^^\n");


	gotoxy(65, 19);
	color(5);
	printf("迷 你 甘");

	gotoxy(68, 20);
	printf("帅 到 爆 炸 \n");

}
void test_ascll() {
	for (int i = 0; i < 255; i++) {
		printf("%d %c\t", i, i);
		if (i % 5 == 0) {
			printf("\n");
		}

	}

}

/*
* 菜单
*/
void welcome() {
	
	int n, i, j = 1;
	color(14);//黄色边框

	for (i = 9; i <= 20; i++) {

		for (j = 15; j <= 60; j++) {


			gotoxy(j, i);

			if (i == 9 || i == 20) {

				printf("=");//打印上下边框 ==

			}
			else if (j == 15 || j == 59) {

				printf("||");//打印左右边框
			}
		}

	}
	color(12);
	gotoxy(25, 12);
	printf("1.开始游戏");

	gotoxy(40, 12);
	printf("2.按键说明");


	gotoxy(25, 17);
	printf("3.游戏规则");

	gotoxy(40, 17);
	printf("4.退出");


	gotoxy(21, 22);
	color(3);
	printf("请选择 [1,2,3,4]:[ ]\b\b");//退格 将当前位置往前一个 这样光标正好在方块里面
	color(14);
	scanf_s("%d", &n);
	switch (n)
	{
	case 1:

		system("cls");//清屏
		DrwaGameFrame();
		Gameplay();
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		break;
	default:
		break;
	}

}
