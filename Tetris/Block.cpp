#include<conio.h>
#include<random>
#include"Block.h"
#include"Feald.h"
#include"glut.h"

//ゲームのスコア
//下ボタンを押すと増加
//ブロックを消すと増加
int gameScore;

//消した総行数
int deleteLinesNumber;

//最初は0で消した行数が10増えるとlevelが1増える
//levelが増えると自由落下の速度が早くなる
int gameLevel;

//o型
char type_O[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 2, 2, 0 },
		{ 0, 0, 0, 0 }
	}

};

//I型
char type_I[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 3, 3, 3, 3 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 3, 0, 0 },
		{ 0, 3, 0, 0 },
		{ 0, 3, 0, 0 },
		{ 0, 3, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 3, 3, 3, 3 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 3, 0, 0 },
		{ 0, 3, 0, 0 },
		{ 0, 3, 0, 0 },
		{ 0, 3, 0, 0 }
	}

};

//凸型
char type_invT[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 4, 0 },
		{ 0, 4, 4, 4 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 4, 0 },
		{ 0, 0, 4, 4 },
		{ 0, 0, 4, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 4, 4, 4 },
		{ 0, 0, 4, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 4, 0 },
		{ 0, 4, 4, 0 },
		{ 0, 0, 4, 0 }
	}

};

//L型
char type_L[RotateMax][4][4] = {
	{
		{ 0, 5, 0, 0 },
		{ 0, 5, 0, 0 },
		{ 0, 5, 5, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 5, 5, 5 },
		{ 0, 5, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 5, 5, 0 },
		{ 0, 0, 5, 0 },
		{ 0, 0, 5, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 5 },
		{ 0, 5, 5, 5 },
		{ 0, 0, 0, 0 }
	}

};

//逆L型
char type_invL[RotateMax][4][4] = {
	{
		{ 0, 0, 6, 0 },
		{ 0, 0, 6, 0 },
		{ 0, 6, 6, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 6, 0, 0 },
		{ 0, 6, 6, 6 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 6, 6, 0 },
		{ 0, 6, 0, 0 },
		{ 0, 6, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 6, 6, 6 },
		{ 0, 0, 0, 6 },
		{ 0, 0, 0, 0 }
	}

};

//Z型
char type_Z[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 7, 7, 0 },
		{ 0, 0, 7, 7 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 7 },
		{ 0, 0, 7, 7 },
		{ 0, 0, 7, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 7, 7, 0 },
		{ 0, 0, 7, 7 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 7 },
		{ 0, 0, 7, 7 },
		{ 0, 0, 7, 0 },
		{ 0, 0, 0, 0 }
	}

};

//逆Z型
char type_invZ[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 8, 8 },
		{ 0, 8, 8, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 8, 0 },
		{ 0, 0, 8, 8 },
		{ 0, 0, 0, 8 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 8, 8 },
		{ 0, 8, 8, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 8, 0 },
		{ 0, 0, 8, 8 },
		{ 0, 0, 0, 8 },
		{ 0, 0, 0, 0 }
	}

};

//ブロックのx,yと回転
//curentBlockは現在落下してるBlock
char currentBlock[RotateMax][4][4];
int blockType;
int posX;
int posY;
int rotate;

//ブロック生成
void createBlock(){
	//ランダムでブロックの種類を決定(2～8の値を取得)

	//blockType = (rand() % 7) + 2;

	//test
	blockType = TYPE_I;

	posX = 4;
	posY = 0;
	rotate = 0;

	//現在のブロック初期化
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			for (int u = 0; u < RotateMax; u++){
				currentBlock[u][i][t] = 0;
			}
		}
	}

	switch (blockType){
	case TYPE_O:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_O[u][i][t];
				}
			}
		}
		break;

	case TYPE_I:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_I[u][i][t];
				}
			}
		}
		break;

	case TYPE_invT:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_invT[u][i][t];
				}
			}
		}
		break;

	case TYPE_L:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_L[u][i][t];
				}
			}
		}
		break;

	case TYPE_invL:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_invL[u][i][t];
				}
			}
		}
		break;

	case TYPE_Z:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_Z[u][i][t];
				}
			}
		}
		break;

	case TYPE_invZ:
		for (int i = 0; i < 4; i++){
			for (int t = 0; t < 4; t++){
				for (int u = 0; u < RotateMax; u++){
					currentBlock[u][i][t] = currentBlock[u][i][t] | type_invZ[u][i][t];
				}
			}
		}
		break;
	}

}

//ブロックの自由落下
void fallBlock(){
	posY++;
}

//ライン消去処理の際に一度に消える行の数
int deleteLineCount = 0;

//ブロックの消去
void clearLine(){

	//カウント初期化
	deleteLineCount = 0;

	for (int i = FEALD_Y_TOP; i <= FEALD_Y_BUTTOM; i++){
		if (feald[i][1]->m_type != NORMAL && feald[i][2]->m_type != NORMAL && feald[i][3]->m_type != NORMAL && feald[i][4]->m_type != NORMAL &&
			feald[i][5]->m_type != NORMAL && feald[i][6]->m_type != NORMAL && feald[i][7]->m_type != NORMAL && feald[i][8]->m_type != NORMAL &&
			feald[i][9]->m_type != NORMAL && feald[i][10]->m_type != NORMAL){
			for (int t = 1; t < FEALD_WIDTH - 1; t++){
				feald[i][t]->m_type = NORMAL;
			}

			//下に降ろす処理
			for (int s = i - 1; s > FEALD_Y_TOP; s--){
				for (int u = 1; u < FEALD_WIDTH - 1; u++){
					feald[s + 1][u]->m_type = feald[s][u]->m_type;
				}
			}

			deleteLineCount++;
		}
	}

	//消した行数更新
	deleteLinesNumber += deleteLineCount;


	//スコアの加算
	switch (deleteLineCount){
	case 1:
		gameScore += 100;

		break;


	case 2:
		gameScore += 300;

		break;


	case 3:
		gameScore += 500;

		break;

	case 4:
		gameScore += 1000;

		break;

	default:
		break;

	}
}

//当たり判定
bool isHit(char _bloak[][4][4], int _x, int _y, int _rotate){
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			if (_bloak[_rotate][i][t] && feald[_y + i][_x + t]->m_type){
				return true;
			}
			else{

			}
		}
	}

	return false;
}

//ブロック固定
void lockBlock(char _bloak[][4][4], int _x, int _y, int _rotate){
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			feald[_y + i][_x + t]->m_type = (feald[_y + i][_x + t]->m_type) | (_bloak[_rotate][i][t]);
		}
	}
}


//ゲームオーバーのチェック
//if (isHit(currentBlock, posX, posY + 1, rotate)){
//	printf("Game Over\n");
//}