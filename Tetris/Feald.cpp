#include"Feald.h"
#include"glut.h"

void Feald::draw(){
	if (NORMAL == m_type){
		glColor3f(1, 1, 1);
	}
	else if (WALL == m_type){
		glColor3f(1, 0, 0);
	}

	glBegin(GL_QUADS);
	{
		glVertex3f(m_position.x - 1, m_position.y - 1, m_position.z);
		glVertex3f(m_position.x + 1, m_position.y - 1, m_position.z);
		glVertex3f(m_position.x + 1, m_position.y + 1, m_position.z);
		glVertex3f(m_position.x - 1, m_position.y + 1, m_position.z);
	}
	glEnd();



}
