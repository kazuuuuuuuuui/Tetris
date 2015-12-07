/*�`��͂����܂ł��`��p�̃o�b�t�@�ōs���Ă���̂Œ���*/

#define WINDOW_WIDTH (900)
#define WINDOW_HEIGHT (1000)

#define FEALD_WIDTH (12)
#define FEALD_HEIGHT (23)

#include<stdio.h>
#include"oka_library\Camera.h"
#include"Feald.h"
#include"glut.h"


Feald *feald[FEALD_HEIGHT][FEALD_WIDTH];
Feald *buffer[FEALD_HEIGHT][FEALD_WIDTH];


//int flameCounter = 0;

void display(){
	glClear(GL_COLOR_BUFFER_BIT /*| GL_DEPTH_BUFFER_BIT*/);
	//glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


	/*�X�V*/
	camera->update();

	//if (0 == flameCounter % 50){
	//	
	//}


	/**/
	//�`��p�o�b�t�@�Ƀt�B�[���h���(m_type)����������
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		for (int t = 0; t < FEALD_WIDTH; t++) {
			buffer[i][t]->m_type = feald[i][t]->m_type;
		}
	}

	//�t�B�[���h�o�b�t�@�`��
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		for (int t = 0; t < FEALD_WIDTH; t++) {
			buffer[i][t]->draw();
		}
	}
	/**/

	glFlush();
}

void timer(int value){

	//flameCounter++;

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
	//glutKeyboardFunc(keyboard);
	//glutSpecialFunc(specialkeydown);

	////�������ςȂ��s��
	//glutIgnoreKeyRepeat(GL_TRUE);
}

/*�Q�[���J�n���̏�����*/
void init(){

	//�J�����̐���
	camera = new oka::Camera();

	//�t�B�[���h�ƕ`��p�̃o�b�t�@����
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		for (int t = 0; t < FEALD_WIDTH; t++) {
			feald[i][t] = new Feald();
			buffer[i][t] = new Feald();
		}
	}

	//�t�B�[���h�ɕǂ̓o�^
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		feald[i][0]->m_type = WALL;
		feald[i][FEALD_WIDTH - 1]->m_type = WALL;
	}

	for (int t = 0; t < FEALD_WIDTH; t++) {
		feald[FEALD_HEIGHT - 1][t]->m_type = WALL;
	}

	//�o�b�t�@�}�X�ڂ̍��W�ݒ�
	//�����(0,0)
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		for (int t = 0; t < FEALD_WIDTH; t++) {
			buffer[i][t]->m_position.x = t * 2;
			buffer[i][t]->m_position.y = i * (-2);
			buffer[i][t]->m_position.z = 0;
		}
	}
}


/*�Q�[�����C��*/
int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Tetris");

	GLUT_CALLBACK_FUNC();

	init();

	//test
	//for (int i = 0; i < FEALD_HEIGHT; i++) {
	//	for (int t = 0; t < FEALD_WIDTH; t++) {
	//		//printf("%d", buffer[i][t]->m_type);
	//		printf("buffer[%d][%d] x:%f y:%f \n", i, t, buffer[i][t]->m_position.x, buffer[i][t]->m_position.y);
	//	}
	//printf("\n");
	//}

	glutMainLoop();
}