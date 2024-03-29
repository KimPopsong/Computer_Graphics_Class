#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glut.h>

float matrixdata[16] = // Shear matrix.
{
   1.0, 0, 0.0, 0.0, 0.2, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0
};


void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
	glColor3f(1.0f, 0.0f, 0.0f);         // the drawing color is black 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-5, 5, -5, 5, -1, 1);

}

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glMultMatrixf(matrixdata);  
	glBegin(GL_QUADS);
	glVertex3f(-1, 1, 0.0);
	glVertex3f(-1, -1, 0.0);
	glVertex3f(1, -1, 0.0);
	glVertex3f(1, 1, 0.0);
	glEnd();
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow("box.cpp");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(drawScene);
	myInit();

	glutMainLoop();
	return 0;
}