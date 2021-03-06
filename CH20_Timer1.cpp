#include <GL/glut.h>
GLfloat size = 0.5;
GLfloat x = 0;
GLfloat dx = 0.10;
static float t = 0.0; // Time parameter.
void DoTimer(int value)
{
    x += dx;
    if (x + size > 3 || x - size < -3) {
        dx *= -1;
    }
    glutPostRedisplay();
    glutTimerFunc(30, DoTimer, 1);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_POLYGON);
    glVertex2f(x, size);
    glVertex2f(x - size, -size);
    glVertex2f(x + size, -size);
    glEnd();
    glutSwapBuffers();
}


int main()
{
    glutInitDisplayMode(GLUT_DOUBLE);
    glutCreateWindow("OpenGL");
    glutDisplayFunc(drawScene);
    glutTimerFunc(30, DoTimer, 1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5.0, 5.0, -5.0, 5.0, -1.0, 1.0);
    glutMainLoop();
    return 0;
}