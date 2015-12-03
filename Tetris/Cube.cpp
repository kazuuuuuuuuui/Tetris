#include"cube.h"
#include"glm\glm.hpp"
#include"glut.h"


Cube::Cube(){
	m_width = CUBE_WIDTH;
	m_height = CUBE_HEIGHT;
	m_depth = CUBE_DEPTH;

	//奥
	glm::vec3 leftButtom = { -m_width / 2, -m_height / 2, 0 };
	glm::vec3 rightButtom = { m_width / 2, -m_height / 2, 0 };
	glm::vec3 leftTop = { -m_width / 2, m_height / 2, 0 };
	glm::vec3 rightTop = { m_width / 2, m_height / 2, 0 };

	//手前
	glm::vec3 leftButtomFront = { -m_width / 2, -m_height / 2, m_depth };
	glm::vec3 rightButtomFront = { m_width / 2, -m_height / 2, m_depth };
	glm::vec3 leftTopFront = { -m_width / 2, m_height / 2, m_depth };
	glm::vec3 rightTopFront = { m_width / 2, m_height / 2, m_depth };

	//頂点データ
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

	//メンバ変数に頂点データをコピー
	for (int i = 0; i < VERTICEIS; i++){
		m_vertex[i] = v[i];
	}

	//インデックスデータ
	unsigned int indeces[INDECIES] = {

		//奥
		0, 1, 2,
		2, 1, 3,

		//右
		4, 5, 1,
		1, 4, 3,

		////手前
		6, 7, 5,
		5, 6, 4,

		////左
		0, 7, 6,
		0, 6, 2,

		////上
		6, 4, 2,
		4, 2, 3,

		////底
		7, 5, 0,
		5, 0, 1

	};

	//メンバ変数にインデックスデータをコピー
	for (int i = 0; i < INDECIES; i++){
		m_index[i] = indeces[i];
	}

	

}


