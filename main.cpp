/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4548)
#pragma warning(disable: 4668)
#pragma warning(disable: 4710)
#pragma warning(disable: 4820)

#include <conio.h>
#include <cstdio>
#include <list>
#include <Windows.h>

#include "defs.h"
#include "GameLogic.h"
#include "HighScores.h"
#include "Renderer.h"

char flagApp = '\0';
char flagGame;

unsigned short int posPlayer;

short int posEnemy;
short int dirEnemy;

short int posLBullet;		//must avoid having posEnemy = -1 and posLBullet = -2, since it would instantly kill enemy with COLLISIONTHRESHOLD >= 1
short int posRBullet;

short int lifesPlayer;
unsigned short int pointsPlayer;

short int posExtraPoint = -1;

unsigned char rainFrames[3] = { '`', '-', '.' };
bool intenseRain = false;		//set to true for fun

std::list<int> listBullets;
std::list<int>::iterator itrListBullets;

void initVars() {
	flagGame = '\0';

	posPlayer = WORLDSIZE / 2;

	posEnemy = -1;
	dirEnemy = -1;

	posLBullet = posEnemy - (COLLISIONTHRESHOLD + 1);		//must avoid having posEnemy = -1 and posLBullet = -2, since it would instantly kill enemy with COLLISIONTHRESHOLD >= 1
	posRBullet = WORLDSIZE + 2;

	lifesPlayer = 2;
	pointsPlayer = 0;
}

int main() {
	unsigned short int key = 0;

	while (!flagApp) {
		Renderer::renderMainMenu();

		if (_kbhit()) {
			key = static_cast<unsigned short int>(toupper(_getch()));

			if (key == ESC) {
				flagApp = '1';
				break;
			} else {
				Renderer::cleanScreen();
				Renderer::setMapPosition();

				initVars();

				while (!flagGame) {
					Renderer::renderWorld();
					Renderer::renderUI();

					//input management
					if (_kbhit()) {
						key = static_cast<unsigned short int>(toupper(_getch()));

						if (key == MOVELEFT && posPlayer > 0)
							GameLogic::updatePlayerPosition(1, -1);
						else if (key == MOVERIGHT && posPlayer < WORLDSIZE - 1)
							GameLogic::updatePlayerPosition(1, 1);
						else if (key == SHOOTLEFT)
							//GameLogic::setBulletPosition(&posLBullet, posPlayer - 1);
							GameLogic::spawnBullet(posPlayer - 1);
						else if (key == SHOOTRIGHT)
							//GameLogic::setBulletPosition(&posRBullet, posPlayer + 1);
							GameLogic::spawnBullet(posPlayer + 1);
						else if (key == ESC) {
							flagGame = '1';
							break;
						}
					}

					//random spawn enemy & extraPoint. One at a time each
					GameLogic::randomSpawnEnemy();
					GameLogic::randomSpawnExtraPoint();

					//enemy - bullets collisions
					for (itrListBullets = listBullets.begin(); itrListBullets != listBullets.end(); itrListBullets++) {
						if (GameLogic::isCollision((*itrListBullets), posEnemy)) {
							pointsPlayer += 5;
							GameLogic::removeBullet(*itrListBullets);
							break;
						}
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
							HighScores::getNewScore(pointsPlayer);
							break;
						} else {
							lifesPlayer--;
							GameLogic::setEnemyPosition(-1);
						}
					}

					Sleep(50);
				}
			}
		}
	}

	HighScores::freeNames();		//this deallocates memory stored for names

	Renderer::cleanScreen();
	getchar();

	return 0;
}