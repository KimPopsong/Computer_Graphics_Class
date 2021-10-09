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
	gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);     // clear the screen 

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			glViewport(i * 100, j * 100, 100, 100);
			double t = 0;
			int N = 5000;

			glBegin(GL_LINE_STRIP);
			glVertex2f(-1.0f, -1.0f);
			glVertex2f(-1.0f, 1.0f);
			glVertex2f(1.0f, 1.0f);
			glVertex2f(1.0f, -1.0f);
			glVertex2f(-1.0f, -1.0f);
			glEnd();

			glBegin(GL_LINE_STRIP);
			for (t = 0; t <= PI / 2; t += PI / N)
			{
				glVertex2f(-1 + 2 * cos(t), -1 + 2 * sin(t));
			}
			glEnd();

			glBegin(GL_LINE_STRIP);
			for (t = PI / 2; t <= PI; t += PI / N)
			{
				glVertex2f(1 + 2 * cos(t), -1 + 2 * sin(t));
			}
			glEnd();

			glBegin(GL_LINE_STRIP);
			for (t = PI; t <= PI / 2 * 3; t += PI / N)
			{
				glVertex2f(1 + 2 * cos(t), 1 + 2 * sin(t));
			}
			glEnd();

			glBegin(GL_LINE_STRIP);
			for (t = PI / 2 * 3; t <= 2 * PI; t += PI / N)
			{
				glVertex2f(-1 + 2 * cos(t), 1 + 2 * sin(t));
			}
			glEnd();
			glFlush();		   // send all output to display 
		}
	}
}

void main(int argc, char** argv)
{
	glutInit(&argc, argv);          // initialize the toolkit
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the display mode
	glutInitWindowSize(screenWidth, screenHeight); // set the window size
	glutInitWindowPosition(100, 150); // set the window position on screen
	glutCreateWindow("HW1_4"); // open the screen window
	glutDisplayFunc(myDisplay);     // register the redraw function
	myInit();
	glutMainLoop(); 		     // go into a perpetual loop
}