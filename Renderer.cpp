/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#include <cstdio>
#include <cstdlib>

#include "defs.h"
#include "Renderer.h"
#include "Metheorology.h"

namespace Renderer {
	void setMapPosition() {
		for (unsigned short int i = 0; i < SCROLL; i++)
			printf("\n");
	}

	void renderWorld() {
		for (unsigned short int i = 0; i < WORLDSIZE - 1; i++) {
			if (i == posLBullet)
				printf("<");
			else if (i == posRBullet)
				printf(">");
			else if (i == posPlayer)
				printf("X");
			else if (i == posEnemy)
				printf("|");
			else if (i == posExtraPoint)
				printf("P");
			else if (!intenseRain)
				printf("%c", Metheorology::rainFrame());
			else
				printf("%c", Metheorology::intenseRainFrame());
		}

		printf(" Points = %d/Lifes = %d", pointsPlayer, lifesPlayer);

		printf("\r");
	}

	void renderGameOver() {
		system("CLS");

		for (unsigned short int i = 0; i < SCROLL / 2; i++)
			printf("\n");

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
	}
}