#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")

#define _CRT_SECURE_NO_WARNINGS

#define WINDOW_WIDTH (960)
#define WINDOW_HEIGHT (1000)

#define BACKGRUND_SIZE (60.f)

#include<stdio.h>
#include<time.h>
#include<vector>
#include"oka_library\Camera.h"
#include"oka_library\BmpImage.h"
#include"oka_library\StrokeString.h"
#include"Feald.h"
#include"GameManager.h"
#include"glut.h"

void init();


//テクスチャ
GLuint titleTex;
GLuint BackGroundTex;

GameManager *gameManager = nullptr;

//test
bool debugFlag = false;

bool isGameOver;
bool isGameMain;

//スコアカウンター
char str_score[256];

//消去したライン数のカウンター
char str_deleteLine[256];

//ゲームレベル
char str_gameLevel[256];

//自由落下のスピード
int fallSpeed;

//1level上がるごとに増える自由落下の速度
int fallSpeedIncrement;

//スコア・消したライン数・レベルを表示
void printStatus(){

	//glColor3f(1, 0, 0);

	glPushMatrix();
	glTranslatef(212, 280, 0);
	glScalef(0.12f, 0.12f, 0.12f);
	StrokeString::print("NEXT");
	glPopMatrix();

	//スコア
	glPushMatrix();
	glTranslatef(238, 162, 0);
	glScalef(0.1f, 0.1f, 0.1f);
	StrokeString::print("SCORE");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(238, 146, 0);
	glScalef(0.1f, 0.1f, 0.1f);
	StrokeString::print(str_score);
	glPopMatrix();

	//消した行総数
	glPushMatrix();
	glTranslatef(238, 128, 0);
	glScalef(0.1f, 0.1f, 0.1f);
	StrokeString::print("LINES");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(238, 110, 0);
	glScalef(0.1f, 0.1f, 0.1f);
	StrokeString::print(str_deleteLine);
	glPopMatrix();

	//消した行総数
	glPushMatrix();
	glTranslatef(238, 94, 0);
	glScalef(0.1f, 0.1f, 0.1f);
	StrokeString::print("LEVEL");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(238, 78, 0);
	glScalef(0.1f, 0.1f, 0.1f);
	StrokeString::print(str_gameLevel);
	glPopMatrix();

	//操作方法
	glPushMatrix();
	glTranslatef(212, 30, 0);
	glScalef(0.08f, 0.08f, 0.08f);
	StrokeString::print("Move:ArrowKey");
	glPopMatrix();

	glPushMatrix();
	glTranslatef(212, 14, 0);
	glScalef(0.08f, 0.08f, 0.08f);
	StrokeString::print("Rotate:SpaceKey");
	glPopMatrix();

}

bool checkGameOver1(){
	for (int i = 1; i >= 0; i--){
		if (feald[i][1]->m_type != NORMAL || feald[i][2]->m_type != NORMAL || feald[i][3]->m_type != NORMAL || feald[i][4]->m_type != NORMAL ||
			feald[i][5]->m_type != NORMAL || feald[i][6]->m_type != NORMAL || feald[i][7]->m_type != NORMAL || feald[i][8]->m_type != NORMAL ||
			feald[i][9]->m_type != NORMAL || feald[i][10]->m_type != NORMAL){
			return true;
		}
	}

	return false;
}

bool checkGameOver2(){
	if (isHit(currentBlock, posX, posY + 1, rotate)){
		return true;
	}

	return false;
}

