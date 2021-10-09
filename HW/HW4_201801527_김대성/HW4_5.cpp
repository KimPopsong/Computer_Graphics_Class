#include <GL/glut.h>

int t = 0;
static GLfloat yPos = 0;
static GLfloat xPos = 0;
static GLfloat dy = 1;
static GLfloat dx = 1;

void InitLight()
{
    GLfloat MyLightPosition[] = { 1.0, 2.0, 3.0, 1.0 };
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_POSITION, MyLightPosition);

    GLfloat MyLightAmbient[] = { 0.0, 0.0, 0.0, 1.0 }; //ambient = red
    GLfloat MyLightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // diffuse = yellow
    GLfloat MyLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 }; // specular = white

    glLightfv(GL_LIGHT0, GL_AMBIENT, MyLightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, MyLightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, MyLightSpecular);

    GLfloat material_ambient[] = { 0.1, 0.1, 0.1, 1.0 };  // ambient (almost black)
    GLfloat material_diffuse[] = { 1, 0, 0, 1.0 };    // diffuse: red
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 }; // specular: white
    GLfloat material_shininess[] = { 25.0 };   // shininess:25

    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);
}

void resize(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-40.0, 40.0, -40.0, 40.0, 70.0, 100.0);
}

void Move()
{
    t += 1;
    yPos -= dy;
    xPos -= dx;

    if (t % 3 == 0)
    {
        dy += 1;
        dx += 1;
    }

    glutPostRedisplay();
}

void animate(int someValue)
{
    Move();
    glutTimerFunc(50, animate, 1);
}

void Draw()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    //glEnable(GL_NORMALIZE);
    glLoadIdentity();

    glPushMatrix();
    glBegin(GL_POLYGON);
    glNormal3f(0, 1, 1);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(10, 30, -90);
    glVertex3f(40, 30, -90);
    glVertex3f(-10, -20.0, -90);
    glVertex3f(-40, -20.0, -90);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(xPos, yPos, 0);
    glTranslatef(15, 30, -80);
    glutSolidSphere(7, 40, 40);
    glPopMatrix();

    glutSwapBuffers();
}

int main()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(700, 700);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("HW4_201801527");

    InitLight();
    glutDisplayFunc(Draw);
    glutReshapeFunc(resize);
    glutTimerFunc(30, animate, 1);
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glutMainLoop();

    return 0;
}