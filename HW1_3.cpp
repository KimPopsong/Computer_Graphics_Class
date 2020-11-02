#include <windows.h> // use proper includes for your system
#include <math.h>
#include <gl/Gl.h>
#include <gl/Glu.h>
#include <gl/Glut.h>
const int screenWidth = 400;	   // width of the screen window in pixels 
const int screenHeight = 400;	   // height of the screen window in pixels
#define PI 3.141592
#define TWOPI 2*3.141592

void myInit(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);       // the background color is white
	glColor3f(0.0f, 0.0f, 0.0f);         // the drawing color is black 
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 100.0, 0.0, 100.0);
}

void drdisc(double rad, double x, double y)
{
	double t = 0;
	int N = 5000;

	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 2 * PI; t += PI / N)
	{
		glVertex2f(x + rad *cos(t), y + rad * sin(t));
	}
	glEnd();
}

void drellipse(double x, double y, double a, double b)
{
	double t = 0;
	int N = 5000;

	glBegin(GL_TRIANGLE_FAN);
	for (t = 0; t <= 2 * PI; t += PI / N)
	{
		glVertex2f(x + a * cos(t), y + b * sin(t));
	}
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 
	/* HW1_3
	glColor3f(1.0, 0.0, 0.0);
	drdisc(20.0, 25.0, 75.0);

	glColor3f(1.0, 1.0, 1.0);
	drdisc(10.0, 25.0, 75.0);
	*/

	// HW1_3 Discussion
	glColor3f(0.0, 0.0, 0.0);
	drellipse(25.0, 75.0, 10.0, 5.0);
	glColor3f(1.0, 1.0, 1.0);
	drdisc(50.0, 25.0, 75.0);
	glColor3f(0.0, 0.0, 0.0);
	drellipse(25.0, 75.0, 50.0, 2.5);
	glColor3f(1.0, 1.0, 1.0);
	drdisc(2.5, 25.0, 75.0);
	glFlush();		   // send all output to display 
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(screenWidth, screenHeight); // set the window size
	glutInitWindowPosition(100, 150); // set the window position on screen
	glutCreateWindow("HW1_3"); // open the screen window
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}