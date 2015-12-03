#include"Floor.h"
#include"glut.h"

Floor *flr[FLOOR_HEIGHT][FLOOR_WIDTH];

void Floor::draw(){
	/*(âº)*/

	//ècê¸
	glBegin(GL_LINES);
	for (float i = 0; i <= FLOOR_WIDTH; i++)
	{
		glColor3f(1, 0, 0);
		glVertex3f(i, 0, 0);//(GLfloat x, GLfloat y, GLfloat z)
		glVertex3f(i, FLOOR_HEIGHT, 0);
	}
	glEnd();

	//â°ê¸
	glBegin(GL_LINES);
	for (float i = 0; i <= FLOOR_HEIGHT; i++)
	{
		glColor3f(0, 1, 0);
		glVertex3f(0, i, 0);//(GLfloat x, GLfloat y, GLfloat z)
		glVertex3f(FLOOR_WIDTH, i, 0);
	}
	glEnd();

	glPushMatrix();
	glColor3f(1, 1, 1);
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