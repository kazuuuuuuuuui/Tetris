#include"Feald.h"
#include"oka_library\Material.h"
#include"glut.h"

Feald *feald[FEALD_HEIGHT][FEALD_WIDTH];
Feald *buffer[FEALD_HEIGHT][FEALD_WIDTH];



unsigned char *p = nullptr;

//ブロック用の立方体の登録
void setCube(){
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	//頂点配列
	float v[] = {
		//手前
		-1, 1, 1, //0
		-1, -1, 1, //1
		1, 1, 1, //2
		1, -1, 1, //3

		//右
		1, 1, 1, //4
		1, -1, 1, //5
		1, 1, -1, //6
		1, -1, -1, //7

		//奥
		1, 1, -1, //8
		1, -1, -1, //9
		-1, 1, -1, //10
		-1, -1, -1, //11

		//左
		-1, 1, -1, //12
		-1, -1, -1, //13
		-1, 1, 1, //14
		-1, -1, 1, //15

		//上面
		-1, 1, -1, //16
		-1, 1, 1, //17
		1, 1, -1, //18
		1, 1, 1, //19

		//底面
		-1, -1, -1, //20
		-1, -1, 1, //21
		1, -1, -1, //22
		1, -1, 1, //23
	};

	//法線配列
	float n[] = {
		//手前
		0, 0, 1, //0
		0, 0, 1, //1
		0, 0, 1, //2
		0, 0, 1, //3

		//右
		1, 0, 0, //4
		1, 0, 0, //5
		1, 0, 0, //6
		1, 0, 0, //7

		//奥
		0, 0, -1, //8
		0, 0, -1, //9
		0, 0, -1, //10
		0, 0, -1, //11

		//左
		-1, 0, 0, //12
		-1, 0, 0, //13 
		-1, 0, 0, //14
		-1, 0, 0, //15

		//上面
		0, 1, 0, //16
		0, 1, 0, //17
		0, 1, 0, //18
		0, 1, 0, //19

		//底面
		0, -1, 0, //20
		0, -1, 0, //21
		0, -1, 0, //22
		0, -1, 0, //23
	};

	glVertexPointer(
		3,//GLint size(何次元か)
		GL_FLOAT,//GLenum type
		0,//GLsizei stride//頂点データの間隔
		v//const GLvoid *pointer
		);

	glNormalPointer(
		GL_FLOAT,
		0,
		n);

	//インデックス配列
	unsigned char indeces[] = {
		0, 1, 2, //手前
		1, 3, 2, //手前
		4, 5, 6, //右
		5, 7, 6, //右
		8, 9, 10, //奥
		9, 11, 10, //奥
		12, 13, 14, //左
		13, 15, 14, //左
		16, 17, 18, //上面
		17, 19, 18, //上面
		20, 22, 21, //底面
		22, 23, 21  //底面
	};

	p = indeces;
}

