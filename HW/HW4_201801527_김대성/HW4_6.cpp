#include <iostream>
#include <cmath>
#include <GL/glut.h>

using namespace std;

float controlPoints[7][3] = { { -1.0, -3.0 }, { -3.0, 1.0 }, { -1.0, 5.0 }, { 0.5, 2.0 }, { 2.9, 4.4 }, { 3.8, 2.8 }, { 2.8, 0.4 } };

double G(float i, float j)
{
	double t = i - j;

	if ((i - j) <= 1)
	{
		return  t * t * 0.5;
	}

	else if ((i - j) <= 2)
	{
		return  - ((t - 1.5) * (t - 1.5)) + 0.75;
	}

	else
	{
		return (3 - t) * (3 - t) * 0.5;
	}
}

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_LINE_STRIP);
	for (int i = 0; i < 7; i++)
	{
		glVertex2f(controlPoints[i][0], controlPoints[i][1]);
	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (float i = 2; i <= 7; i += 0.001)  //t
	{	
		double x = 0, y = 0;

		for (float j = 0; j <= 6; j += 1)  //k
		{
			
			if ((0 > (i - j)) || (i - j) > 3)
			{
				continue;
			}

			x += controlPoints[(int)j][0] * G(i, j);
			y += controlPoints[(int)j][1] * G(i, j);		
		}

		glVertex2f(x, y);	
	}
	glEnd();

	glPointSize(7.5);
	glColor3f(1.0, 0.0, 1.0);

	glBegin(GL_POINTS);
	for (int i = 0; i < 7; i++)
	{
		glVertex2fv(controlPoints[i]);
	}
	glEnd();

	glFlush();
}

int main()
{
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW4_201801527");
	glutDisplayFunc(Draw);
	gluOrtho2D(-10, 10, -10, 10);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutMainLoop();

	return 0;
}
