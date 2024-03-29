#include <GL/glut.h>

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glColor3f(1.0f, 0.0f, 0.0f); // the drawing color is black   
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
}

void Display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0, 0.0, -15.0);
	glPushMatrix();
	glScalef(1.0, 2.0, 1.0);
	glutWireCube(5.0);
	glPopMatrix();
	glTranslatef(0.0, 7.0, 0.0);
	glutWireSphere(2.0, 10, 8);
	glFlush();
}

int main()
{
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("OpenGL Hello World!");
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutDisplayFunc(Display);
	myInit();
	glutMainLoop();
	return 0;
}