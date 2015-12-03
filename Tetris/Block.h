#ifndef BLOCK_H_
#define BLOCK_H_

#include"glm\glm.hpp"
#include"Cube.h"

enum {
	TYEPE0,//–_
	TYEPE1,//Lš
	TYEPE2,//‹tLš
	TYEPE3,//Zš
	TYEPE4,//‹tZš
	TYEPE5,//lŠp
	TYEPE6//“Ê
};

class Block :public Cube{
public:
	glm::vec3 m_position;
	int m_angle;
	int m_blockType;

	void control();

	//Šeí—Ş‚ÌƒuƒƒbƒN•`‰æ
	void drawType0();
	void drawType1();
	void drawType2();
	void drawType3();
	void drawType4();
	void drawType5();
	void drawType6();

	//ƒuƒƒbƒN©‘Ì‚Ì•`‰æ
	void draw();

	void update();

	Block();
};

void keyboard(unsigned char key, int x, int y);
void specialkeydown(int key, int x, int y);

extern Block *block;

#endif