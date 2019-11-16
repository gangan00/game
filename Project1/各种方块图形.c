
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>//控制DOS界面（获取控制台上的坐标位置，设置字体颜色）
#include<conio.h>//接收键盘输入输出（_kbhit()，_getch())
#include<time.h>//用于获得随机数
#include<stdlib.h>

/*宏定义*/
#define FrameX 13 //游戏窗口左上角x轴坐标
#define FrameY 3 //游戏窗口左上角y轴坐标
#define Frame_height 20 //游戏窗口的高度
#define Frame_width 18 //游戏窗口的宽度
int temp, temp1, temp2;//用于记住和转换方块变量的值
struct Tetris {
	//方块的各种信息
	int x;
	int y;
	int flag;
	int next;
	int speed;
	int number;
	int score;
	int level;

};
HANDLE hOut; //控制台句柄；
int b[4] = { 0,0,0,0 };//标记四个“口”方块：1表示有方块，0表示无方块；
char ch;
int a[80][80] = { 0 };
extern void gotoxy(int x, int y);
extern int color(int c);
extern void welcome();

/*

俄罗斯方块共有七种基本图形，19种旋转类型。
*/

void MakeTetris(struct Tetris * tetris) {

	a[tetris->x][tetris->y] = b[0];//中心方块位置的图形状态；
	switch (tetris->flag) {
	case 1:
		color(10);//田
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x + 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;

	case 2:
		color(13);//直线 -
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y] = b[2];
		a[tetris->x + 4][tetris->y] = b[3];
		break;

	case 3:
		color(13);//直线竖条 |
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x][tetris->y + 2] = b[3];
		break;
	case 4:
		color(11);// T
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y] = b[2];
		a[tetris->x][tetris->y + 1] = b[3];
		break;
	case 5:
		color(11);// |-
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x - 2][tetris->y] = b[3];
		break;
	case 6:
		color(11);/* |
					——
				   */
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x - 2][tetris->y] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 7:
		color(11);// -|
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 8:
		color(14);// Z
		a[tetris->x][tetris->y + 1] = b[1];
		a[tetris->x - 2][tetris->y] = b[2];
		a[tetris->x + 2][tetris->y + 1] = b[3];
		break;
	case 9:
		color(14);// Z 旋转
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x - 2][tetris->y] = b[2];
		a[tetris->x - 2][tetris->y + 1] = b[3];
		break;
	case 10:
		color(14);// Z 反转
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x - 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 11:
		color(14);// 顺时针 Z 反转
		a[tetris->x][tetris->y + 1] = b[1];
		a[tetris->x - 2][tetris->y - 1] = b[2];
		a[tetris->x - 2][tetris->y] = b[3];
		break;
	case 12:
		color(12);// 7
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x - 2][tetris->y - 1] = b[3];
		break;

	case 13:
		color(12);// 顺时针九十度 7
		a[tetris->x][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 14:
		color(12);// 顺时针180 7
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y + 1] = b[3];
		break;
	case 15:
		color(12);// 顺时针270 7
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x - 2][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 16:
		color(9);// 反转 7
		a[tetris->x][tetris->y + 1] = b[1];
		a[tetris->x][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y - 1] = b[3];
		break;
	case 17:
		color(9);// 逆时针90 7
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 18:
		color(9);// 逆时针180 7
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x - 2][tetris->y + 1] = b[3];
		break;
	case 19:
		color(9);// 逆时针180 7
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y] = b[2];
		a[tetris->x - 2][tetris->y - 1] = b[3];
		break;

	}

}


void PrintTetris(struct Tetris *tetris) {

	for (int i = 0; i < 4; i++) b[i] = 1; //先把b[i]里的值都置为1 定义的时候为啥不直接置为1
	MakeTetris(tetris);//通过这个函数 就保存了对应位置图形需要画一个方块的坐标 
	for (int i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
		for (int j = tetris->y - 2; j <= tetris->y + 1; j++) {
			//四个值也只能最多覆盖的区域
			if (a[i][j] == 1 && j > FrameY) {
				//J的值要在游戏界面里面
				gotoxy(i, j);
				printf("■");
			}
		}
	}
	//打印菜单信息
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 1);
	color(4);
	printf("level : ");
	color(12);
	printf(" %d", tetris->level);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 3);
	color(4);
	printf("score : ");
	color(12);
	printf(" %d", tetris->score);
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 5);
	color(4);
	printf("speed : ");
	color(12);
	printf(" %d", tetris->speed);


}
/*
判断方块是否可以移动
*/

