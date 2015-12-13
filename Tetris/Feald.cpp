#include"Feald.h"
#include"oka_library\Material.h"
#include"glut.h"

Feald *feald[FEALD_HEIGHT][FEALD_WIDTH];
Feald *buffer[FEALD_HEIGHT][FEALD_WIDTH];



unsigned char *p = nullptr;

//�u���b�N�p�̗����̂̓o�^
void setCube(){
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	//���_�z��
	float v[] = {
		//��O
		-1, 1, 1, //0
		-1, -1, 1, //1
		1, 1, 1, //2
		1, -1, 1, //3

		//�E
		1, 1, 1, //4
		1, -1, 1, //5
		1, 1, -1, //6
		1, -1, -1, //7

		//��
		1, 1, -1, //8
		1, -1, -1, //9
		-1, 1, -1, //10
		-1, -1, -1, //11

		//��
		-1, 1, -1, //12
		-1, -1, -1, //13
		-1, 1, 1, //14
		-1, -1, 1, //15

		//���
		-1, 1, -1, //16
		-1, 1, 1, //17
		1, 1, -1, //18
		1, 1, 1, //19

		//���
		-1, -1, -1, //20
		-1, -1, 1, //21
		1, -1, -1, //22
		1, -1, 1, //23
	};

	//�@���z��
	float n[] = {
		//��O
		0, 0, 1, //0
		0, 0, 1, //1
		0, 0, 1, //2
		0, 0, 1, //3

		//�E
		1, 0, 0, //4
		1, 0, 0, //5
		1, 0, 0, //6
		1, 0, 0, //7

		//��
		0, 0, -1, //8
		0, 0, -1, //9
		0, 0, -1, //10
		0, 0, -1, //11

		//��
		-1, 0, 0, //12
		-1, 0, 0, //13 
		-1, 0, 0, //14
		-1, 0, 0, //15

		//���
		0, 1, 0, //16
		0, 1, 0, //17
		0, 1, 0, //18
		0, 1, 0, //19

		//���
		0, -1, 0, //20
		0, -1, 0, //21
		0, -1, 0, //22
		0, -1, 0, //23
	};

	glVertexPointer(
		3,//GLint size(��������)
		GL_FLOAT,//GLenum type
		0,//GLsizei stride//���_�f�[�^�̊Ԋu
		v//const GLvoid *pointer
		);

	glNormalPointer(
		GL_FLOAT,
		0,
		n);

	//�C���f�b�N�X�z��
	unsigned char indeces[] = {
		0, 1, 2, //��O
		1, 3, 2, //��O
		4, 5, 6, //�E
		5, 7, 6, //�E
		8, 9, 10, //��
		9, 11, 10, //��
		12, 13, 14, //��
		13, 15, 14, //��
		16, 17, 18, //���
		17, 19, 18, //���
		20, 22, 21, //���
		22, 23, 21  //���
	};

	p = indeces;
}

void Feald::draw(){
	/*�Ƃ肠����*/
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);

	//���_�z��
	float v[] = {
		//��O
		-1, 1, 1, //0
		-1, -1, 1, //1
		1, 1, 1, //2
		1, -1, 1, //3

		//�E
		1, 1, 1, //4
		1, -1, 1, //5
		1, 1, -1, //6
		1, -1, -1, //7

		//��
		1, 1, -1, //8
		1, -1, -1, //9
		-1, 1, -1, //10
		-1, -1, -1, //11

		//��
		-1, 1, -1, //12
		-1, -1, -1, //13
		-1, 1, 1, //14
		-1, -1, 1, //15

		//���
		-1, 1, -1, //16
		-1, 1, 1, //17
		1, 1, -1, //18
		1, 1, 1, //19

		//���
		-1, -1, -1, //20
		-1, -1, 1, //21
		1, -1, -1, //22
		1, -1, 1, //23
	};

	//�@���z��
	float n[] = {
		//��O
		0, 0, 1, //0
		0, 0, 1, //1
		0, 0, 1, //2
		0, 0, 1, //3

		//�E
		1, 0, 0, //4
		1, 0, 0, //5
		1, 0, 0, //6
		1, 0, 0, //7

		//��
		0, 0, -1, //8
		0, 0, -1, //9
		0, 0, -1, //10
		0, 0, -1, //11

		//��
		-1, 0, 0, //12
		-1, 0, 0, //13 
		-1, 0, 0, //14
		-1, 0, 0, //15

		//���
		0, 1, 0, //16
		0, 1, 0, //17
		0, 1, 0, //18
		0, 1, 0, //19

		//���
		0, -1, 0, //20
		0, -1, 0, //21
		0, -1, 0, //22
		0, -1, 0, //23
	};

	glVertexPointer(
		3,//GLint size(��������)
		GL_FLOAT,//GLenum type
		0,//GLsizei stride//���_�f�[�^�̊Ԋu
		v//const GLvoid *pointer
		);

	glNormalPointer(
		GL_FLOAT,
		0,
		n);

	//�C���f�b�N�X�z��
	unsigned char indeces[] = {
		0, 1, 2, //��O
		1, 3, 2, //��O
		4, 5, 6, //�E
		5, 7, 6, //�E
		8, 9, 10, //��
		9, 11, 10, //��
		12, 13, 14, //��
		13, 15, 14, //��
		16, 17, 18, //���
		17, 19, 18, //���
		20, 22, 21, //���
		22, 23, 21  //���
	};

	//�}�e���A�������߂�
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

		//�u���b�N�`��
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

		//�u���b�N�`��
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


		//�u���b�N�`��
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

		//�u���b�N�`��
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

		//�u���b�N�`��
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

		//�u���b�N�`��
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

		//�u���b�N�`��
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

		//�u���b�N�`��
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
