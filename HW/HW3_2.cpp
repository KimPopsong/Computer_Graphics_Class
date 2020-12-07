#include <stdio.h>
#include <cstdlib>
#include <GL/glut.h>

int count = 0;

void pickPixel(int x, int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x, y);
	glEnd();
}

int round(float z)
{
	int y;
	y = z > 0.0 ? int(z + 0.5) : int(z - 0.5);
	return y;
}

void DDA(int i1, int j1, int i2, int j2) 
{
	float y = j1;
	float m = float(j2 - j1) / (i2 - i1);

	for (int x = i1; x <= i2; x++)
	{
		pickPixel(x, round(y));
		y += m;
	}
}

void MidpointLine(int x1, int y1, int x2, int y2)
{
	int dx, dy, incrN, incrNE, D, x, y;

	dx = x2 - x1; dy = y2 - y1;
	D = -2 * dx + dy;
	incrN = -2 * dx;
	incrNE = -2 * dx + 2 * dy;
	x = x1; y = y1; 

	pickPixel(x, y);

	while (y < y2)
	{
		printf("중점 : %d\n", D);
		count += 1;

		if (D <= 0)
		{
			D += incrNE;
			y++;	
		}

		else
		{
			D += incrN;
			x++; y++;
		}

		pickPixel(x, y);
	}

	printf("총 이용한 중점의 수 : %d\n", count);
}

void drawScene(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 1.0, 1.0);

	//DDA(100, 100, 300, 200);
	MidpointLine(0, 0, 5, 9);

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(200, 200);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW3_201801527");
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutDisplayFunc(drawScene);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 10, 0.0, 10);
	glutMainLoop();

	return 0;
}