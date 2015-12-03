#include"cube.h"
#include"glm\glm.hpp"
#include"glut.h"


Cube::Cube(){
	m_width = CUBE_WIDTH;
	m_height = CUBE_HEIGHT;
	m_depth = CUBE_DEPTH;

	//��
	glm::vec3 leftButtom = { -m_width / 2, -m_height / 2, 0 };
	glm::vec3 rightButtom = { m_width / 2, -m_height / 2, 0 };
	glm::vec3 leftTop = { -m_width / 2, m_height / 2, 0 };
	glm::vec3 rightTop = { m_width / 2, m_height / 2, 0 };

	//��O
	glm::vec3 leftButtomFront = { -m_width / 2, -m_height / 2, m_depth };
	glm::vec3 rightButtomFront = { m_width / 2, -m_height / 2, m_depth };
	glm::vec3 leftTopFront = { -m_width / 2, m_height / 2, m_depth };
	glm::vec3 rightTopFront = { m_width / 2, m_height / 2, m_depth };

	//���_�f�[�^
	float v[VERTICEIS] = {
		leftButtom.x, leftButtom.y, leftButtom.z,//0
		rightButtom.x, rightButtom.y, rightButtom.z,//1
		leftTop.x, leftTop.y, leftTop.z,//2
		rightTop.x, rightTop.y, rightTop.z,//3

		rightTopFront.x, rightTopFront.y, rightTopFront.z,//4
		rightButtomFront.x, rightButtomFront.y, rightButtomFront.z,//5
		leftTopFront.x, leftTopFront.y, leftTopFront.z,//6
		leftButtomFront.x, leftButtomFront.y, leftButtomFront.z,//7
	};

	//�����o�ϐ��ɒ��_�f�[�^���R�s�[
	for (int i = 0; i < VERTICEIS; i++){
		m_vertex[i] = v[i];
	}

	//�C���f�b�N�X�f�[�^
	unsigned int indeces[INDECIES] = {

		//��
		0, 1, 2,
		2, 1, 3,

		//�E
		4, 5, 1,
		1, 4, 3,

		////��O
		6, 7, 5,
		5, 6, 4,

		////��
		0, 7, 6,
		0, 6, 2,

		////��
		6, 4, 2,
		4, 2, 3,

		////��
		7, 5, 0,
		5, 0, 1

	};

	//�����o�ϐ��ɃC���f�b�N�X�f�[�^���R�s�[
	for (int i = 0; i < INDECIES; i++){
		m_index[i] = indeces[i];
	}

	

}


