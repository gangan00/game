
#define  _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<windows.h>//����DOS���棨��ȡ����̨�ϵ�����λ�ã�����������ɫ��
#include<conio.h>//���ռ������������_kbhit()��_getch())
#include<time.h>//���ڻ�������
#include<stdlib.h>

/*�궨��*/
#define FrameX 13 //��Ϸ�������Ͻ�x������
#define FrameY 3 //��Ϸ�������Ͻ�y������
#define Frame_height 20 //��Ϸ���ڵĸ߶�
#define Frame_width 18 //��Ϸ���ڵĿ��
int temp, temp1, temp2;//���ڼ�ס��ת�����������ֵ
struct Tetris {
	//����ĸ�����Ϣ
	int x;
	int y;
	int flag;
	int next;
	int speed;
	int number;
	int score;
	int level;

};
HANDLE hOut; //����̨�����
int b[4] = { 0,0,0,0 };//����ĸ����ڡ����飺1��ʾ�з��飬0��ʾ�޷��飻
char ch;
int a[80][80] = { 0 };
extern void gotoxy(int x, int y);
extern int color(int c);
extern void welcome();

/*

����˹���鹲�����ֻ���ͼ�Σ�19����ת���͡�
*/

void MakeTetris(struct Tetris * tetris) {

	a[tetris->x][tetris->y] = b[0];//���ķ���λ�õ�ͼ��״̬��
	switch (tetris->flag) {
	case 1:
		color(10);//��
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x + 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;

	case 2:
		color(13);//ֱ�� -
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y] = b[2];
		a[tetris->x + 4][tetris->y] = b[3];
		break;

	case 3:
		color(13);//ֱ������ |
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
					����
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
		color(14);// Z ��ת
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x - 2][tetris->y] = b[2];
		a[tetris->x - 2][tetris->y + 1] = b[3];
		break;
	case 10:
		color(14);// Z ��ת
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x - 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 11:
		color(14);// ˳ʱ�� Z ��ת
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
		color(12);// ˳ʱ���ʮ�� 7
		a[tetris->x][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 14:
		color(12);// ˳ʱ��180 7
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y + 1] = b[3];
		break;
	case 15:
		color(12);// ˳ʱ��270 7
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x - 2][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 16:
		color(9);// ��ת 7
		a[tetris->x][tetris->y + 1] = b[1];
		a[tetris->x][tetris->y - 1] = b[2];
		a[tetris->x + 2][tetris->y - 1] = b[3];
		break;
	case 17:
		color(9);// ��ʱ��90 7
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y + 1] = b[2];
		a[tetris->x + 2][tetris->y] = b[3];
		break;
	case 18:
		color(9);// ��ʱ��180 7
		a[tetris->x][tetris->y - 1] = b[1];
		a[tetris->x][tetris->y + 1] = b[2];
		a[tetris->x - 2][tetris->y + 1] = b[3];
		break;
	case 19:
		color(9);// ��ʱ��180 7
		a[tetris->x - 2][tetris->y] = b[1];
		a[tetris->x + 2][tetris->y] = b[2];
		a[tetris->x - 2][tetris->y - 1] = b[3];
		break;

	}

}