//回転の入力
void keyboard(unsigned char key, int x, int y){

	switch (gameManager->m_scene){
	case TITLE:{

		//スペースでゲームに進む
		if (NULL != key){
			gameManager->m_scene = GAME;
		}

		//debug
		/*if ('z' == key){
			xx += 0.1f;
		}

		if ('x' == key){
			yy += 0.1f;

		}

		if ('c' == key){
			xx -= 0.1f;
		}*/

		break;
	}

	case GAME:{

		if (false == isGameOver){

			//rで回転
			if (' ' == key){
				if (isHit(currentBlock, posX, posY, ((rotate + 1) % RotateMax))){

				}
				else{
					rotate++;
					rotate = rotate%RotateMax;
				}
			}

		}

		if (true == isGameOver){
			if (NULL != key){
				init();
				gameManager->m_scene = TITLE;
			}
		}

		//debug
		/*if ('d' == key){
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

		if ('n' == key){
			camera->m_position.m_z -= 0.5f;
		}

		if ('m' == key){
			camera->m_position.m_z += 0.5f;
		}*/

		/*if ('z' == key){
			camera->m_target.m_x -= 0.5f;
			}

			if ('x' == key){
			camera->m_target.m_x += 0.5f;


			}*/

		/*f ('z' == key){
			xx += 0.1f;
		}

		if ('x' == key){
			yy += 0.1f;

		}

		if ('c' == key){
			xx -= 0.1f;
		}*/

		/*printf("x: %f\ny: %f\nz: %f\n target.x: %f\n", camera->m_position.m_x, camera->m_position.m_y, camera->m_position.m_z, camera->m_target.m_x);
		printf("\n");*/

		break;
	}

	}
}

//矢印キーの入力
void specialkeydown(int key, int x, int y){

	switch (gameManager->m_scene){

	case TITLE:{

		break;
	}

	case GAME:{

		if (false == isGameOver){

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

					/*if (checkUpGameLevel()){
						gameLevel++;
						}*/

					gameLevel = deleteLinesNumber / 10;

					createBlock();
				}
				else{
					posY++;
					gameScore++;
				}
				break;

			}

		}

		break;
	}

	}
}

void display(){
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);


	switch (gameManager->m_scene)
	{
	case TITLE:{

		//タイトル画面
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glOrtho(
			0, 1,  // GLdouble left, right
			0, 1,  // GLdouble bottom, top,
			1, -1); // GLdouble zNear, zFar

		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, titleTex);

		//背景
		glBegin(GL_QUADS);
		{
			glTexCoord2f(0.f, 0.f);
			glVertex2f(0.f, 0.f);

			glTexCoord2f(1.f, 0.f);
			glVertex2f(1.f, 0.f);

			glTexCoord2f(1.f, 1.f);
			glVertex2f(1.f, 1.f);

			glTexCoord2f(0.f, 1.f);
			glVertex2f(0.f, 1.f);
		}
		glEnd();

		//タイトル
		/*glEnable(GL_BLEND);
		
		glBlendFunc(
			GL_SRC_ALPHA,
			GL_ONE);

		glColor4f(1, 1, 1, 1);

		glPushMatrix();
		glTranslatef(0.2, 0.6, 0);
		glBegin(GL_QUADS);
		{
			glTexCoord2f(0.f, 0.f);
			glVertex2f(0.f, 0.f);

			glTexCoord2f(1.f, 0.f);
			glVertex2f(0.6f, 0.f);

			glTexCoord2f(1.f, 1.f);
			glVertex2f(0.6f, 0.2f);

			glTexCoord2f(0.f, 1.f);
			glVertex2f(0.f, 0.2f);
		}
		glEnd();
		glPopMatrix();
		glDisable(GL_BLEND);*/

		glDisable(GL_TEXTURE_2D);

		break;
	}

	case GAME:{

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

		//背景設定
		glEnable(GL_TEXTURE_2D);
		glBindTexture(GL_TEXTURE_2D, BackGroundTex);

		glPushMatrix();
		glColor3f(1, 1, 1);
		glTranslatef(-20, -55, -1);
		glBegin(GL_QUADS);
		{
			glNormal3f(0, 0, 1);

			glTexCoord2f(0.f, 0.f);
			glVertex3f(0.f, 0.f, 0.f);

			glTexCoord2f(1.f, 0.f);
			glVertex3f(BACKGRUND_SIZE, 0.f, 0.f);

			glTexCoord2f(1.f, 1.f);
			glVertex3f(BACKGRUND_SIZE, BACKGRUND_SIZE, 0.f);

			glTexCoord2f(0.f, 1.f);
			glVertex3f(0.f, BACKGRUND_SIZE, 0.f);
		}
		glEnd();
		glPopMatrix();

		glDisable(GL_TEXTURE_2D);

		if (false == isGameOver){

			if (0 == gameManager->m_flameCounter % fallSpeed){
				//if (0 == gameManager->m_flameCounter % 100){
				if (isHit(currentBlock, posX, posY + 1, rotate)){
					lockBlock(currentBlock, posX, posY, rotate);

					clearLine();

					/*if (checkUpGameLevel()){
						gameLevel++;
						}*/

					gameLevel = deleteLinesNumber / 10;

					//横一列処理後にブロック生成領域にブロックが置かれていたらゲームオーバー
					if (checkGameOver1()){
						isGameOver = true;
					}

					createBlock();

					//生成した直下にブロックがあったらゲームオーバー
					if (checkGameOver2()){
						isGameOver = true;
					}
				}
				else{
					fallBlock();
				}
			}

		}

		//次のブロック表示
		glPushMatrix();
		glScalef(0.8, 0.8, 0.8);
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				nextBlock[i][t].draw();
			}
		}

		//次の次のブロック表示
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				nextNextBlock[i][t].draw();
			}
		}
		glPopMatrix();

		/////////////////////////////////////

		//表示用バッファ初期化
		for (int i = 0; i < FEALD_HEIGHT; i++){
			for (int t = 0; t < FEALD_WIDTH; t++){
				buffer[i][t]->m_type = NORMAL;
			}
		}

		if (isGameOver == false){

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

		}

		else if (isGameOver == true){
			for (int i = 0; i < FEALD_HEIGHT; i++){
				for (int t = 0; t < FEALD_WIDTH; t++){
					feald[i][t]->m_type = WALL;
				}
			}

			//描画用buffer更新
			//フィールド情報
			for (int i = 0; i < FEALD_HEIGHT; i++){
				for (int t = 0; t < FEALD_WIDTH; t++){
					buffer[i][t]->m_type = feald[i][t]->m_type;
				}
			}
		}

		//フィールドバッファ描画
		for (int i = FEALD_Y_TOP; i < FEALD_HEIGHT - 1; i++) {
			for (int t = 0; t < FEALD_WIDTH; t++) {
				buffer[i][t]->draw();
			}
		}

		//2D画面上の処理
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glOrtho(
			0, 300,  // GLdouble left, right
			0, 300,  // GLdouble bottom, top,
			1, -1); // GLdouble zNear, zFar

		//スコア等の表示
		printStatus();

		if (isGameOver == true){
			glPushMatrix();
			glTranslatef(46, 140, 0);
			glScalef(0.2f, 0.2f, 0.2f);
			StrokeString::print("GAME OVER");
			glPopMatrix();


			glPushMatrix();
			glTranslatef(84, 100, 0);
			glScalef(0.08f, 0.08f, 0.08f);
			StrokeString::print("push any key");
			glPopMatrix();

		}

		break;
	}

	}

	glFlush();
}

