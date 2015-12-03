#ifndef BLOCK_H_
#define BLOCK_H_

#include"glm\glm.hpp"
#include"Cube.h"

enum {
	TYEPE0,//棒
	TYEPE1,//L字
	TYEPE2,//逆L字
	TYEPE3,//Z字
	TYEPE4,//逆Z字
	TYEPE5,//四角
	TYEPE6//凸
};

class Block :public Cube{
public:
	glm::vec3 m_position;
	int m_angle;
	int m_blockType;

	void control();

	//各種類のブロック描画
	void drawType0();
	void drawType1();
	void drawType2();
	void drawType3();
	void drawType4();
	void drawType5();
	void drawType6();

	//ブロック自体の描画
	void draw();

	void update();

	Block();
};

void keyboard(unsigned char key, int x, int y);
void specialkeydown(int key, int x, int y);

extern Block *block;

#endif