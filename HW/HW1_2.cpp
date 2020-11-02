#include <GL/glut.h>
void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);      // set the bg color to a bright white
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained 
	glLoadIdentity();// to be explained
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);// to be explained
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	glShadeModel(GL_FLAT);
	glBegin(GL_TRIANGLE_STRIP);

	glVertex2f(-0.45, 0.3);
	glVertex2f(-0.45, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.25, 0.3);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.05, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(-0.25, -0.5);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-0.05, -0.3);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.25, -0.5);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.05, -0.3);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.25, 0.3);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.05, 0.5);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(0.45, 0.3);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(0.45, 0.5);

	glEnd();
	glFlush();		                 // send all output to display 
}

void main(int argc, char** argv)
{
	glutInitWindowSize(400, 400);     // set the window size
	glutInitWindowPosition(200, 200); // set the window position on the screen
	glutCreateWindow("HW1_2"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}
