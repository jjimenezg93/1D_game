/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#pragma warning(disable: 4514)
#pragma warning(disable: 4548)
#pragma warning(disable: 4710)

#include <map>

#include "HighScores.h"
#include "defs.h"

static std::map<unsigned short int, char *> m_scores;

void insertScore(const unsigned short int newScore);
bool checkScoreIsHighScore(const unsigned short int score);		//returns if score must be added or not
void deletePair(unsigned short int scoreToFree);

namespace HighScores {
	int getNewScore(const unsigned short int newScore) {
		if (m_scores.size() < HIGHSCORESIZE) {
			insertScore(newScore);

			return 0;
		} else if (checkScoreIsHighScore(newScore)) {
			insertScore(newScore);

			return 0;
		}

		return 1;
	}

	void printHighScores() {
		//reverse iterator to show it in descending order
		for (std::map<unsigned short int, char *>::reverse_iterator reverseIt = m_scores.rbegin(); reverseIt != m_scores.rend(); reverseIt++) {
			printf("%s : ", reverseIt->second);
			printf("%d points\n\n", reverseIt->first);
		}
	}

	void freeNames() {
		for (std::map<unsigned short int, char *>::iterator it = m_scores.begin(); it != m_scores.end(); it++) {
			free(it->second);
		}
	}
}

void insertScore(const unsigned short int newScore) {
	printf("\n\nEnter your name (max. %d chars): ", NAMESIZE);
	char * name = (char *)malloc(NAMESIZE * sizeof(char));
	scanf_s("%s", name, NAMESIZE);

	//only adds if there is no one with that score
	if (m_scores.find(newScore) == m_scores.end()) {
		m_scores.insert({ newScore , name });
		if (m_scores.size() > HIGHSCORESIZE)
			deletePair(m_scores.begin()->first);
	}
}

bool checkScoreIsHighScore(const unsigned short int score) {
	if (!(m_scores.size()))
		return true;
	else {
		for (std::map<unsigned short int, char *>::iterator it = m_scores.begin(); it != m_scores.end(); it++) {
			if (score > it->first)
				return true;
		}

		return false;
	}
}

void deletePair(unsigned short int scoreToFree) {
	if (m_scores.size()) {
		free(m_scores.find(scoreToFree)->second);
		m_scores.erase(m_scores.find(scoreToFree));
	}
}