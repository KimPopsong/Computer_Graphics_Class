#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0); // set the bg color to a bright white
	glColor3f(0.0f, 0.0f, 0.0f); // set the drawing color to black
	glPointSize(4.0); //set the point size to 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);// set up appropriate matrices- to be explained
	glLoadIdentity();// to be explained
	gluOrtho2D(0.0, 4.0, -1.0, 1.0);// to be explained

}
void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT); // clear the screen
	glBegin(GL_POINTS);
	
	for (double i = 0; i <= 4; i+= 0.005)
	{
		double t = exp(-i) * cos(2 * PI * i);
		glVertex2f(i, t);
	}

	glEnd();
	glFlush(); // send all output to display

}
void main(int argc, char** argv)
{
	glutInitWindowSize(400, 200); // set the window size
	glutInitWindowPosition(100, 150); // set the window position on the screen
	glutCreateWindow("HW1_1"); // open the screen window(with its exciting title)
	glutDisplayFunc(myDisplay); // register the redraw function
	myInit();
	glutMainLoop(); // go into a perpetual loop
}
