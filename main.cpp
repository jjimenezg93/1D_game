#define WORLDSIZE 30
#define MOVELEFT 65
#define MOVERIGHT 68
#define SHOOTLEFT 81
#define SHOOTRIGHT 69

#pragma warning(disable: 4668)
#pragma warning(disable: 4710)
#pragma warning(disable: 4820)

#include <conio.h>
#include <cstdio>
#include <Windows.h>

int main() {
	char flag = '\0';
	unsigned short int key = 0;

	unsigned short int pos = WORLDSIZE / 2;
	short int posLBullet = -1;
	short int posRBullet = WORLDSIZE + 1;

	while (!flag) {
		for (unsigned short int i = 0; i < WORLDSIZE; i++) {
			if (i == posLBullet)
				printf("<");
			else if (i == posRBullet)
				printf(">");
			else if (i == pos)
				printf("X");
			else
				printf("-");
		}

		if (_kbhit()) {
			key = static_cast<unsigned short int>(toupper(_getch()));

			if (key == MOVELEFT && pos > 0)
				pos--;
			else if (key == MOVERIGHT && pos < WORLDSIZE - 1)
				pos++;
			else if (key == SHOOTLEFT && posLBullet <= -1)
				posLBullet = pos - 1;
			else if (key == SHOOTRIGHT && posRBullet >= WORLDSIZE + 1)
				posRBullet = pos + 1;
			else if (key == 27)
				flag = '1';
		}

		if (posLBullet >= 0)
			posLBullet--;

		if (posRBullet <= WORLDSIZE + 1)
			posRBullet++;

		Sleep(50);

		printf("\r");
	}
}