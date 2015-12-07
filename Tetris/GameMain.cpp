/*描画はあくまでも描画用のバッファで行っているので注意*/

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


	/*更新*/
	camera->update();

	//if (0 == flameCounter % 50){
	//	
	//}


	/**/
	//描画用バッファにフィールド情報(m_type)を書き込む
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		for (int t = 0; t < FEALD_WIDTH; t++) {
			buffer[i][t]->m_type = feald[i][t]->m_type;
		}
	}

	//フィールドバッファ描画
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

//コールバック関数の登録
void GLUT_CALLBACK_FUNC(){
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	//glutKeyboardFunc(keyboard);
	//glutSpecialFunc(specialkeydown);

	////押しっぱなし不可
	//glutIgnoreKeyRepeat(GL_TRUE);
}

/*ゲーム開始時の初期化*/
void init(){

	//カメラの生成
	camera = new oka::Camera();

	//フィールドと描画用のバッファ生成
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		for (int t = 0; t < FEALD_WIDTH; t++) {
			feald[i][t] = new Feald();
			buffer[i][t] = new Feald();
		}
	}

	//フィールドに壁の登録
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		feald[i][0]->m_type = WALL;
		feald[i][FEALD_WIDTH - 1]->m_type = WALL;
	}

	for (int t = 0; t < FEALD_WIDTH; t++) {
		feald[FEALD_HEIGHT - 1][t]->m_type = WALL;
	}

	//バッファマス目の座標設定
	//左上を(0,0)
	for (int i = 0; i < FEALD_HEIGHT; i++) {
		for (int t = 0; t < FEALD_WIDTH; t++) {
			buffer[i][t]->m_position.x = t * 2;
			buffer[i][t]->m_position.y = i * (-2);
			buffer[i][t]->m_position.z = 0;
		}
	}
}


/*ゲームメイン*/
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