void PrintTetris(struct Tetris *tetris) {

	for (int i = 0; i < 4; i++) b[i] = 1; //�Ȱ�b[i]���ֵ����Ϊ1 �����ʱ��Ϊɶ��ֱ����Ϊ1
	MakeTetris(tetris);//ͨ��������� �ͱ����˶�Ӧλ��ͼ����Ҫ��һ����������� 
	for (int i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
		for (int j = tetris->y - 2; j <= tetris->y + 1; j++) {
			//�ĸ�ֵҲֻ����า�ǵ�����
			if (a[i][j] == 1 && j > FrameY) {
				//J��ֵҪ����Ϸ��������
				gotoxy(i, j);
				printf("��");
			}
		}
	}
	//��ӡ�˵���Ϣ
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
�жϷ����Ƿ�����ƶ�
*/

int ifMove(struct Tetris *tetris) {
	//�ǳ����鷳 ��Ҫ���ж����ķ����Ƿ�Ϊ�� ���жϸ���λ�����Ƿ�Ϊ�� �ٸ��ݲ�ͬ�ķ�����״ �ж��Ƿ����ƶ�

	if (a[tetris->x][tetris->y] != 0) return 0;//�����ƶ�
	//��������� 
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
�������ĺۼ�
*/
void CleanTetris(struct Tetris *tetris) {

	for (int i = 0; i < 4; i++) b[i] = 0; //��b[i]���ֵ����Ϊ0

	MakeTetris(tetris);//ͨ��������� ��Ҫ�����������ı�־��Ϊ0��
	for (int i = tetris->x - 2; i <= tetris->x + 4; i += 2) {
		for (int j = tetris->y - 2; j <= tetris->y + 1; j++) {
			//�ĸ�ֵҲֻ����า�ǵ�����
			if (a[i][j] == 0 && j > FrameY) {
				//J��ֵҪ����Ϸ��������
				gotoxy(i, j);
				printf("  ");//���

			}
		}

	}
}
void CleanTetrisall(struct Tetris *tetris) {

	for (int i = tetris->x - 4; i <= tetris->x + 4; i += 2) {
		for (int j = tetris->y - 2; j <= tetris->y + 2; j++) {
			//�ĸ�ֵҲֻ����า�ǵ�����

			a[i][j] = 0;//ȫ�����
			gotoxy(i, j);
			printf("  ");//���
		}
	}

}

/*
�ж��Ƿ�����
*/

void Del_Fullline(struct Tetris *tetris) {
	int k, del_rows = 0;//kΪĳ�з���ĸ��� 
	for (int j = FrameY + Frame_height - 1; j >= FrameY + 1; j--) {

		k = 0;
		for (int i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2) {

			//���Ǳ���������Ļ
			if (a[i][j] == 1) {
				k++;
				if (k == Frame_width - 2) {
					//����
					for (k = FrameX + 2; i < FrameX + 2 * Frame_width - 2; k += 2) {
						a[k][j] = 0;
						gotoxy(k, j);
						printf(" ");//ɾ�����еķ���
					}
					//ɾ��������ķ��黹��Ҫ�����ƶ�һ��
					for (k = j - 1; k >= FrameY; k--) {
						for (int i = FrameX + 2; i < FrameX + 2 * Frame_width - 2; i += 2) {
							//���Ǳ�����ɾ���е���һ�е�������Ļ
							if (a[i][k] == 1) {

								a[i][k] = 0;
								gotoxy(i, k);
								printf(" ");//ɾ��ԭ���ķ���
								gotoxy(i, k + 1);//y������һ��
								printf("��");
							}

						}

					}
					j++;//�����ж���û�����еģ���������j-- ���һ�����ü��� ����һ��֮�� ��ǰ�л�����Ҫ�ٴ��ж�
					del_rows++;//ɾ����������
				}

			}

		}


	}

	tetris->score += 100 * del_rows;//ɾ��һ��100��
	if (del_rows > 0 && (tetris->score % 1000 == 0 || tetris->score / 1000 > tetris->level - 1)) {

		tetris->speed -= 20;
		tetris->level++; // ����
	}

}//��ĳ����Frame_width-2������ʱ ������

/*
��������������

*/
void Flag(struct Tetris *tetris) {
	tetris->number++;//��ס��������ĸ�����
	srand(time(NULL));//��ʼ�������
	if (tetris->number == 1) {

		tetris->flag = rand() % 19;//�õ���һ���������ţ���Ϊflag��0-19������ȡ����19�������õ�0-18�������
		tetris->next = rand() % 19;//�õ���һ���������� �ұ���һ�������Ԥ������
	}
	else
	{
		tetris->flag = tetris->next; //����һ��next��ֵ��flag
		tetris->next = rand() % 19;//�õ���һ���������� �ұ���һ�������Ԥ������

	}


}

/*
��ʼ��Ϸ
*/
void Gameplay() {


	struct Tetris t;//����ṹ��
	struct Tetris *tetris = &t;//�ṹ��ָ��ָ��ṹ�����
	//��ʼ������ֵ
	t.number = 0;
	t.score = 0;
	t.speed = 100;
	t.level = 1;
	while (1)
	{

		Flag(tetris);//�õ����
		tetris->flag = tetris->flag % 19 + 1; //����һ��next��ֵ��flag
		tetris->next = tetris->next % 19 + 1;
		temp = tetris->flag;//��ǰ�������
		tetris->x = FrameX + 2 * Frame_width + 6;//Ԥ������X����
		tetris->y = FrameY + 10;//Ԥ������Y����
		tetris->flag = tetris->next;//�����һ�����
		CleanTetrisall(tetris);//����Ԥ�������ֵΪ0��Ϊ�˱����´��ظ���ӡ
		PrintTetris(tetris);//��ӡԤ������

		tetris->x = FrameX + Frame_width;//��Ϸ����X����
		tetris->y = FrameY - 1;//��Ϸ����Y����		
		tetris->flag = temp;

		//CleanTetrisall(tetris);
		//printf("��ǰflag %d", tetris->flag);
		/*for (int i = 0; i < 80; i++) {
			for (int j = 0; j < 80; j++) {
				if (a[i][j] == 1) {

					printf("a[%d][%d]=1\n", i, j);
				}
			}
		}*/
		//��ȡ����
		while (1)
			//���Ʒ��� ֱ���������ƶ�
		{
			setbuf(stdin, NULL);
			fflush(stdin);//�����������
		label:PrintTetris(tetris);//��ӡ���飻
			Sleep(tetris->speed);//�ӻ�ʱ��
			CleanTetris(tetris);//����ۼ�
			temp1 = tetris->x;//��ס���ķ���ĺ�����
			temp2 = tetris->flag;//��ס���ķ��������

			if (_kbhit() && ifMove(tetris)) {
				//�������������
				ch = _getch();
				//ch = getchar();
				
				setbuf(stdin, NULL);
				fflush(stdin);
				if (ch == 75 && tetris->x > FrameX + 4) {
					//���
					tetris->x -= 2;
				}
				else if (ch == 77 && tetris->x < FrameX + 2 * Frame_width - 7) {
					//�Ҽ�
					tetris->x += 2;
					
					//gotoxy(tetris->y, (FrameX + 2 * Frame_width - 4));
				//printf("x:%d", tetris->x);
					//printf("�߽�:%d", FrameX + 2 * Frame_width - 6);
				}
				else if (ch == 80) {
					//�¼� ��������

					//�ж��Ƿ����ƶ�
					if (ifMove(tetris) && tetris->y < FrameY + Frame_height) {

						tetris->y += 2;
					}
					//else {
					//	tetris->y = FrameY + Frame_height - 2;
					//}
				}
				else if (ch == 72) {
					//�ϼ� ��ʼ���ֱ仯
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
					//�ո� ��ͣ
					PrintTetris(tetris);
					while (1)
					{
						if (_kbhit()) {
							//�ٰ��ո���ͼ���
							ch = _getch();
							if (ch == 32) goto label;
						}

					}

				}
				else if (ch == 27) {
					//�˳�
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
				tetris->y++;//û�в����������ƶ�

			if (ifMove(tetris) == 0) {
				//���ܶ��� �ͷ�������
				//printf("����һ��");
				tetris->y--;
				PrintTetris(tetris);
				Del_Fullline(tetris); //��������ж���ô�����е�
				setbuf(stdin, NULL);
				fflush(stdin);
				break;
			}
		}

	}
}
/*
������Ϸ����
*/
void DrwaGameFrame() {

	gotoxy(FrameX + Frame_width - 5, FrameY - 2);
	color(11);
	printf("����˿�����~");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 7);
	color(2);
	printf("*********");//�ϱ߿�
	gotoxy(FrameX + 2 * Frame_width + 13, FrameY + 7);
	color(3);
	printf("��һ���ַ���:");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 13);
	color(2);
	printf("*********");//�±߿�
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 17);
	color(14);
	printf("���� �� ��ת");

	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 19);
	printf("�ո� ����ͣ��Ϸ");
	gotoxy(FrameX + 2 * Frame_width + 3, FrameY + 15);
	printf("Esc �� �˳���Ϸ");
	gotoxy(FrameX, FrameY);
	color(12);
	printf("�X");
	gotoxy(FrameX + 2 * Frame_width - 2, FrameY);
	printf("�[");

	gotoxy(FrameX, FrameY + Frame_height);
	printf("�^");
	gotoxy(FrameX + 2 * Frame_width - 2, FrameY + Frame_height);
	printf("�a");
	for (int i = 2; i < 2 * Frame_width - 2; i += 2) {
		gotoxy(FrameX + i, FrameY);
		printf("�T");
	};
	for (int i = 2; i < 2 * Frame_width - 2; i += 2) {
		gotoxy(FrameX + i, FrameY + Frame_height);
		printf("�T"); //��ӡ�º��
		a[FrameX + i][FrameY + Frame_height] = 2;//����º��Ϊ��Ϸ�߿򣬷�ֹ����Խ�硣
	};
	for (int i = 1; i < Frame_height; i++) {
		gotoxy(FrameX, FrameY + i);
		printf("��"); //��ӡ������
		a[FrameX][FrameY + i] = 2;//���������Ϊ��Ϸ�߿򣬷�ֹ����Խ�硣
	};
	for (int i = 1; i < Frame_height; i++) {
		gotoxy(FrameX + 2 * Frame_width - 2, FrameY + i);
		printf("��"); //��ӡ������
		a[FrameX + 2 * Frame_width - 2][FrameY + i] = 2;//���������Ϊ��Ϸ�߿򣬷�ֹ����Խ�硣
	};
}

/*
���¿�ʼ
*/
void Replay(struct Tetris *tetris) {
	system("cls");
	memset(a, 0, 6400 * sizeof(int));
	DrwaGameFrame();
	Gameplay();
}