#ifndef FEALD_H_
#define FEALD_H_

#define FEALD_WIDTH (12)
#define FEALD_HEIGHT (25)

#define FEALD_Y_TOP (3)
#define FEALD_Y_BUTTOM (22)


#include"glm\glm.hpp"
#include"Block.h"

enum{
	NORMAL = 0,
	WALL
};

class Feald{
public:
	char m_type;
	glm::vec3 m_position;

	void draw();

	//コンストラクタ
	Feald(){
		m_type = NORMAL;
		m_position.x = 0.f;
		m_position.y = 0.f;
		m_position.z = 0.f;
	};

};

void setCube();

extern Feald *feald[FEALD_HEIGHT][FEALD_WIDTH];
extern Feald *buffer[FEALD_HEIGHT][FEALD_WIDTH];

#endif