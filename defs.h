/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _DEFS_H
#define _DEFS_H

#include <list>

#define WORLDSIZE 41
#define MOVELEFT 65
#define MOVERIGHT 68
#define SHOOTLEFT 81
#define SHOOTRIGHT 69
#define ESC 27
#define SCROLL 14
#define SPEED 1
#define COLLISIONTHRESHOLD 1
#define NAMESIZE 15
#define HIGHSCORESIZE 3

extern char flagApp;
extern char flagGame;

extern unsigned short int posPlayer;
extern short int lifesPlayer;
extern unsigned short int pointsPlayer;

extern short int posEnemy;
extern short int dirEnemy;

extern short int posExtraPoint;

extern unsigned char rainFrames[3];

extern bool intenseRain;

extern std::list<int> listBullets;
extern std::list<int>::iterator itrListBullets;

#endif	// !_DEFS_H