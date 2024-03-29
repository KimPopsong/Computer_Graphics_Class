#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

void InitLight() {
	GLfloat MyLightPosition[] = { 1.0, 2.0, 3.0, 1.0 }; // ����?��??����ġ��
	glEnable(GL_LIGHTING);   //  ���Ҹ��iȰ�Ƽ���?ȭ��
	glEnable(GL_LIGHT0);    // 0����?����?��??Ȱ�Ƽ���?ȭ��
	glEnable(GL_DEPTH_TEST);  // ������??ȿ����? �����ب�(shading)
	glLightfv(GL_LIGHT0, GL_POSITION, MyLightPosition);

	GLfloat MyLightAmbient[] = { 0.0, 0.0, 0.0, 1.0 }; //ambient = red
	GLfloat MyLightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // diffuse = yellow
	GLfloat MyLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 }; // specular = white

	glLightfv(GL_LIGHT0, GL_AMBIENT, MyLightAmbient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, MyLightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, MyLightSpecular);
}

void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
	GLfloat mat_shininess[] = { 50.0 };

	GLfloat mat_specular1[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse1[] = { 0.0, 1.0, 0.0, 1.0 };
	GLfloat mat_shininess1[] = { 50.0 };

	GLfloat mat_specular2[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse2[] = { 0.0, 0.0, 1.0, 1.0 };
	GLfloat mat_shininess2[] = { 50.0 };

	GLfloat mat_specular3[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat mat_diffuse3[] = { 1.0, 1.0, 0.0, 1.0 };
	GLfloat mat_shininess3[] = { 50.0 };

	gluLookAt(5, 5, 5, 0, 0, 0, 0, 1, 0);

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular3);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse3);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess3);
	glutSolidCube(4.0);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(-5, 0, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular2);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse2);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess2);
	glutSolidCube(4.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-10, 0, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
	glutSolidCube(4.0);
	glPopMatrix();
	glPushMatrix();
	glTranslatef(-15, 0, 0);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular1);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse1);
	glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess1);
	glutSolidCube(4.0);
	glPopMatrix();
	glFlush();
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow(argv[0]);
	InitLight();
	glutDisplayFunc(display);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-5, 5, -5, 5, 5, 50);
	glutMainLoop();
	return 0;
}