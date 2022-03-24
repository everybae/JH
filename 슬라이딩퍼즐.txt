#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <conio.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

#define KEY_UP (256 + 72)
#define KEY_DOWN (256 + 80)
#define KEY_LEFT (256 + 75)
#define KEY_RIGHT (256 + 77)
#define KEY_ESC 27

int GetKey(void);
void gotoxy(int x, int y);

int main()
{
	srand(time(NULL));

	int puzzle[5][5] = { { 9,9,9,9,9 },
						 { 9,1,2,3,9 },
						 { 9,4,5,6,9 },
						 { 9,7,8,0,9 },
						 { 9,9,9,9,9 }, };

	int victory[5][5] = {{ 9,9,9,9,9 },
						 { 9,1,2,3,9 },
						 { 9,4,5,6,9 },
						 { 9,7,8,0,9 },
						 { 9,9,9,9,9 }, };

	int randnum = 0; // 섞일 랜덤수 생성
	int temp;
	int i = 3, j = 3; // 0 의 위치
	int ch;
	int count = 0;


	for (int a = 0; a < 5; a++)
	{

		randnum = rand() % 4 + 1;

		if (randnum == UP)
		{
			if (puzzle[i - 1][j] != 9)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[i - 1][j];
				puzzle[i - 1][j] = temp;
				i--;
			}
		}
		else if (randnum == DOWN)
		{
			if (puzzle[i + 1][j] != 9)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[i + 1][j];
				puzzle[i + 1][j] = temp;
				i++;
			}
		}
		else if (randnum == LEFT)
		{
			if (puzzle[i][j - 1] != 9)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[i][j - 1];
				puzzle[i][j - 1] = temp;
				j--;
			}
		}
		else if (randnum == RIGHT)
		{
			if (puzzle[i][j + 1] != 9)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[i][j + 1];
				puzzle[i][j + 1] = temp;
				j++;
			}
		}
		gotoxy(0, 0);
		for (int n = 0; n < 5; n++)
		{
			for (int m = 0; m < 5; m++)
			{
				if (puzzle[n][m] == 9)
				{
					printf("■");
				}
				else if (puzzle[n][m] == 0)
				{
					printf("　");
				}
				else
				{
					printf("%d ", puzzle[n][m]);
				}
			}
			printf("\n");
		} // 퍼즐 출력
		//Sleep(10);
	} // 맵 생성 for문

	while (1)
	{
		(ch = GetKey());
		switch (ch)
		{
		case KEY_UP:
			if (puzzle[i - 1][j] != 9)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[i - 1][j];
				puzzle[i - 1][j] = temp;
				i--;
			}
			break;
		case KEY_DOWN:
			if (puzzle[i + 1][j] != 9)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[i + 1][j];
				puzzle[i + 1][j] = temp;
				i++;
			}
			break;
		case KEY_LEFT:
			if (puzzle[i][j - 1] != 9)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[i][j - 1];
				puzzle[i][j - 1] = temp;
				j--;
			}
			break;
		case KEY_RIGHT:
			if (puzzle[i][j + 1] != 9)
			{
				temp = puzzle[i][j];
				puzzle[i][j] = puzzle[i][j + 1];
				puzzle[i][j + 1] = temp;
				j++;
			}
			break;
		}
		gotoxy(0, 0);
		for (int n = 0; n < 5; n++)
		{
			for (int m = 0; m < 5; m++)
			{
				if (puzzle[n][m] == 9)
				{
					printf("■");
				}
				else if (puzzle[n][m] == 0)
				{
					printf("　");
				}
				else
				{
					printf("%d ", puzzle[n][m]);
				}
			}
			printf("\n");
		} // 퍼즐 출력

		for (int i = 1; i < 4; i++)
		{
			for (int j = 1; j < 4; j++)
			{
				if (puzzle[i][j] == victory[i][j])
				{
					count++;
				}
			}
		}
		if (count == 9)
		{
			printf("정답입니다\n");
			break;
		}
		else if (count != 9)
		{
			count = 0;
		}
	}
}

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

int GetKey(void)
{
	int ch = _getch();

	if (ch == 0 || ch == 224)
		ch = 256 + _getch();
	return ch;
}