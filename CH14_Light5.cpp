#include <cstdlib>
#include <cmath>
#include <GL/glut.h>

void InitLight() 
{
    GLfloat MyLightPosition[] = { 1.0, 2.0, 3.0, 1.0 };
    GLfloat MyLightPosition1[] = { -1.0, -2.0, 3.0, 1.0 };

    glEnable(GL_LIGHTING);   //
    glEnable(GL_LIGHT0);    //
    glEnable(GL_LIGHT1);
    glEnable(GL_DEPTH_TEST);  // 음½영??효¿과? 위§해Ø (shading)

    glLightfv(GL_LIGHT0, GL_POSITION, MyLightPosition);
    glLightfv(GL_LIGHT1, GL_POSITION, MyLightPosition1);

    GLfloat MyLightAmbient[] = { 1.0, 1.0, 1.0, 1.0 }; //ambient = red
    GLfloat MyLightDiffuse[] = { 1.0, 1.0, 1.0, 1.0 }; // diffuse = yellow
    GLfloat MyLightSpecular[] = { 1.0, 1.0, 1.0, 1.0 }; // specular = white

    GLfloat MyLightAmbient1[] = { 1.0, 1.0, 1.0, 1.0 }; //ambient = red
    GLfloat MyLightDiffuse1[] = { 1.0, 1.0, 1.0, 1.0 }; // diffuse = yellow
    GLfloat MyLightSpecular1[] = { 1.0, 1.0, 1.0, 1.0 }; // specular = white

    GLfloat material_ambient[] = { 0.1, 0.1, 0.1, 1.0 };
    GLfloat material_diffuse[] = { 1, 0, 0, 1.0 };
    GLfloat material_specular[] = { 1.0, 1.0, 1.0, 1.0 };
    GLfloat material_shininess[] = { 25.0 };

    glMaterialfv(GL_FRONT, GL_DIFFUSE, material_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR, material_specular);
    glMaterialfv(GL_FRONT, GL_AMBIENT, material_ambient);
    glMaterialfv(GL_FRONT, GL_SHININESS, material_shininess);


    glLightfv(GL_LIGHT0, GL_AMBIENT, MyLightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, MyLightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, MyLightSpecular);

    glLightfv(GL_LIGHT1, GL_AMBIENT, MyLightAmbient1);
    glLightfv(GL_LIGHT1, GL_DIFFUSE, MyLightDiffuse1);
    glLightfv(GL_LIGHT1, GL_SPECULAR, MyLightSpecular1);
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