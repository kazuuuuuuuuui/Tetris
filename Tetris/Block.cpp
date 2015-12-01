#include"Block.h"
#include<random>
#include"glut.h"

Block::Block(){
	m_blockType = TYEPE0;
	//m_blockType = rand() % 7;
	m_angle = 0;
	m_position.x = 0.5;
	m_position.y = 0.5;
	m_position.z = 0;
}

void Block::control(){

}

void Block::drawType0(){

	//debug
	//基準は赤
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);

	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);

	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType1(){

	//debug
	//基準は赤
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);

	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, -1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType2(){
	//debug
	//基準は赤
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);

	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, -1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, -1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType3(){
	//debug
	//基準は赤
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);

	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType4(){
	//debug
	//基準は赤
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);

	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(1, 0, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-1, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType5(){
	//debug
	//基準は赤
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);

	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::drawType6(){
	//debug
	//基準は赤
	glColor3f(1, 0, 0);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);

	glColor3f(1, 1, 1);

	glPushMatrix();
	glTranslatef(-1, 0, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(1, 0, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0, 1, 0);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, m_index);
	glPopMatrix();
}

void Block::draw(){
	glPushMatrix();
	{
		//色
		//glColor3f(1, 1, 1);

		//ブロック全体の移動・回転
		glTranslatef(m_position.x, m_position.y, m_position.z);

		glRotatef(m_angle, 0.0f, 0.0f, 1.0f);

		//描画
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, m_vertex);

		//ブロックの種類によって形が違う
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
	m_position.y--;
}