void timer(int value){

	sprintf(str_score, "%d", gameScore);
	sprintf(str_deleteLine, "%d", deleteLinesNumber);
	sprintf(str_gameLevel, "%d", gameLevel);

	gameManager->m_flameCounter++;

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

	//ゲーム進行に必要なフラグを初期化する
	isGameMain = false;

	isGameOver = false;

	gameScore = 0;
	deleteLinesNumber = 0;
	gameLevel = 0;
	fallSpeedIncrement = 5;


	//落下速度の初期化
	//値が小さくなるにつれ落下速度は速くなる
	//初期値は50Fに1回呼ばれるくらいの速度
	fallSpeed = 50 - fallSpeedIncrement * gameLevel;

	//ブロック生成の乱数のシードを変える
	srand((unsigned)time(NULL));

	//ゲームマネージャー生成
	gameManager = new GameManager();

	//カメラの生成
	camera = new oka::Camera();


	//setCube();

	titleTex = BmpImage::loadImage("BMP/title.bmp");
	BackGroundTex = BmpImage::loadImage("BMP/bg.bmp");

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

	//次の表示位置を設定
	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			nextBlock[i][t].m_position.x = 31 + t * 2;
			nextBlock[i][t].m_position.y = -8.5 + i*(-2);
			nextBlock[i][t].m_position.z = 0;
		}
	}

	//次の次の表示位置を設定
	for (int i = 0; i < 4; i++) {
		for (int t = 0; t < 4; t++) {
			nextNextBlock[i][t].m_position.x = 31 + t * 2;
			nextNextBlock[i][t].m_position.y = -17.5 + i*(-2);
			nextNextBlock[i][t].m_position.z = 0;
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

	glutMainLoop();
}