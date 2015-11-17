/*
** Author: Julián Jiménez González (jjimenezg93)
*/

#define WORLDSIZE 41
#define MOVELEFT 65
#define MOVERIGHT 68
#define SHOOTLEFT 81
#define SHOOTRIGHT 69
#define SCROLL 14

#pragma warning(disable: 4668)
#pragma warning(disable: 4710)
#pragma warning(disable: 4820)

#include <conio.h>
#include <cstdio>
#include <cstdlib>
#include <Windows.h>

int main() {
	char flag = '\0';
	unsigned short int key = 0;

	unsigned short int playerPos = WORLDSIZE / 2;

	short int enemyPos = 0;
	short int enemyDir = -1;

	short int posLBullet = -2;		//if set to -1, on enemy spawn: posLBullet = -1, enemyPos = 0 -> instantly kills enemy when it spawns on the left
	short int posRBullet = WORLDSIZE + 1;

	short int playerLifes = 3;
	short int playerPoints = 0;

	short int extraPointPos = -1;

	for (unsigned short int i = 0; i < SCROLL; i++)
		printf("\n");

	while (!flag) {
		for (unsigned short int i = 0; i < WORLDSIZE - 1; i++) {
			if (i == posLBullet)
				printf("<");
			else if (i == posRBullet)
				printf(">");
			else if (i == playerPos)
				printf("X");
			else if (i == enemyPos)
				printf("|");
			else if (i == extraPointPos)
				printf("V");
			else
				printf("-");
		}

		//input management
		if (_kbhit()) {
			key = static_cast<unsigned short int>(toupper(_getch()));

			if (key == MOVELEFT && playerPos > 0)
				playerPos--;
			else if (key == MOVERIGHT && playerPos < WORLDSIZE - 1)
				playerPos++;
			else if (key == SHOOTLEFT && posLBullet <= -1 && !(posRBullet <= WORLDSIZE))
				posLBullet = playerPos - 1;
			else if (key == SHOOTRIGHT && posRBullet >= WORLDSIZE + 1 && !(posLBullet >= 0))
				posRBullet = playerPos + 1;
			else if (key == 27)
				flag = '1';
		}

		//enemy random spawn. One at a time
		if (enemyPos < 0 || enemyPos > WORLDSIZE) {
			if (rand() % 2) {
				enemyPos = 0;
				enemyDir = 1;
			} else {
				enemyPos = WORLDSIZE;
				enemyDir = -1;
			}
		}

		if (!(rand() % 100))
			extraPointPos = rand() % WORLDSIZE;

		//enemy - bullets collisions
		if (abs(enemyPos - posLBullet) <= 1) {
			playerPoints += 5;
			posLBullet = -1;
			enemyPos = -1;
		}

		if (abs(enemyPos - posRBullet) <= 1) {
			playerPoints += 5;
			posRBullet = WORLDSIZE + 1;
			enemyPos = -1;
		}

		//enemy & bullets position update
		if (enemyPos >= 0 && enemyPos <= WORLDSIZE)
			enemyPos += enemyDir;

		if (posLBullet >= -1)
			posLBullet--;

		if (posRBullet <= WORLDSIZE + 1)
			posRBullet++;

		//extraPoint collisions
		if (abs(enemyPos - extraPointPos) <= 1)
			extraPointPos = -1;

		if (abs(playerPos - extraPointPos) <= 1) {
			extraPointPos = -1;
			playerPoints += 100;
		}

		//enemy - player collision
		if (abs(enemyPos - playerPos) <= 1) {
			if (playerLifes == 0) {
				printf("\r");

				for (unsigned short int i = 0; i < WORLDSIZE / 2; i++)
					printf("\\/");

				break;
			} else {
				playerLifes--;
				enemyPos = -1;
			}
		}

		printf(" Points = %d/Lifes = %d", playerPoints, playerLifes);

		Sleep(50);

		printf("\r");
	}

	getchar();

	return 0;
}