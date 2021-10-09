#include <iostream>

#include<GL/glut.h>

using namespace std;
static GLint fogMode;
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_DEPTH_TEST); // Enable depth testing.

							 // Turn on OpenGL lighting.
	glEnable(GL_LIGHTING);

	// Light property vectors.
	float lightAmb[] = { 0.0, 0.0, 0.0, 1.0 };
	float lightDifAndSpec[] = { 1.0, 1.0, 1.0, 1.0 };
	float lightPos[] = { 30.0, 30.0, 30.0, 1.0 };

	// Light properties.
	glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmb);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_SPECULAR, lightDifAndSpec);
	glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
	glEnable(GL_LIGHT0); // Enable particular light source.

						 // Material property vectors.
	float matSpec[] = { 1.0, 1.0, 1.0, 1.0 };
	float matDiffuse[] = { 0.0, 1.0, 0.0, 1.0 };
	float matShine[] = { 50.0 };

	// Material properties.
	glMaterialfv(GL_FRONT, GL_DIFFUSE, matDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, matSpec);
	glMaterialfv(GL_FRONT, GL_SHININESS, matShine);

	glEnable(GL_FOG);
	GLfloat fogColor[4] = { 1.0, 1.0, 1.0, 1.0 };
	fogMode = GL_EXP2;
	glFogi(GL_FOG_MODE, fogMode);
	glFogfv(GL_FOG_COLOR, fogColor);
	glFogf(GL_FOG_DENSITY, 0.03);
	glHint(GL_FOG_HINT, GL_NICEST);
}

// Drawing routine.
void drawScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(5.0, 20.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	glPushMatrix();
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(2.0, 5.0, 80, 80);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -40.0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(2.0, 5.0, 80, 80);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, -20.0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(2.0, 5.0, 80, 80);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0.0, 0.0, 15.0);
	glRotatef(90, 1, 0, 0);
	glutSolidTorus(2.0, 5.0, 80, 80);
	glPopMatrix();

	glFlush();
}


// Main routine.
int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(700, 700);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("ballAndTorusReflected.cpp");
	glutDisplayFunc(drawScene);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
	setup();
	glutMainLoop();
}