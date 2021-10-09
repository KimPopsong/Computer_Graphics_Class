#include <GL/glut.h>

static float t = 0.0;  //Time parameter.
static float h = 0.5;  //Horizontal component of initial velocity.
static float v = 4.0;  //Vertical component of initial velocity.
static float g = 0.2;   //Gravitational accelaration.

void DoTimer(int value)
{
    t += 1;
    glutPostRedisplay();
    glutTimerFunc(30, DoTimer, 1);
}

void init(void)
{
    GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat mat_diffuse[] = { 1.0, 0.0, 0.0, 1.0 };
    GLfloat mat_shininess[] = { 50.0 };

    GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat light_position[] = { 1.0, 1.0, 1.0, 0.0 };

    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_SMOOTH);
    glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);

    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_AMBIENT_AND_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
}

void drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(-15.0, -15.0, -25.0);
    glTranslatef(h * t, v * t - (g / 2.0) * t * t, 0.0);
    glColor3f(0.0, 0.0, 1.0);
    glutSolidSphere(3.0, 10, 10);
    glutSwapBuffers();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-5.0, 5.0, -5.0, 5.0, 5.0, 100.0);
}

int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutCreateWindow("aaa");
    init();
    glutDisplayFunc(drawScene);
    glutReshapeFunc(resize);
    glutTimerFunc(30, DoTimer, 1);
    glutMainLoop();

    return 0;
}