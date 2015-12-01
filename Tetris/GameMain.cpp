#define WINDOW_WIDTH (900)
#define WINDOW_HEIGHT (1000)

#include<stdio.h>
#include"oka_library\Camera.h"
#include"Block.h"
#include"Floor.h"
#include"glut.h"

Block *block = nullptr;

//回転の入力
void keyboard(unsigned char key, int x, int y){

	block->m_angle -= 90;

}

//矢印キーの入力
void specialkeydown(int key, int x, int y){

	switch (key){

		//左に動く処理
	case GLUT_KEY_LEFT:
		block->m_position.x--;
		break;

		//右に動く処理
	case GLUT_KEY_RIGHT:
		block->m_position.x++;
		break;

		//下に動く処理
	case GLUT_KEY_DOWN:
		block->m_position.y--;
		break;

	}

}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);

	/*更新*/
	camera->update();

	//block->update();


	/*描画*/
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

//コールバック関数の登録
void GLUT_CALLBACK_FUNC(){
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeydown);
}

/*ゲーム開始時の初期化*/
void init(){
	camera = new oka::Camera();
	flr = new Floor();

	block = new Block();
}


/*ゲームメイン*/
int main(int argc, char *argv[]){
	glutInit(&argc, argv);
	glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
	glutCreateWindow("Tetris");

	GLUT_CALLBACK_FUNC();

	//押しっぱなし不可
	glutIgnoreKeyRepeat(GL_TRUE);

	init();

	glutMainLoop();
}