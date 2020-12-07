#include <GL/glut.h>

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.0);
	gluLookAt(0.0, 7.0, 10.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	// Front faces filled, back faces outlined.  
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);   glBegin(GL_POLYGON);
	glVertex3f(-5.0, 1.0, 5.0); //P1  
	glVertex3f(-5.0, -1.0, 5.0); // P2 
	glVertex3f(5.0, 1.0, 5.0); //P3 
	glEnd();
	glFlush();
}

// Main routine.  
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("squareOfWalls.cpp");
	glutDisplayFunc(drawScene);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutMainLoop();
	return 0;
}