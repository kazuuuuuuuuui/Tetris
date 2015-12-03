#ifndef FLOOR_H_
#define FLOOR_H_

#define FLOOR_WIDTH (12)
#define FLOOR_HEIGHT (21)

#include"glm\glm.hpp"

class Floor{
public:
	glm::vec3 m_position;

	void draw();
	Floor(){};
	Floor(float _x, float _y, float _z)
	{
		m_position.x = _x;
		m_position.y = _y;
		m_position.z = _z;
	};

};


extern Floor *flr[FLOOR_HEIGHT][FLOOR_WIDTH];

#endif