/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _GAMELOGIC_H
#define _GAMELOGIC_H

namespace GameLogic {
	void randomSpawnEnemy();
	void randomSpawnExtraPoint();

	void spawnBullet(const short int posBullet);
	void removeBullet(const int posBullet);

	void setEnemyPosition(const short int newPosition);
	void setExtraPointPosition(const short int newPosition);

	void updatePlayerPosition(const unsigned short int offset, const short int direction);	//direction = -1 left. direction = 1 right
	void updateEnemyPosition(const unsigned short int offset);
	void updateBulletsPosition(const unsigned short int offset);

	void addPoints(const unsigned short int points);

	bool isCollision(const int element1, const int element2);
}

#endif // !_GAMELOGIC_H