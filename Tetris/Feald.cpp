#include"Feald.h"
#include"glut.h"

Feald *feald[FEALD_HEIGHT][FEALD_WIDTH];

void Feald::draw(){
	/*(âº)*/

	//ècê¸
	glBegin(GL_LINES);
	for (float i = 0; i <= FEALD_WIDTH; i++)
	{
		glColor3f(1, 0, 0);
		glVertex3f(i, 0, 0);//(GLfloat x, GLfloat y, GLfloat z)
		glVertex3f(i, FEALD_HEIGHT, 0);
	}
	glEnd();

	//â°ê¸
	glBegin(GL_LINES);
	for (float i = 0; i <= FEALD_HEIGHT; i++)
	{
		glColor3f(0, 1, 0);
		glVertex3f(0, i, 0);//(GLfloat x, GLfloat y, GLfloat z)
		glVertex3f(FEALD_WIDTH, i, 0);
	}
	glEnd();

	glPushMatrix();

	if (NOTHING == m_fealdType){
		glColor3f(1, 1, 1);
	}
	else if (WALL == m_fealdType){
		glColor3f(174.f / 256.f, 174.f / 256.f, 174.f / 256.f);
	}

	glTranslatef(m_position.x, m_position.y, m_position.z);
	glBegin(GL_QUADS);
	{
		glVertex3f(-0.5, 0.5, 0);
		glVertex3f(-0.5, -0.5, 0);
		glVertex3f(0.5, -0.5, 0);
		glVertex3f(0.5, 0.5, 0);
	}
	glEnd();
	glPopMatrix();
}