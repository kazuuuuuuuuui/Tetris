#ifndef BLOCK_H_
#define BLOCK_H_

#include"glm\glm.hpp"

class Feald;

enum{
	Rotate0 = 0,
	Rotate90,
	Rotate180,
	Rotate270,
	RotateMax
};

//1ブロック単位で見た時の種類
enum{
	NORMAL = 0,
	WALL,
	TYPE_O,
	TYPE_I,
	TYPE_invT,
	TYPE_L,
	TYPE_invL,
	TYPE_Z,
	TYPE_invZ
};


void createBlock();
void fallBlock();
bool isHit(char _bloak[][4][4], int _x, int _y, int _rotate);
void lockBlock(char _bloak[][4][4], int _x, int _y, int _rotate);
void clearLine();

extern int gameScore;
extern int deleteLinesNumber;
extern int gameLevel;
extern char currentBlock[RotateMax][4][4];
extern Feald nextBlock[4][4];
extern Feald nextNextBlock[4][4];
extern int blockType;
extern int posX;
extern int posY;
extern int rotate;

#endif