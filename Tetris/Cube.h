#ifndef CUBE_H_
#define CUBE_H_

//ŒÅ’è
#define VERTICEIS (24)
#define INDECIES (36)
#define NORMALS (24)

#define CUBE_WIDTH (1)
#define CUBE_HEIGHT (1)
#define CUBE_DEPTH (1)

#include<vector>
#include"glm\glm.hpp"

class Cube{
public:

	float m_width;
	float m_height;
	float m_depth;

	float m_vertex[VERTICEIS];
	unsigned int m_index[INDECIES];
	float normal[VERTICEIS];

	Cube();
};


#endif