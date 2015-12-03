#ifndef FEALD_H_
#define FEALD_H_

#define FEALD_WIDTH (12)
#define FEALD_HEIGHT (21)

#include"glm\glm.hpp"

enum{
	NOTHING,
	WALL
};

class Feald{
public:

	glm::vec3 m_position;

	bool m_fealdType;

	void draw();
	Feald(){};
	Feald(float _x, float _y, float _z)
	{
		m_position.x = _x;
		m_position.y = _y;
		m_position.z = _z;
	};

};


extern Feald *feald[FEALD_HEIGHT][FEALD_WIDTH];

#endif