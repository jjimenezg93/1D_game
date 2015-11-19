/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4668)
#pragma warning(disable: 4710)
#pragma warning(disable: 4820)

#include <conio.h>
#include <cstdio>
#include <Windows.h>

#include "defs.h"
#include "Renderer.h"
#include "GameLogic.h"

char flagLoop = '\0';

unsigned short int posPlayer = WORLDSIZE / 2;

short int posEnemy = -1;
short int dirEnemy = -1;

short int posLBullet = posEnemy -(COLLISIONTHRESHOLD + 1);		//must avoid having posEnemy = -1 and posLBullet = -2, since it would instantly kill enemy with COLLISIONTHRESHOLD >= 1
short int posRBullet = WORLDSIZE + 2;

short int lifesPlayer = 3;
short int pointsPlayer = 0;

short int posExtraPoint = -1;

unsigned char rainFrames[3] = { '`', '-', '.' };
bool intenseRain = false;		//change for fun

int main() {
	unsigned short int key = 0;

	Renderer::setMapPosition();

	while (!flagLoop) {
		Renderer::renderWorld();

		//input management
		if (_kbhit()) {
			key = static_cast<unsigned short int>(toupper(_getch()));

			if (key == MOVELEFT && posPlayer > 0)
				GameLogic::updatePlayerPosition(1, -1);
			else if (key == MOVERIGHT && posPlayer < WORLDSIZE - 1)
				GameLogic::updatePlayerPosition(1, 1);
			else if (key == SHOOTLEFT && posLBullet <= -(1 + COLLISIONTHRESHOLD) && !(posRBullet <= WORLDSIZE))
				GameLogic::setBulletPosition(&posLBullet, posPlayer - 1);
			else if (key == SHOOTRIGHT && posRBullet >= WORLDSIZE + 2 && !(posLBullet >= 0))
				GameLogic::setBulletPosition(&posRBullet, posPlayer + 1);
			else if (key == ESC)
				flagLoop = '1';
		}

		//random spawn enemy & extraPoint. One at a time each
		GameLogic::randomSpawnEnemy();
		GameLogic::randomSpawnExtraPoint();

		//enemy - bullets collisions
		if (GameLogic::isCollision(posEnemy, posLBullet)) {
			GameLogic::addPoints(5);
			GameLogic::setBulletPosition(&posLBullet, -(1 + COLLISIONTHRESHOLD + 1));
			GameLogic::setEnemyPosition(-1);
		}

		if (GameLogic::isCollision(posEnemy, posRBullet)) {
			GameLogic::addPoints(5);
			GameLogic::setBulletPosition(&posRBullet, WORLDSIZE + 1);
			GameLogic::setEnemyPosition(-1);
		}

		//enemy & bullets position update
		GameLogic::updateEnemyPosition(SPEED);
		GameLogic::updateBulletsPosition(SPEED);

		//extraPoint collisions - enemy & player
		if (GameLogic::isCollision(posEnemy, posExtraPoint))
			GameLogic::setExtraPointPosition(-(1 + COLLISIONTHRESHOLD + 1));

		if (GameLogic::isCollision(posPlayer, posExtraPoint)) {
			GameLogic::setExtraPointPosition(-(1 + COLLISIONTHRESHOLD + 1));
			GameLogic::addPoints(100);
		}

		//enemy - player collision
		if (GameLogic::isCollision(posPlayer, posEnemy)) {
			if (lifesPlayer == 0) {
				Renderer::renderGameOver();
				break;
			} else {
				lifesPlayer--;
				GameLogic::setEnemyPosition(-1);
			}
		}

		Sleep(50);
	}

	getchar();

	return 0;
}