#include <GL/glut.h>
#include <math.h>

void myInit(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glColor3f(0.0f, 0.0f, 0.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-150, 150, -150, 150);
}

void DrawHexagon()
{
    glBegin(GL_LINE_STRIP);

    double x = (20 * sqrt(7) - 20);

    glVertex2f(0, 30);
    glVertex2f(-30, (20 * sqrt(7) - 20) / 2);
    glVertex2f(-30, -(20 * sqrt(7) - 20) / 2);
    glVertex2f(0, -30);
    glVertex2f(30, -(20 * sqrt(7) - 20) / 2);
    glVertex2f(30, (20 * sqrt(7) - 20) / 2);
    glVertex2f(0, 30);

    glEnd();
}

void myDisplay(void)
{
    double x = 30 + (20 * sqrt(7) - 20) / 2;

    DrawHexagon();
    glTranslatef(60, 0, 0);
    DrawHexagon();
    glTranslatef(-30, -x, 0);
    DrawHexagon();
    glTranslatef(-60, 0, 0);
    DrawHexagon();
    glTranslatef(-30, x, 0);
    DrawHexagon();
    glTranslatef(-60, 0, 0);
    DrawHexagon();
    glTranslatef(30, -x, 0);
    DrawHexagon();
    glTranslatef(30, -x, 0);
    DrawHexagon();
    glTranslatef(60, 0, 0);
    DrawHexagon();
    glTranslatef(60, 0, 0);
    DrawHexagon();
    glTranslatef(30, x, 0);
    DrawHexagon();
    glTranslatef(30, x, 0);
    DrawHexagon();
    glTranslatef(-120, 0, 0);

    glFlush();
}

void draw()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    myDisplay();
    glScalef(1.0, -1.0, 1.0);
    myDisplay();
    glFlush();
}

void main(int argc, char** argv)
{
    glutInitWindowSize(640, 640);
    glutCreateWindow("201801527_DS KIM");
    glutDisplayFunc(draw);
    glMatrixMode(GL_MODELVIEW);
    myInit();
    glutMainLoop();
}