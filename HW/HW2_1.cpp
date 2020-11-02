#include <GL/glut.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(0.0f, 0.0f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-25, 25, -25, 25);
}

void DrawSnow()
{
	glBegin(GL_LINE_STRIP);
	glVertex2f(1, 0.5);
	glVertex2f(10, 0.5);
	glVertex2f(15, 3);
	glVertex2f(16, 3);
	glVertex2f(11, 0.5);
	glVertex2f(16, 0.5);
	glVertex2f(21, 3);
	glVertex2f(22, 3);
	glVertex2f(17, 0.5);
	glVertex2f(25, 0.5);
	glVertex2f(25, 0);
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);

	glViewport(-100, 200, -100, 200);

	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();

	glScalef(-1.0, 1.0, 1.0);

	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();
	glRotatef(60, 0.0, 0.0, 1.0);
	DrawSnow();

	glFlush();
}

void main(int argc, char** argv)
{
	glutInitWindowSize(640, 640);
	glutCreateWindow("my first attempt");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
