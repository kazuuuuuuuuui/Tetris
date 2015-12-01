#define WINDOW_WIDTH (900)
#define WINDOW_HEIGHT (1000)

#include<stdio.h>
#include"oka_library\Camera.h"
#include"Block.h"
#include"Floor.h"
#include"glut.h"

Block *block = nullptr;

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
		break;

		//�E�ɓ�������
	case GLUT_KEY_RIGHT:
		block->m_position.x++;
		break;

		//���ɓ�������
	case GLUT_KEY_DOWN:
		block->m_position.y--;
		break;

	}

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	/*�X�V*/
	camera->update();

	//block->update();


	/*�`��*/
	flr->draw();
	block->draw();


	glFlush();
}

void timer(int value){

	glutPostRedisplay();
	glutTimerFunc(
		1000 / 60,
		timer,
		0);
}

//�R�[���o�b�N�֐��̓o�^
void GLUT_CALLBACK_FUNC(){
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeydown);
}

/*�Q�[���J�n���̏�����*/
void init(){
	camera = new oka::Camera();
	flr = new Floor();

	block = new Block();
}


/*�Q�[�����C��*/
int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Tetris");

	GLUT_CALLBACK_FUNC();

	//�������ςȂ��s��
	glutIgnoreKeyRepeat(GL_TRUE);

	init();

	glutMainLoop();
}