int ifMove(struct Tetris *tetris) {
	//非常的麻烦 主要先判断中心方块是否为空 再判断各个位置上是否为空 再根据不同的方块形状 判断是否能移动

	if (a[tetris->x][tetris->y] != 0) return 0;//不可移动
	//这个函数不 
	else {
		if (
			(tetris->flag == 1 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x + 2][tetris->y - 1] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)
			|| (tetris->flag == 2 && a[tetris->x - 2][tetris->y] == 0 &&
				a[tetris->x + 2][tetris->y] == 0 &&
				a[tetris->x + 4][tetris->y] == 0)
			|| (tetris->flag == 3 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x][tetris->y + 2] == 0)
			|| (tetris->flag == 4 && a[tetris->x - 2][tetris->y] == 0 &&
				a[tetris->x + 2][tetris->y] == 0 &&
				a[tetris->x][tetris->y + 1] == 0)
			|| (tetris->flag == 5 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x - 2][tetris->y] == 0)
			|| (tetris->flag == 6 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x - 2][tetris->y] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)
			|| (tetris->flag == 7 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)
			|| (tetris->flag == 8 && a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x - 2][tetris->y] == 0 &&
				a[tetris->x + 2][tetris->y + 1] == 0)
			|| (tetris->flag == 9 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x - 2][tetris->y] == 0 &&
				a[tetris->x - 2][tetris->y + 1] == 0)
			|| (tetris->flag == 10 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x - 2][tetris->y - 1] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)
			|| (tetris->flag == 11 && a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x - 2][tetris->y - 1] == 0 &&
				a[tetris->x - 2][tetris->y] == 0)
			|| (tetris->flag == 12 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x - 2][tetris->y - 1] == 0)
			|| (tetris->flag == 13 && a[tetris->x][tetris->y] == 0 &&
				a[tetris->x + 2][tetris->y - 1] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)
			|| (tetris->flag == 14 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x + 2][tetris->y + 1] == 0)
			|| (tetris->flag == 15 && a[tetris->x - 2][tetris->y] == 0 &&
				a[tetris->x - 2][tetris->y + 1] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)
			|| (tetris->flag == 16 && a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x + 2][tetris->y - 1] == 0)
			|| (tetris->flag == 17 && a[tetris->x - 2][tetris->y] == 0 &&
				a[tetris->x + 2][tetris->y + 1] == 0 &&
				a[tetris->x + 2][tetris->y] == 0)
			|| (tetris->flag == 18 && a[tetris->x][tetris->y - 1] == 0 &&
				a[tetris->x][tetris->y + 1] == 0 &&
				a[tetris->x - 2][tetris->y + 1] == 0)
			|| (tetris->flag == 19 && a[tetris->x - 2][tetris->y] == 0 &&
				a[tetris->x + 2][tetris->y] == 0 &&
				a[tetris->x - 2][tetris->y - 1] == 0)

			) {

			return 1;
		}
	}
	return 0;
}

/*
清楚方块的痕迹
*/
void CleanTetris(struct Tetris *tetris) {

	for (int i = 0; i < 4; i++) b[i] = 0; //把b[i]里的值都置为0

	MakeTetris(tetris);//通过这个函数 把要清除区域坐标的标志置为0；
	for (int i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
		for (int j = tetris->y - 2; j <= tetris->y + 1; j++) {
			//四个值也只能最多覆盖的区域
			if (a[i][j] == 0 && j > FrameY) {
				//J的值要在游戏界面里面
				gotoxy(i, j);
				printf("  ");//清除

			}
		}

	}
}
void CleanTetrisall(struct Tetris *tetris) {

	for (int i = tetris->x - 4; i <= tetris->x + 4; i += 2) {
		for (int j = tetris->y - 2; j <= tetris->y + 2; j++) {
			//四个值也只能最多覆盖的区域

			a[i][j] = 0;//全部清除
			gotoxy(i, j);
			printf("  ");//清除
		}
	}

}

/*
判断是否满行
*/

