#include"Floor.h"
#include"glut.h"

#define FLOOR_WIDTH (10)
#define FLOOR_HEIGHT (20)

Floor *flr = nullptr;

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
}