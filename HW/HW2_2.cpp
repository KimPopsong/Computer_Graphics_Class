#include <windows.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <fstream>

void drawPolyLineFile(const char* fileName) 
{
	std::ifstream inStream;

	inStream.open(fileName);

	if (inStream.fail())
		return;

	GLint numpolys, numLines, x, y;
	inStream >> numpolys;

	for (int j = 0; j < numpolys; j++)
	{
		inStream >> numLines;
		glBegin(GL_LINE_STRIP);

		for (int i = 0; i < numLines; i++)
		{
			inStream >> x >> y;
			glVertex3f(x, y, 0.0);
		}

		glEnd();
	}

	glFlush();
	inStream.close();
}

void setWindow(float left, float right, int bottom, int top)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glColor3f(1.0f, 1.0f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(left, right, bottom, top, -10, 100);
}

void render() 
{
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	setWindow(-640, 640, -640, 640);

	glTranslatef(-120.0, 360, 0.0);
	glScalef(0.5, 0.5, 0.5);
	drawPolyLineFile("dino.dat");

	for (int i = 0; i < 11; i++)
	{
		glTranslatef(-320.0, -180.0, 0.0);
		glRotatef(30.0, 0.0, 0.0, 1.0);
		drawPolyLineFile("dino.dat");
	}

	glFlush();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 640);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("201801527_DS KIM");
	glutDisplayFunc(render);;
	glutMainLoop();
	return(0);
}