void Del_Fullline(struct Tetris *tetris) {
	int k, del_rows = 0;//k为某行方块的个数 
	for (int j = FrameY + Frame_height - 1; j >= FrameY + 1; j--) {

		k = 0;
		for (int i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2) {

			//就是遍历整个屏幕
			if (a[i][j] == 1) {
				k++;
				if (k == Frame_width - 2) {
					//满行
					for (k = FrameX + 2; i < FrameX + 2 * Frame_width - 2; k += 2) {
						a[k][j] = 0;
						gotoxy(k, j);
						printf(" ");//删除满行的方块
					}
					//删除行上面的方块还需要往下移动一行
					for (k = j - 1; k >= FrameY; k--) {
						for (int i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2) {
							//这是遍历从删除行的上一行到整个屏幕
							if (a[i][k] == 1) {

								a[i][k] = 0;
								gotoxy(i, k);
								printf(" ");//删除原来的方块
								gotoxy(i, k + 1);//y轴下移一个
								printf("■");
							}

						}

					}
					j++;//继续判断有没有满行的，用来抵消j-- 如果一下满好几行 下移一行之后 当前行还是需要再次判断
					del_rows++;//删除行数计数
				}

			}

		}


	}

	tetris->score += 100 * del_rows;//删除一行100分
	if (del_rows > 0 && (tetris->score % 1000 == 0 || tetris->score / 1000 > tetris->level - 1)) {

		tetris->speed -= 20;
		tetris->level++; // 升级
	}

}//当某行有Frame_width-2个方块时 ，消除

/*
随机产生方块序号

*/
void Flag(struct Tetris *tetris) {
	tetris->number++;//记住产生方块的个数；
	srand(time(NULL));//初始化随机数
	if (tetris->number == 1) {

		tetris->flag = rand() % 19;//得到第一个方块的序号，因为flag是0-19，所以取除以19的余数得到0-18的随机数
		tetris->next = rand() % 19;//得到下一个方块的序号 右边下一个方块的预览类型
	}
	else
	{
		tetris->flag = tetris->next; //把上一个next的值给flag
		tetris->next = rand() % 19;//得到下一个方块的序号 右边下一个方块的预览类型

	}


}

