#ifndef BLOCK_H_
#define BLOCK_H_

#include"glm\glm.hpp"
#include"Cube.h"

enum {
	TYEPE0,//�_
	TYEPE1,//L��
	TYEPE2,//�tL��
	TYEPE3,//Z��
	TYEPE4,//�tZ��
	TYEPE5,//�l�p
	TYEPE6//��
};

class Block :public Cube{
public:
	glm::vec3 m_position;
	int m_angle;
	int m_blockType;

	void control();

	//�e��ނ̃u���b�N�`��
	void drawType0();
	void drawType1();
	void drawType2();
	void drawType3();
	void drawType4();
	void drawType5();
	void drawType6();

	//�u���b�N���̂̕`��
	void draw();

	void update();

	Block();
};

void keyboard(unsigned char key, int x, int y);
void specialkeydown(int key, int x, int y);

extern Block *block;

#endif