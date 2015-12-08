#include<conio.h>
#include<random>
#include"Block.h"
#include"Feald.h"
#include"glut.h"

//o�^
char type_O[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	}

};

//I�^
char type_I[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 1, 1, 1, 1 },
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 }
	}

};

//�ʌ^
char type_invT[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 1, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 }
	}

};

//L�^
char type_L[RotateMax][4][4] = {
	{
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 0, 1 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 0, 0 }
	}

};

//�tL�^
char type_invL[RotateMax][4][4] = {
	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 1, 1, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 1, 0, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
	}

};

//Z�^
char type_Z[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 1 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 1, 0 },
		{ 0, 0, 0, 0 }
	}

};

//�tZ�^
char type_invZ[RotateMax][4][4] = {
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},

	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 0, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 1, 1, 0 },
		{ 0, 0, 0, 0 }
	},
	{
		{ 0, 0, 1, 0 },
		{ 0, 0, 1, 1 },
		{ 0, 0, 0, 1 },
		{ 0, 0, 0, 0 }
	}

};

//�u���b�N��x,y�Ɖ�]
//curentBlock�͌��ݗ������Ă�Block
char currentBlock[RotateMax][4][4];
int blockType;
int posX;
int posY;
int rotate;

//�u���b�N����
void createBlock(){
	//�����_���Ńu���b�N�̎�ނ�����

	blockType = rand() % 7;
	
	//test
	//blockType = TYPE_I;
	
	posX = 4;
	posY = 0;
	rotate = 0;

	//���݂̃u���b�N������
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

//�u���b�N�̎��R����
void fallBlock(){
	posY++;
}

//�u���b�N�̏���
void clearLine(){
	for (int i = 21; i > 3; i--){
		if (feald[i][1]->m_type == 1 && feald[i][2]->m_type == 1 && feald[i][3]->m_type == 1 && feald[i][4]->m_type == 1 &&
			feald[i][5]->m_type == 1 && feald[i][6]->m_type == 1 && feald[i][7]->m_type == 1 && feald[i][8]->m_type == 1 &&
			feald[i][9]->m_type == 1 && feald[i][10]->m_type == 1){
			for (int t = 1; t < FEALD_WIDTH - 1; t++){
				feald[i][t] = 0;
			}
		}
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
			feald[_y + i][_x + t]->m_type = (feald[_y + i][_x + t]->m_type) | (_bloak[_rotate][i][t]);
		}
	}

	//�V�����u���b�N�𐶐�
	createBlock();
}
