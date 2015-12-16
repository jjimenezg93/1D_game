/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4548)
#pragma warning(disable: 4668)
#pragma warning(disable: 4710)
#pragma warning(disable: 4820)

#include <cstdio>
#include <cstdlib>
#include <Windows.h>

#include "defs.h"
#include "HighScores.h"
#include "Metheorology.h"
#include "Renderer.h"

namespace Renderer {
	void setMapPosition() {
		for (unsigned short int i = 0; i < SCROLL; i++)
			printf("\n");
	}

	void cleanScreen() {
		system("CLS");
	}

	void renderMainMenu() {
		cleanScreen();
		printf("\nPress any key to start a new game or ESC to exit");
		renderScore();
		Sleep(200);
	}

	void renderWorld() {
		itrListBullets = listBullets.begin();
		bool posIsBullet;

		for (unsigned short int i = 0; i < WORLDSIZE - 1; i++) {
			posIsBullet = false;
			itrListBullets = listBullets.begin();
			while (itrListBullets != listBullets.end()) {
				if (i == *itrListBullets) {
					if (*itrListBullets < posPlayer)
						printf("<");
					else if (*itrListBullets > posPlayer)
						printf(">");
					posIsBullet = true;
					break;
				}

				itrListBullets++;
			}

			if (!posIsBullet && i == posPlayer)
				printf("X");
			else if (!posIsBullet && i == posEnemy)
				printf("|");
			else if (!posIsBullet && !intenseRain && !(i == posExtraPoint))
				printf("%c", Metheorology::rainFrame());
			else if (!posIsBullet && !(i == posExtraPoint))
				printf("%c", Metheorology::intenseRainFrame());
			else if (!posIsBullet && i == posExtraPoint)
				printf("P");
		}
	}

	void renderUI() {
		printf(" Points = %d/Lifes = %d", pointsPlayer, lifesPlayer);

		printf("\r");
	}

	void renderGameOver() {
		cleanScreen();

		printf(" _________    ________     ___        ___     ______\n");
		printf("|            |        |   |   \\      /   |   |    \n");
		printf("|            |        |   |    \\    /    |   |    \n");
		printf("|   _____    |________|   |     \\__/     |   |____  \n");
		printf("|        |   |        |   |              |   |    \n");
		printf("|________|   |        |   |              |   |______\n");

		printf(" ________                   _______  _______\n");
		printf("|        |   \\          /  |        |      |\n");
		printf("|        |    \\        /   |        |      |\n");
		printf("|        |     \\      /    |__      |______|\n");
		printf("|        |      \\    /     |        |   \\\n");
		printf("|________|       \\__/      |______  |    \\\n");
		

		printf("\n");
		renderScore();
	}

	void renderScore() {
		printf("\n\nHIGHSCORES \n\n");
		HighScores::printHighScores();
	}
}