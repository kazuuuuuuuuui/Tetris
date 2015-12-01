#include"cube.h"
#include"glm\glm.hpp"
#include"glut.h"


Cube::Cube(){
	m_width = CUBE_WIDTH;
	m_height = CUBE_HEIGHT;
	m_depth = CUBE_DEPTH;

	glm::vec3 leftButtom = { -m_width / 2, -m_height / 2, 0 };
	glm::vec3 rightButtom = { m_width / 2, -m_height / 2, 0 };
	glm::vec3 leftTop = { -m_width / 2, m_height / 2, 0 };
	glm::vec3 rightTop = { m_width / 2, m_height / 2, 0 };

	//頂点データ
	float v[VERTICEIS] = {
		leftButtom.x, leftButtom.y, leftButtom.z,
		rightButtom.x, rightButtom.y, rightButtom.z,
		leftTop.x, leftTop.y, leftTop.z,
		rightTop.x, rightTop.y, rightTop.z,

	};

	//メンバ変数に頂点データをコピー
	for (int i = 0; i < VERTICEIS; i++){
		m_vertex[i] = v[i];
	}

	//インデックスデータ
	unsigned int indeces[INDECIES] = {
		0, 1, 2,
		2, 1, 3
	};

	//メンバ変数にインデックスデータをコピー
	for (int i = 0; i < INDECIES; i++){
		m_index[i] = indeces[i];
	}
}


