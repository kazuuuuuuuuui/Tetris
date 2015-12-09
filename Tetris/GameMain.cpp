/*�`��͂����܂ł��`��p�̃o�b�t�@�ōs���Ă���̂Œ���*/
//memo lock�����ۂ�create�������Ƃ�isHit(y-1)����true�Ȃ�Q�[���I�[�o�[

#define WINDOW_WIDTH (900)
#define WINDOW_HEIGHT (1000)

#include<stdio.h>
#include<time.h>
#include<vector>
#include"oka_library\Camera.h"
#include"Feald.h"
#include"glut.h"

int flameCounter = 0;

//test
bool debugFlag = false;

//��]�̓���
void keyboard(unsigned char key, int x, int y){
	if ('a' == key){
		if (isHit(currentBlock, posX, posY, ((rotate + 1) % RotateMax))){

		}
		else{
			rotate++;
			rotate = rotate%RotateMax;
		}
	}

	//debug
	if ('d' == key){
		debugFlag = !debugFlag;
	}

	if ('u' == key){
		camera->m_position.m_y += 0.5f;
	}

	if ('h' == key){
		camera->m_position.m_x -= 0.5f;
	}
	if ('j' == key){
		camera->m_position.m_y -= 0.5f;
	}

	if ('k' == key){
		camera->m_position.m_x += 0.5f;
	}


}

//���L�[�̓���
void specialkeydown(int key, int x, int y){

	switch (key){

		//���ɓ�������
	case GLUT_KEY_LEFT:
		if (isHit(currentBlock, posX - 1, posY, rotate)){

		}
		else{
			posX--;
		}

		break;

		//�E�ɓ�������
	case GLUT_KEY_RIGHT:
		if (isHit(currentBlock, posX + 1, posY, rotate)){

		}
		else{
			posX++;
		}

		break;

		//���ɓ�������
	case GLUT_KEY_DOWN:
		if (isHit(currentBlock, posX, posY + 1, rotate)){
			lockBlock(currentBlock, posX, posY, rotate);
			clearLine();
		}
		else{
			posY++;
		}
		break;

	}
}

void display(){
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//test
	if (debugFlag == false){
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	}
	else{
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	}


	//�[�x�e�X�g
	glEnable(GL_DEPTH_TEST);

	//�J�����O
	//glEnable(GL_CULL_FACE);

	//���C�g
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	/*�X�V*/
	camera->update();

	if (0 == flameCounter % 50){
		if (isHit(currentBlock, posX, posY + 1, rotate)){
			lockBlock(currentBlock, posX, posY, rotate);
			clearLine();
		}
		else{
			fallBlock();
		}
	}


	//�\���p�o�b�t�@������
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			buffer[i][t]->m_type = NORMAL;
		}
	}

	//�`��pbuffer�X�V
	//�t�B�[���h���
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			buffer[i][t]->m_type = feald[i][t]->m_type;
		}
	}

	//�`��pbuffer�X�V
	//�u���b�N
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			buffer[i + posY][t + posX]->m_type = (buffer[i + posY][t + posX])->m_type | (currentBlock[rotate][i][t]);
		}
	}

	//�t�B�[���h�o�b�t�@�`��
	for (int i = FEALD_Y_TOP; i < FEALD_HEIGHT - 1; i++) {
		for (int t = 0; t < FEALD_WIDTH; t++) {
			buffer[i][t]->draw();
		}
	}

	/**/

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

	//�������ςȂ���
	glutIgnoreKeyRepeat(GL_FALSE);
}

/*�Q�[���J�n���̏�����*/
void init(){
	//�u���b�N�����̗����̃V�[�h��ς���
	srand((unsigned)time(NULL));

	//�J�����̐���
	camera = new oka::Camera();


	//setCube();

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
		feald[FEALD_HEIGHT - 2][t]->m_type = WALL;
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


	//�ŏ���1�ڃu���b�N����
	createBlock();

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