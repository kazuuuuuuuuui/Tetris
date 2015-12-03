#include<conio.h>
#include<random>
#include"Block.h"
#include"Feald.h"
#include"glut.h"

Block *block = nullptr;

Block::Block(){
	m_blockType = TYEPE3;
	//m_blockType = rand() % 7;
	m_angle = 0;
	m_position.x = 5.5;
	m_position.y = 10.5;
	m_position.z = 0;
}

void checkBlockMoveLeft(){
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			if (feald[i][t]->m_position == block->m_position && feald[i][t]->m_fealdType == WALL){
				block->m_position.x++;
			}
		}
	}
}

void checkBlockMoveRight(){
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			if (feald[i][t]->m_position == block->m_position && feald[i][t]->m_fealdType == WALL){
				block->m_position.x--;
			}
		}
	}
}

void checkBlockMoveDown(){
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			if (feald[i][t]->m_position == block->m_position && feald[i][t]->m_fealdType == WALL){
				block->m_position.y++;
			}
		}
	}
}

//��]�̓���
void keyboard(unsigned char key, int x, int y){

	block->m_angle -= 90;

}

//���L�[�̓���
void specialkeydown(int key, int x, int y){

	switch (key){

		//���ɓ�������
	case GLUT_KEY_LEFT:
		block->m_position.x--;
		checkBlockMoveLeft();

		break;

		//�E�ɓ�������
	case GLUT_KEY_RIGHT:
		block->m_position.x++;
		checkBlockMoveRight();

		break;

		//���ɓ�������
	case GLUT_KEY_DOWN:
		block->m_position.y--;
		checkBlockMoveDown();
		break;

	}
}

void Block::control(){

}

void Block::drawType0(){

	//debug
	//��͐�
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);

	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);

	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType1(){

	//debug
	//��͐�
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);

	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType2(){
	//debug
	//��͐�
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);

	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, -1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType3(){
	//debug
	//��͐�
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);

	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType4(){
	//debug
	//��͐�
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);

	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslatef(1, 0, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType5(){
	//debug
	//��͐�
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);

	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType6(){
	//debug
	//��͐�
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);

	glColor3f(0, 0, 1);

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, INDECIES, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::draw(){
	glPushMatrix();
	{
		//test
		//float ambient[4] = { 0.1745, 0.01175, 0.01175, 1.0 };
		//float diffuse[4] = { 0.61424, 0.04136, 0.04136, 1.0 };
		//float specular[4] = { 0.727811, 0.626959, 0.626959, 1.0 };
		//float shininess = 76.8;

		//glMaterialfv(
		//	GL_FRONT,   // GLenum face
		//	GL_AMBIENT, // GLenum pname
		//	ambient);   // const GLfloat *params

		//glMaterialfv(
		//	GL_FRONT,   // GLenum face
		//	GL_DIFFUSE, // GLenum pname
		//	diffuse);   // const GLfloat *params

		//glMaterialfv(
		//	GL_FRONT,   // GLenum face
		//	GL_SPECULAR,// GLenum pname
		//	specular);  // const GLfloat *params

		//glMaterialf(
		//	GL_FRONT,       // GLenum face
		//	GL_SHININESS,   // GLenum pname
		//	shininess);            // GLfloat param


		//�u���b�N�S�̂̈ړ��E��]
		glTranslatef(m_position.x, m_position.y, m_position.z);

		glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		//�`��
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, m_vertex);

		//�u���b�N�̎�ނɂ���Č`���Ⴄ
		switch (m_blockType){

		case TYEPE0:

			drawType0();

			break;

		case TYEPE1:
			drawType1();
			break;

		case TYEPE2:
			drawType2();
			break;

		case TYEPE3:
			drawType3();
			break;

		case TYEPE4:
			drawType4();
			break;

		case TYEPE5:
			drawType5();
			break;

		case TYEPE6:
			drawType6();
			break;
		}
	}

	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void Block::update(){
	m_position.y -= 1;
	checkBlockMoveDown();
}