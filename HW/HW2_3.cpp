#include <GL/glut.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-150, 150, -150, 150);
}

void DrawHexagon()
{
	glBegin(GL_LINE_STRIP);

	glVertex2f(0, 30);
	glVertex2f(-30, 10);
	glVertex2f(-30, -10);
	glVertex2f(0, -30);
	glVertex2f(30, -10);
	glVertex2f(30, 10);
	glVertex2f(0, 30);

	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	DrawHexagon();
	glTranslatef(60, 0, 0);
	DrawHexagon();
	glTranslatef(-30, -40, 0);
	DrawHexagon();
	glTranslatef(-60, 0, 0);
	DrawHexagon();
	glTranslatef(-30, 40, 0);
	DrawHexagon();
	glTranslatef(30, 40, 0);
	DrawHexagon();
	glTranslatef(60, 0, 0);
	DrawHexagon();
	glTranslatef(60, 0, 0);
	DrawHexagon();
	glTranslatef(30, -40, 0);
	DrawHexagon();
	glTranslatef(-30, -40, 0);
	DrawHexagon();
	glTranslatef(-30, -40, 0);
	DrawHexagon();
	glTranslatef(-60, 0, 0);
	DrawHexagon();
	glTranslatef(-60, 0, 0);
	DrawHexagon();
	glTranslatef(-30, 40, 0);
	DrawHexagon();
	glTranslatef(-30, 40, 0);
	DrawHexagon();
	glTranslatef(30, 40, 0);
	DrawHexagon();
	glTranslatef(30, 40, 0);
	DrawHexagon();
	glTranslatef(60, 0, 0);
	DrawHexagon();
	glTranslatef(60, 0, 0);
	DrawHexagon();

	glFlush();
}

void main(int argc, char** argv)
{
	glutInitWindowSize(640, 640);
	glutCreateWindow("201801527_DS KIM");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
