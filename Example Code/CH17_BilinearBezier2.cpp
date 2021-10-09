#include <GL/glut.h> // we will use GLUT (GL UTILITY TOOLKIT)
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glLoadIdentity();
	gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	int i;
	int j;
	int NUM = 100;
	double u;
	double v;

	glBegin(GL_POINTS);

	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			u = double(i) / (NUM * 1.0);
			v = double(j) / (NUM * 1.0);

			glVertex3f((1 - u) * (1 - v) * -1 + u * (1 - v) * 1 + v * (1 - u) * -1 + u * v * 1, (1 - u) * (1 - v) * 0 + u * (1 - v) * 0 + v * (1 - u) * 2 + u * v * 0, -2 * u * (1 - v));
		}

	}

	glEnd();