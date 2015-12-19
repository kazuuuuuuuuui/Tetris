#include<conio.h>
#include<random>
#include"Block.h"
#include"Feald.h"
#include"glut.h"

//�Q�[���̃X�R�A
//���{�^���������Ƒ���
//�u���b�N�������Ƒ���
int gameScore;

//���������s��
int deleteLinesNumber;

//�ŏ���0�ŏ������s����10�������level��1������
//level��������Ǝ��R�����̑��x�������Ȃ�
int gameLevel;

//o�^
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

//I�^
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

//�ʌ^
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

//L�^
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

//�tL�^
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

//Z�^
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

//�tZ�^
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

Feald nextBlock[4][4];
Feald nextNextBlock[4][4];

//�u���b�N��x,y�Ɖ�]
//curentBlock�͌��ݗ������Ă�Block
char currentBlock[RotateMax][4][4];

char blockShadow[RotateMax][4][4];


int blockType = (rand() % 7) + 2;
int nextBlockType = (rand() % 7) + 2;
int nextNextBlockType=(rand() % 7) + 2;
int posX;
int posY;
int rotate;

//�u���b�N����
void createBlock(){
	//�����_���Ńu���b�N�̎�ނ�����(2�`8�̒l���擾)


	blockType = nextBlockType;
	nextBlockType = nextNextBlockType;
	nextNextBlockType = (rand() % 7) + 2;


	posX = 4;
	posY = 0;
	rotate = 0;

	//���݂̃u���b�N������
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			for (int u = 0; u < RotateMax; u++){
				currentBlock[u][i][t] = NORMAL;
			}
		}
	}

	//���݂̃u���b�N�̉e������
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			for (int u = 0; u < RotateMax; u++){
				blockShadow[u][i][t] = NORMAL;
			}
		}
	}

	using arr = char(*)[4][4];///char(*)[4][4];

	arr pType[9] = {
		nullptr,
		nullptr,
		type_O,
		type_I,
		type_invT,
		type_L,
		type_invL,
		type_Z,
		type_invZ
	};

	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			for (int u = 0; u < RotateMax; u++){
				currentBlock[u][i][t] = pType[blockType][u][i][t];
				blockShadow[u][i][t] = pType[blockType][u][i][t];
			}
		}
	}

	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			nextBlock[i][t].m_type = pType[nextBlockType][0][i][t];
		}
	}

	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			nextNextBlock[i][t].m_type = pType[nextNextBlockType][0][i][t];
		}
	}
}

//�u���b�N�̎��R����
void fallBlock(){
	posY++;
}

//���C�����������̍ۂɈ�x�ɏ�����s�̐�
int deleteLineCount = 0;

//�u���b�N�̏���
void clearLine(){

	//�J�E���g������
	deleteLineCount = 0;

	for (int i = FEALD_Y_TOP; i <= FEALD_Y_BUTTOM; i++){
		if (feald[i][1]->m_type != NORMAL && feald[i][2]->m_type != NORMAL && feald[i][3]->m_type != NORMAL && feald[i][4]->m_type != NORMAL &&
			feald[i][5]->m_type != NORMAL && feald[i][6]->m_type != NORMAL && feald[i][7]->m_type != NORMAL && feald[i][8]->m_type != NORMAL &&
			feald[i][9]->m_type != NORMAL && feald[i][10]->m_type != NORMAL){

			for (int t = 1; t < FEALD_WIDTH - 1; t++){
				feald[i][t]->m_type = NORMAL;
			}

			//���ɍ~�낷����
			for (int s = i - 1; s > FEALD_Y_TOP - 2; s--){
				for (int u = 1; u < FEALD_WIDTH - 1; u++){
					feald[s + 1][u]->m_type = feald[s][u]->m_type;
				}
			}


			deleteLineCount++;
		}
	}

	//�������s���X�V
	deleteLinesNumber += deleteLineCount;


	//�X�R�A�̉��Z
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

//�����蔻��
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

//�u���b�N�Œ�
void lockBlock(char _bloak[][4][4], int _x, int _y, int _rotate){
	for (int i = 0; i < 4; i++){
		for (int t = 0; t < 4; t++){
			feald[_y + i][_x + t]->m_type = (feald[_y + i][_x + t]->m_type) + (_bloak[_rotate][i][t]);
		}
	}
}
