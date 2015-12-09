/*描画はあくまでも描画用のバッファで行っているので注意*/
//memo lockした際のcreateしたあとにisHit(y-1)してtrueならゲームオーバー

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

//回転の入力
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

//矢印キーの入力
void specialkeydown(int key, int x, int y){

	switch (key){

		//左に動く処理
	case GLUT_KEY_LEFT:
		if (isHit(currentBlock, posX - 1, posY, rotate)){

		}
		else{
			posX--;
		}

		break;

		//右に動く処理
	case GLUT_KEY_RIGHT:
		if (isHit(currentBlock, posX + 1, posY, rotate)){

		}
		else{
			posX++;
		}

		break;

		//下に動く処理
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


	//深度テスト
	glEnable(GL_DEPTH_TEST);

	//カリング
	//glEnable(GL_CULL_FACE);

	//ライト
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);


	/*更新*/
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


	//表示用バッファ初期化
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			buffer[i][t]->m_type = NORMAL;
		}
	}

	//描画用buffer更新
	//フィールド情報
	for (int i = 0; i < FEALD_HEIGHT; i++){
		for (int t = 0; t < FEALD_WIDTH; t++){
			buffer[i][t]->m_type = feald[i][t]->m_type;
		}
	}

	//描画用buffer更新
	//ブロック
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			buffer[i + posY][t + posX]->m_type = (buffer[i + posY][t + posX])->m_type | (currentBlock[rotate][i][t]);
		}
	}

	//フィールドバッファ描画
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

//コールバック関数の登録
void GLUT_CALLBACK_FUNC(){
	glutDisplayFunc(display);
	glutTimerFunc(0, timer, 0);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(specialkeydown);

	//押しっぱなし可
	glutIgnoreKeyRepeat(GL_FALSE);
}

/*ゲーム開始時の初期化*/
void init(){
	//ブロック生成の乱数のシードを変える
	srand((unsigned)time(NULL));

	//カメラの生成
	camera = new oka::Camera();


	//setCube();

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
		feald[FEALD_HEIGHT - 2][t]->m_type = WALL;
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


	//最初の1個目ブロック生成
	createBlock();

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