#define WINDOW_WIDTH (900)
#define WINDOW_HEIGHT (1000)

#include<stdio.h>
#include"oka_library\Camera.h"
#include"Block.h"
#include"Feald.h"
#include"glut.h"

int flameCounter = 0;

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	glEnable(GL_DEPTH_TEST);

	//glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	/*�X�V*/
	camera->update();

	if (0 == flameCounter % 50){
		block->update();
	}
	
	/*�`��*/
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			feald[i][t]->draw();
		}
	}

	block->draw();


	glFlush();
}

void timer(int value){

	flameCounter++;

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

	//�������ςȂ��s��
	glutIgnoreKeyRepeat(GL_TRUE);
}

/*�Q�[���J�n���̏�����*/
void init(){

	camera = new oka::Camera();

	//���W�̏�����
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			feald[i][t] = new Feald({ 0.5f + 1.f*t, 0.5f + 1.f*i, 0.f });
			feald[i][t]->m_fealdType = NOTHING;

		}
	}

	//�Ǐ���
	for (int t = 0; t < FEALD_WIDTH; t++){
		feald[0][t]->m_fealdType = WALL;
	}

	for (int i = 0; i < FEALD_HEIGHT; i++){
		feald[i][0]->m_fealdType = WALL;
		feald[i][11]->m_fealdType = WALL;
	}


	block = new Block();
}


/*�Q�[�����C��*/
int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Tetris");

	GLUT_CALLBACK_FUNC();

	init();

	glutMainLoop();
}