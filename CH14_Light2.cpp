#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

void InitLight() {
	GLfloat MyLightPosition[] = { 1.0, 2.0, 3.0, 1.0 }; // ±¤¿øÀÇ À§Ä¡
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0); 
	glEnable(GL_DEPTH_TEST);  // shading
	glLightfv(GL_LIGHT0, GL_POSITION, MyLightPosition);

	GLfloat MyLightAmbient[] = { 0.0, 0.0, 0.0, 1.0 }; //ambient = red
	GLfloat MyLightDiffuse[] = { 1.0, 1.0, 0.0, 1.0 }; // diffuse = yellow
	GLfloat MyLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 }; // specular = white

	glLightfv(GL_LIGHT0, GL_AMBIENT, MyLightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, MyLightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, MyLightSpecular);

	glLightf(GL_LIGHT0, GL_CONSTANT_ATTENUATION, 0.0);
	glLightf(GL_LIGHT0, GL_LINEAR_ATTENUATION, 1.0);
	glLightf(GL_LIGHT0, GL_QUADRATIC_ATTENUATION, 0.0);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glutSolidSphere(1.0, 20, 16);
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	InitLight();
	glutDisplayFunc(display);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-2, 2, -2, 2, -1, 1);
	glutMainLoop();
	return 0;
}