#include <iostream>
#include <GL/glut.h>

using namespace std;

void DRAW()
{
	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	double vertexX[10] = {0, 1, 1, 0.5, 0, 0, 1, 1, 0.5, 0};
	double vertexY[10] = {0, 0, 1, 1.5, 1, 0, 0, 1, 1.5, 1};
	double vertexZ[10] = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1,};
	double normal[7][3] = { {-1, 0, 0}, {-0.707, 0.707, 0}, {0.707, 0.707, 0}, {1, 0, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1} };
	int faceVertex[7][5] = { {0, 5, 9, 4}, {3, 4, 9, 8}, {2, 3, 8, 7}, {1, 2, 7, 6}, {0, 1, 6, 5}, {5, 6, 7, 8, 9}, {0, 4, 3, 2, 1} };
	int faceAssociatedNormal[7][7] = { {0, 0, 0, 0}, {1, 1, 1, 1}, {2, 2, 2, 2}, {3, 3, 3, 3}, {4, 4, 4, 4}, {5, 5, 5, 5, 5}, {6, 6, 6, 6, 6} };
	
	for (int i = 0; i < 5; i++)
	{
		glBegin(GL_POLYGON);

		glColor3f(1.0, 1.0, 0.0);

		for (int j = 0; j < 4; j++)
		{
			glVertex3f(vertexX[faceVertex[i][j]], vertexY[faceVertex[i][j]], vertexZ[faceVertex[i][j]]);		
		}
		
		glEnd();
		glFlush();
	}

	for (int i = 5; i < 7; i++)
	{
		glBegin(GL_POLYGON);

		glColor3f(1.0, 1.0, 0.0);

		for (int j = 0; j < 5; j++)
		{
			glVertex3f(vertexX[faceVertex[i][j]], vertexY[faceVertex[i][j]], vertexZ[faceVertex[i][j]]);
		}

		glEnd();
		glFlush();
	}
}

int main(int argc, char** argv)
{ 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW4_201801527");
	glutDisplayFunc(DRAW);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 7.0, 15.0);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutMainLoop();

	return 0;
}