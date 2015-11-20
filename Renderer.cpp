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
#include "Renderer.h"
#include "Metheorology.h"
#include "HighScores.h"

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