/*
开始游戏
*/
void Gameplay() {


	struct Tetris t;//定义结构体
	struct Tetris *tetris = &t;//结构体指针指向结构体变量
	//初始化所有值
	t.number = 0;
	t.score = 0;
	t.speed = 100;
	t.level = 1;
	while (1)
	{

		Flag(tetris);//得到序号
		tetris->flag = tetris->flag % 19 + 1; //把上一个next的值给flag
		tetris->next = tetris->next % 19 + 1;
		temp = tetris->flag;//当前方块序号
		tetris->x = FrameX + 2 * Frame_width + 6;//预览界面X坐标
		tetris->y = FrameY + 10;//预览界面Y坐标
		tetris->flag = tetris->next;//获得下一个序号
		CleanTetrisall(tetris);//设置预览方块的值为0，为了避免下次重复打印
		PrintTetris(tetris);//打印预览方块

		tetris->x = FrameX + Frame_width;//游戏中心X坐标
		tetris->y = FrameY - 1;//游戏中心Y坐标		
		tetris->flag = temp;

		//CleanTetrisall(tetris);
		//printf("当前flag %d", tetris->flag);
		/*for (int i = 0; i < 80; i++) {
			for (int j = 0; j < 80; j++) {
				if (a[i][j] == 1) {

					printf("a[%d][%d]=1\n", i, j);
				}
			}
		}*/
		//获取按键
		while (1)
			//控制方块 直到他不在移动
		{
			setbuf(stdin, NULL);
			fflush(stdin);//想清除缓冲区
		label:PrintTetris(tetris);//打印方块；
			Sleep(tetris->speed);//延缓时间
			CleanTetris(tetris);//清除痕迹
			temp1 = tetris->x;//记住中心方块的横坐标
			temp2 = tetris->flag;//记住中心方块的类型

			if (_kbhit() && ifMove(tetris)) {
				//如果键盘有输入
				ch = _getch();
				//ch = getchar();
				
				setbuf(stdin, NULL);
				fflush(stdin);
				if (ch == 75 && tetris->x > FrameX + 4) {
					//左键
					tetris->x -= 2;
				}
				else if (ch == 77 && tetris->x < FrameX + 2 * Frame_width - 7) {
					//右键
					tetris->x += 2;
					
					//gotoxy(tetris->y, (FrameX + 2 * Frame_width - 4));
				//printf("x:%d", tetris->x);
					//printf("边界:%d", FrameX + 2 * Frame_width - 6);
				}
				else if (ch == 80) {
					//下键 加速下落

					//判断是否能移动
					if (ifMove(tetris) && tetris->y < FrameY + Frame_height) {

						tetris->y += 2;
					}
					//else {
					//	tetris->y = FrameY + Frame_height - 2;
					//}
				}
				else if (ch == 72) {
					//上键 开始各种变化
					if (tetris->flag >= 2 && tetris->flag <= 3) {
						tetris->flag++;
						tetris->flag %= 2;
						tetris->flag += 2;

					}
					if (tetris->flag >= 4 && tetris->flag <= 7) {
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 4;

					}
					if (tetris->flag >= 8 && tetris->flag <= 11) {
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 8;

					}
					if (tetris->flag >= 12 && tetris->flag <= 15) {
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 12;

					}
					if (tetris->flag >= 16 && tetris->flag <= 19) {
						tetris->flag++;
						tetris->flag %= 4;
						tetris->flag += 16;

					}


				}
				else if (ch == 32) {
					//空格 暂停
					PrintTetris(tetris);
					while (1)
					{
						if (_kbhit()) {
							//再按空格键就继续
							ch = _getch();
							if (ch == 32) goto label;
						}

					}

				}
				else if (ch == 27) {
					//退出
					system("cls");
					memset(a, 0, 6400 * sizeof(int));
					welcome();

				}
				//else if (ifMove(tetris) == 0) {

					//tetris->x = temp1;
					//tetris->flag = temp2;
				//}
				//else {
					//goto label;
				//}
			}
			if (tetris->y <= FrameY + Frame_height)
				tetris->y++;//没有操作就往下移动

			if (ifMove(tetris) == 0) {
				//不能动了 就放在这里
				//printf("结束一个");
				tetris->y--;
				PrintTetris(tetris);
				Del_Fullline(tetris); //到这里才判断有么有满行的
				setbuf(stdin, NULL);
				fflush(stdin);
				break;
			}
		}

	}
}
/*
制作游戏窗口
*/
void DrwaGameFrame() {

	gotoxy(FrameX + Frame_width - 5, FrameY - 2);
	color(11);
	printf("俄罗丝方块儿~");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 7);
	color(2);
	printf("*********");//上边框
	gotoxy(FrameX + 2 * Frame_width + 13, FrameY + 7);
	color(3);
	printf("下一出现方块:");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 13);
	color(2);
	printf("*********");//下边框
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 17);
	color(14);
	printf("↑键 ： 旋转");

	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 19);
	printf("空格 ：暂停游戏");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 15);
	printf("Esc ： 退出游戏");
	gotoxy(FrameX, FrameY);
	color(12);
	printf("╔");
	gotoxy(FrameX + 2 * Frame_width - 2, FrameY);
	printf("╗");

	gotoxy(FrameX, FrameY + Frame_height);
	printf("╚");
	gotoxy(FrameX + 2 * Frame_width - 2, FrameY + Frame_height);
	printf("╝");
	for (int i = 2; i < 2 * Frame_width - 2; i += 2) {
		gotoxy(FrameX + i, FrameY);
		printf("═");
	};
	for (int i = 2; i < 2 * Frame_width - 2; i += 2) {
		gotoxy(FrameX + i, FrameY + Frame_height);
		printf("═"); //打印下横框
		a[FrameX + i][FrameY + Frame_height] = 2;//标记下横框为游戏边框，防止方块越界。
	};
	for (int i = 1; i < Frame_height; i++) {
		gotoxy(FrameX, FrameY + i);
		printf("‖"); //打印左竖框
		a[FrameX][FrameY + i] = 2;//标记左竖框为游戏边框，防止方块越界。
	};
	for (int i = 1; i < Frame_height; i++) {
		gotoxy(FrameX + 2 * Frame_width - 2, FrameY + i);
		printf("‖"); //打印右竖框
		a[FrameX + 2 * Frame_width - 2][FrameY + i] = 2;//标记右竖框为游戏边框，防止方块越界。
	};
}

/*
重新开始
*/
void Replay(struct Tetris *tetris) {
	system("cls");
	memset(a, 0, 6400 * sizeof(int));
	DrwaGameFrame();
	Gameplay();
}