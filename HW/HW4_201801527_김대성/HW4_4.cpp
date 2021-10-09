#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

void display(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glBegin(GL_QUADS);
	glColor4f(0.0, 0.0, 1.0, 0.5);
	glVertex2f(-1.5, 0.0);
	glVertex2f(2.5, 0.0);
	glVertex2f(2.5, -1.0);
	glVertex2f(-1.5, -1.0);
	glEnd();

	glBegin(GL_QUADS);
	glColor4f(1.0, 0.0, 0.0, 0.5);
	glVertex2f(1.5, -1.5);
	glVertex2f(1.5, 2.0);
	glVertex2f(0.5, 2.0);
	glVertex2f(0.5, -1.5);
	glEnd();

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(700, 700);
	glutCreateWindow("HW4_201801527");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 3, -2, 3, -1, 1);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}