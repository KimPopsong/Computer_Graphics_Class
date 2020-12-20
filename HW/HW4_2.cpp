#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

static GLuint texName;

struct BitMapFile
{
	int sizeX;
	int sizeY;
	unsigned char* data;
};

BitMapFile* getBMPData(string filename)
{
	BitMapFile* bmp = new BitMapFile;
	unsigned int size, offset, headerSize;

	ifstream infile(filename.c_str(), ios::binary);

	infile.seekg(10);
	infile.read((char*)&offset, 4);

	infile.read((char*)&headerSize, 4);

	infile.seekg(18);
	infile.read((char*)&bmp->sizeX, 4);
	infile.read((char*)&bmp->sizeY, 4);

	size = bmp->sizeX * bmp->sizeY * 24;
	bmp->data = new unsigned char[size];

	infile.seekg(offset);
	infile.read((char*)bmp->data, size);

	int temp;

	for (int i = 0; i < size; i += 3)
	{
		temp = bmp->data[i];
		bmp->data[i] = bmp->data[i + 2];
		bmp->data[i + 2] = temp;
	}

	return bmp;
}

void init(void)
{
	glShadeModel(GL_FLAT);
	glEnable(GL_DEPTH_TEST);

	BitMapFile* image[1];

	image[0] = getBMPData("canTop.bmp");
	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX, image[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image[0]->data);
}

void DRAW()
{
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);

	double vertexX[10] = { 0, 1, 1, 0.5, 0, 0, 1, 1, 0.5, 0 };
	double vertexY[10] = { 0, 0, 1, 1.5, 1, 0, 0, 1, 1.5, 1 };
	double vertexZ[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, };
	double normal[7][3] = { {-1, 0, 0}, {-0.707, 0.707, 0}, {0.707, 0.707, 0}, {1, 0, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
	int faceVertex[7][5] = { {0, 5, 9, 4}, {3, 4, 9, 8}, {2, 3, 8, 7}, {1, 2, 7, 6}, {0, 1, 6, 5}, {5, 6, 7, 8, 9}, {0, 4, 3, 2, 1} };
	int faceAssociatedNormal[7][7] = { {0, 0, 0, 0}, {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {6, 6, 6, 6, 6} };

	for (int i = 0; i < 5; i++)
	{
		glBegin(GL_POLYGON);

		if (i == 1 || i == 2)  //When Draw Roof
		{
			for (int j = 0; j < 4; j++)
			{
				if (j == 0)
					glTexCoord2f(1.0, 0.0);

				else if (j == 1)
					glTexCoord2f(1.0, 0.5 * sqrt(2));

				else if (j == 2)
					glTexCoord2f(0.0, 0.5 * sqrt(2));

				else
					glTexCoord2f(0.0, 0.0);

				glVertex3f(vertexX[faceVertex[i][j]], vertexY[faceVertex[i][j]], vertexZ[faceVertex[i][j]]);
			}
		}

		else  //When Not Roof
		{
			for (int j = 0; j < 4; j++)
			{
				if (j == 0)
					glTexCoord2f(0.0, 0.0);

				else if (j == 1)
					glTexCoord2f(0.0, 2.0);

				else if (j == 2)
					glTexCoord2f(2.0, 2.0);

				else
					glTexCoord2f(2.0, 0.0);

				glVertex3f(vertexX[faceVertex[i][j]], vertexY[faceVertex[i][j]], vertexZ[faceVertex[i][j]]);
			}
		}

		glEnd();
		glFlush();
	}

	for (int i = 5; i < 7; i++)  //Front & Back
	{
		glBegin(GL_POLYGON);

		for (int j = 0; j < 5; j++)
		{
			if (j == 0)
				glTexCoord2f(0.0, 0.0);

			else if (j == 1)
				glTexCoord2f(2.0, 0.0);

			else if (j == 2)
				glTexCoord2f(2.0, 2.0);

			else if (j == 3)
				glTexCoord2f(1.0, 3.0);

			else
				glTexCoord2f(0.0, 2.0);

			glVertex3f(vertexX[faceVertex[i][j]], vertexY[faceVertex[i][j]], vertexZ[faceVertex[i][j]]);
		}

		glEnd();
		glFlush();
	}
	glDisable(GL_TEXTURE_2D);
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW4_201801527");
	init();
	glutDisplayFunc(DRAW);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 5.0, 15.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutMainLoop();

	return 0;
}