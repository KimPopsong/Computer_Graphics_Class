#include <GL/glut.h>           //   we will use GLUT (GL UTILITY TOOLKIT)
void Display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	int i;
	int NUM = 400;
	double u;
	double v;
	glBegin(GL_LINE_STRIP);
	for (i = 0; i < NUM; i++)
	{
		u = double(i) / (NUM * 1.0);
		v = u + 1 / (NUM * 1.0);
		glVertex2f(2 * u + 3 * u * u, -1 + 6 * u - 6 * u * u);
		glVertex2f(2 * v + 3 * v * v, -1 + 6 * v - 6 * v * v);
	}
	glEnd();

	glFlush();
}
int main() {
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("OpenGL Hello World!");
	glutDisplayFunc(Display);
	glClearColor(0.0, 0.0, 0.0, 0.0);
	gluOrtho2D(0, 5, -1, 2);
	glutMainLoop();
	return 0;
}