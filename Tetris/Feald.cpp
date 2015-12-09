#include"Feald.h"
#include"Material.h"
#include"glut.h"

Feald *feald[FEALD_HEIGHT][FEALD_WIDTH];
Feald *buffer[FEALD_HEIGHT][FEALD_WIDTH];

unsigned char *p = nullptr;

//ゴム(緑)
Material green_rubber = {
	{ 0.0, 0.05, 0.0, 1.0 },
	{ 0.4, 0.5, 0.4, 1.0 },
	{ 0.04, 0.7, 0.04, 1.0 },
	10.0 };

//シアン
Material cyan_plastic = {
	{ 0.0, 0.1, 0.06, 1.0 },
	{ 0.0, 0.50980392, 0.50980392, 1.0 },
	{ 0.50196078, 0.50196078, 0.50196078, 1.0 },
	32 };

//プラスチック(青)
Material blue_plastic = {
	{ 0.0, 0.0, 0.0, 1.0 },
	{ 0.0, 0.0, 1.0, 1.0 },
	{ 0.0, 0.20, 0.50, 1.0 },
	32 };

Material yellowGreen = {
	{ 0.0, 0.0, 0.0, 1.0 },
	{ 0.0, 0.8, 0.3, 1.0 },
	{ 0.0, 0.80, 0.30, 1.0 },
	32 };

Material ruby = {
	{ 0.1745, 0.01175, 0.01175, 1.0 },
	{ 0.61424, 0.04136, 0.04136, 1.0 },
	{ 0.727811, 0.626959, 0.626959, 1.0 },
	76.8 };

Material green_plastic = {
	{ 0.0, 0.0, 0.0, 1.0 },
	{ 0.1, 0.35, 0.1, 1.0 },
	{ 0.45, 0.55, 0.45, 1.0 },
	32 };

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
	case NORMAL:
	
		glMaterialfv(GL_FRONT, GL_AMBIENT, white_plastic.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, white_plastic.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, white_plastic.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, white_plastic.shininess);

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
	

	case WALL:

		glMaterialfv(GL_FRONT, GL_AMBIENT, obsidian.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, obsidian.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, obsidian.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, obsidian.shininess);

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

	case TYPE_O:

		glMaterialfv(GL_FRONT, GL_AMBIENT, bronze.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, bronze.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, bronze.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, bronze.shininess);

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

	case TYPE_I:

		glMaterialfv(GL_FRONT, GL_AMBIENT, green_rubber.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, green_rubber.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, green_rubber.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, green_rubber.shininess);

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

	case TYPE_invT:

		glMaterialfv(GL_FRONT, GL_AMBIENT, cyan_plastic.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, cyan_plastic.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, cyan_plastic.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, cyan_plastic.shininess);

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

	case TYPE_L:

		glMaterialfv(GL_FRONT, GL_AMBIENT, blue_plastic.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, blue_plastic.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, blue_plastic.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, blue_plastic.shininess);

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

	case TYPE_invL:

		glMaterialfv(GL_FRONT, GL_AMBIENT, yellowGreen.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, yellowGreen.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, yellowGreen.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, yellowGreen.shininess);

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

	case TYPE_Z:

		glMaterialfv(GL_FRONT, GL_AMBIENT, ruby.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, ruby.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, ruby.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, ruby.shininess);

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

	case TYPE_invZ:

		glMaterialfv(GL_FRONT, GL_AMBIENT, green_plastic.ambient);
		glMaterialfv(GL_FRONT, GL_DIFFUSE, green_plastic.diffuse);
		glMaterialfv(GL_FRONT, GL_SPECULAR, green_plastic.specular);
		glMaterialf(GL_FRONT, GL_SHININESS, green_plastic.shininess);

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
