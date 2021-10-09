#include <GL/glut.h>

static GLfloat currentAngleOfRotation = 0.0;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(currentAngleOfRotation, 0.0, 0.0, 1.0);
    glRectf(-10.0, -10.0, 10.0, 10.0);
    glFlush();
}
void MyMouseClick(GLint Button, GLint State, GLint X, GLint Y) {
    if ((Button == GLUT_LEFT_BUTTON) && (State == GLUT_DOWN))
    {
        currentAngleOfRotation++;
        glutPostRedisplay();
    }
    if ((Button == GLUT_RIGHT_BUTTON) && (State == GLUT_DOWN))
    {
        currentAngleOfRotation--;
        glutPostRedisplay();
    }

}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 500);
    glutCreateWindow("Spinning Square");
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50, 50, -50, 50, -1, 1);
    glutDisplayFunc(display);
    glutMouseFunc(MyMouseClick);
    glutMainLoop();
}