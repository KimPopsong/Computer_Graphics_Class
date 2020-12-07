#include <GL/glut.h>

void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	// glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	// glEnable(GL_DEPTH_TEST);  
	// Front faces filled, back faces outlined. 
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 0.0, -10.0);
	glVertex3f(5.0, 0.0, -10.0);
	glVertex3f(0.0, 5.0, -10.0);
	glEnd();
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	glVertex3f(-5.0, 0.0, -15.0);
	glVertex3f(5.0, 0.0, -15.0);
	glVertex3f(0.0, 5.0, -15.0);
	glEnd();
	glFlush();

}
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	//   glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); 
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("squareOfWalls.cpp");
	glutDisplayFunc(drawScene);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutMainLoop();
}