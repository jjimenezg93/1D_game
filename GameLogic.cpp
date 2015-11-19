/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#include <cstdio>
#include <cstdlib>

#include "GameLogic.h"
#include "defs.h"

namespace GameLogic {
	void randomSpawnEnemy() {
		if (posEnemy < 0 || posEnemy > WORLDSIZE) {
			if (rand() % 2) {
				setEnemyPosition(0);
				dirEnemy = 1;
			} else {
				setEnemyPosition(WORLDSIZE);
				dirEnemy = -1;
			}
		}
	}

	void randomSpawnExtraPoint() {
		if (!(rand() % 100))
			posExtraPoint = rand() % WORLDSIZE;
	}

	void setEnemyPosition(const short int newPosition) {
		posEnemy = newPosition;
	}
	
	void setBulletPosition(short int * const ptrBullet, const short int newPosition) {
		*ptrBullet = newPosition;
	}

	void setExtraPointPosition(const short int newPosition) {
		posExtraPoint = newPosition;
	}

	void updatePlayerPosition(const unsigned short int offset, const short int direction) {
		posPlayer += offset * direction;
	}

	void updateEnemyPosition(const unsigned short int offset) {
		if (posEnemy >= 0 && posEnemy <= WORLDSIZE)
			posEnemy += offset * dirEnemy;
	}

	void updateBulletsPosition(const unsigned short int offset) {
		if (posLBullet >= -1)
			posLBullet -= offset;

		if (posRBullet <= WORLDSIZE + 1)
			posRBullet += offset;
	}

	void addPoints(const unsigned short int points) {
		pointsPlayer += points;
	}

	bool isCollision(const int element1, const int element2) {
		if (abs(element1 - element2) <= COLLISIONTHRESHOLD)
			return true;
		else
			return false;
	}
}