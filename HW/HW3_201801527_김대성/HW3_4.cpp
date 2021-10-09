#include <GL/glut.h> 

float controlPoints1[4][3] = { { -3.0, 2.0 }, { 1.0, -5.0 }, { 14.0, -4.0 }, { 16.0, 5.0 } };
float controlPoints2[4][3] = { { 16.0, 5.0 }, { 16.0, 16.0 }, { 5.0, 20.0 },{ 0.0, 15.0 } };

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	glVertex3f(0.0, 15.0, 0.0);
	glVertex3f(5.0, 30.0, 0.0);
	glVertex3f(17.5, 30.0, 0.0);
	glEnd();

	glEnable(GL_MAP1_VERTEX_3);

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, controlPoints1[0]);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 100; i++)
	{
		glEvalCoord1f((double)i / 100);
	}
	glEnd();

	glMap1f(GL_MAP1_VERTEX_3, 0.0, 1.0, 3, 4, controlPoints2[0]);
	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 100; i++)
	{
		glEvalCoord1f((double)i / 100);
	}
	glEnd();

	glPointSize(7.5);
	glColor3f(1.0, 0.0, 1.0);
	glBegin(GL_POINTS);
	for (int i = 0; i < 4; i++)
	{
		glVertex2fv(controlPoints1[i]);
		glVertex2fv(controlPoints2[i]);
	}
	glEnd();
	glFlush();
}

int main()
{
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW3_201801527");
	glutDisplayFunc(Draw);
	gluOrtho2D(-25, 50, -25, 50);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutMainLoop();

	return 0;
}

