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
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	/*�X�V*/
	camera->update();

	//block->update();


	/*�`��*/
	for (int i = 0; i < FLOOR_HEIGHT; i++){
		for (int t = 0; t < FLOOR_WIDTH; t++){
			flr[i][t]->draw();
		}
	}

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

	for (int i = 0; i < FLOOR_HEIGHT; i++){
		for (int t = 0; t < FLOOR_WIDTH; t++){
			flr[i][t] = new Floor({ 0.5f + 1.f*t, 0.5f + 1.f*i, 0.f });
		}
	}

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