void Feald::draw(){
	/*とりあえず*/
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	//頂点配列
	float v[] = {
		//手前
		-1, 1, 1, //0
		-1, -1, 1, //1
		1, 1, 1, //2
		1, -1, 1, //3

		//右
		1, 1, 1, //4
		1, -1, 1, //5
		1, 1, -1, //6
		1, -1, -1, //7

		//奥
		1, 1, -1, //8
		1, -1, -1, //9
		-1, 1, -1, //10
		-1, -1, -1, //11

		//左
		-1, 1, -1, //12
		-1, -1, -1, //13
		-1, 1, 1, //14
		-1, -1, 1, //15

		//上面
		-1, 1, -1, //16
		-1, 1, 1, //17
		1, 1, -1, //18
		1, 1, 1, //19

		//底面
		-1, -1, -1, //20
		-1, -1, 1, //21
		1, -1, -1, //22
		1, -1, 1, //23
	};

	//法線配列
	float n[] = {
		//手前
		0, 0, 1, //0
		0, 0, 1, //1
		0, 0, 1, //2
		0, 0, 1, //3

		//右
		1, 0, 0, //4
		1, 0, 0, //5
		1, 0, 0, //6
		1, 0, 0, //7

		//奥
		0, 0, -1, //8
		0, 0, -1, //9
		0, 0, -1, //10
		0, 0, -1, //11

		//左
		-1, 0, 0, //12
		-1, 0, 0, //13 
		-1, 0, 0, //14
		-1, 0, 0, //15

		//上面
		0, 1, 0, //16
		0, 1, 0, //17
		0, 1, 0, //18
		0, 1, 0, //19

		//底面
		0, -1, 0, //20
		0, -1, 0, //21
		0, -1, 0, //22
		0, -1, 0, //23
	};

	glVertexPointer(
		3,//GLint size(何次元か)
		GL_FLOAT,//GLenum type
		0,//GLsizei stride//頂点データの間隔
		v//const GLvoid *pointer
		);

	glNormalPointer(
		GL_FLOAT,
		0,
		n);

	//インデックス配列
	unsigned char indeces[] = {
		0, 1, 2, //手前
		1, 3, 2, //手前
		4, 5, 6, //右
		5, 7, 6, //右
		8, 9, 10, //奥
		9, 11, 10, //奥
		12, 13, 14, //左
		13, 15, 14, //左
		16, 17, 18, //上面
		17, 19, 18, //上面
		20, 22, 21, //底面
		22, 23, 21  //底面
	};

	//マテリアルを決める
	switch (m_type){
	case NORMAL:{

		float diffuse[] = { 255 / 255.f, 255 / 255.f, 255 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

		glBegin(GL_QUADS);
		{
			glTexCoord3f(0, 0, 1.f);
			glVertex3f(m_position.x - 1, m_position.y - 1, m_position.z);
			glVertex3f(m_position.x + 1, m_position.y - 1, m_position.z);
			glVertex3f(m_position.x + 1, m_position.y + 1, m_position.z);
			glVertex3f(m_position.x - 1, m_position.y + 1, m_position.z);
		}
		glEnd();

		break;
	}

	case WALL:{

		float diffuse[] = { 128 / 255.f, 128 / 255.f, 128 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

		//ブロック描画
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glDrawElements(
			GL_TRIANGLES,//GLenum mode
			36,//GLsizei count
			GL_UNSIGNED_BYTE,//GLenum type
			indeces//const GLvoid *indices
			);
		glPopMatrix();

		break;
	}


	case TYPE_O:{

		float diffuse[] = { 255 / 255.f, 255 / 255.f, 33 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

		//ブロック描画
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glDrawElements(
			GL_TRIANGLES,//GLenum mode
			36,//GLsizei count
			GL_UNSIGNED_BYTE,//GLenum type
			indeces//const GLvoid *indices
			);
		glPopMatrix();

		break;
	}

	case TYPE_I:{

		float diffuse[] = { 82 / 255.f, 226 / 255.f, 255 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);


		//ブロック描画
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glDrawElements(
			GL_TRIANGLES,//GLenum mode
			36,//GLsizei count
			GL_UNSIGNED_BYTE,//GLenum type
			indeces//const GLvoid *indices
			);
		glPopMatrix();

		break;
	}

	case TYPE_invT:{

		float diffuse[] = { 255 / 255.f, 27 / 255.f, 253 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

		//ブロック描画
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glDrawElements(
			GL_TRIANGLES,//GLenum mode
			36,//GLsizei count
			GL_UNSIGNED_BYTE,//GLenum type
			indeces//const GLvoid *indices
			);
		glPopMatrix();

		break;
	}

	case TYPE_L:{

		float diffuse[] = { 255 / 255.f, 172 / 255.f, 50 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

		//ブロック描画
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glDrawElements(
			GL_TRIANGLES,//GLenum mode
			36,//GLsizei count
			GL_UNSIGNED_BYTE,//GLenum type
			indeces//const GLvoid *indices
			);
		glPopMatrix();

		break;
	}

	case TYPE_invL:{

		float diffuse[] = { 22 / 255.f, 22 / 255.f, 203 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

		//ブロック描画
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glDrawElements(
			GL_TRIANGLES,//GLenum mode
			36,//GLsizei count
			GL_UNSIGNED_BYTE,//GLenum type
			indeces//const GLvoid *indices
			);
		glPopMatrix();

		break;
	}

	case TYPE_Z:{

		float diffuse[] = { 241 / 255.f, 27 / 255.f, 27 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

		//ブロック描画
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glDrawElements(
			GL_TRIANGLES,//GLenum mode
			36,//GLsizei count
			GL_UNSIGNED_BYTE,//GLenum type
			indeces//const GLvoid *indices
			);
		glPopMatrix();

		break;
	}

	case TYPE_invZ:{

		float diffuse[] = { 55 / 255.f, 255 / 255.f, 73 / 255.f, 1 };
		glMaterialfv(GL_FRONT, GL_DIFFUSE, diffuse);

		//ブロック描画
		glPushMatrix();
		glTranslatef(m_position.x, m_position.y, m_position.z);
		glDrawElements(
			GL_TRIANGLES,//GLenum mode
			36,//GLsizei count
			GL_UNSIGNED_BYTE,//GLenum type
			indeces//const GLvoid *indices
			);
		glPopMatrix();

		break;
	}

	}
	
}
