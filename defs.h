/*
** Author: Julian Jimenez Gonzalez (jjimenezg93)
*/

#ifndef _DEFS_H
#define _DEFS_H

#define WORLDSIZE 41
#define MOVELEFT 65
#define MOVERIGHT 68
#define SHOOTLEFT 81
#define SHOOTRIGHT 69
#define ESC 27
#define SCROLL 14
#define SPEED 1
#define COLLISIONTHRESHOLD 1

extern char flagLoop;

extern unsigned short int posPlayer;

extern short int posEnemy;
extern short int dirEnemy;

extern short int posLBullet;
extern short int posRBullet;

extern short int lifesPlayer;
extern short int pointsPlayer;

extern short int posExtraPoint;

extern unsigned char rainFrames[3];

extern bool intenseRain;

#endif	// !_DEFS_H