/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _HIGHSCORES_H
#define _HIGHSCORES_H

namespace HighScores {
	int getNewScore(const unsigned short int newScore);		//returns 0 if new score added, 1 if it is not a HighScore, other returns are left for error codes

	void printHighScores();		//calls Renderer::renderScore

	//bool checkScoreIsHighScore(const unsigned short int score);		//returns if score must be added or not

	void freeNames();

	//void deletePair(unsigned short int score);
}

#endif // !_HIGHSCORES_H