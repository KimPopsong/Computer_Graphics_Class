#include <cmath>
# include <GL/glut.h>
#define PI 3.14159265358979324
static float R = 40.0; // Radius of circle.
static float X = 50.0; // X-coordinate of center of circle.
static float Y = 50.0; // Y-coordinate of center of circle.
static int numVertices = 5; // Number of vertices on circle.
void drawScene(void)
{
    float t = 0; // Angle parameter.
    int i;
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);
    glBegin(GL_LINE_LOOP);
    for (i = 0; i < numVertices; ++i)
    {
        t = 2 * PI * i / numVertices;
        glVertex3f(cos(t), sin(t), 0.0);
    }
    glEnd();
    glFlush();
}
void keyInput(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 27:
        exit(0);
        break;
    case '+':
        numVertices++;
        glutPostRedisplay();
        break;
    case '-':
        if (numVertices > 3) numVertices--;
        glutPostRedisplay();
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("circle.cpp");
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutDisplayFunc(drawScene);
    glutKeyboardFunc(keyInput);
    glutMainLoop();

    return 0;
}