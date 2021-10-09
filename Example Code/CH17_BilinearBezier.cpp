#include <GL/glut.h> // we will use GLUT (GL UTILITY TOOLKIT)  
void Display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 0.0);
	glLoadIdentity();
	gluLookAt(3.0, 3.0, 3.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);

	int i;
	int j;
	int NUM = 30;
	double u;
	double v;

	glBegin(GL_POINTS);

	for (i = 0; i < NUM; i++)
	{
		for (j = 0; j < NUM; j++)
		{
			u = double(i) / (NUM * 1.0);
			v = double(j) / (NUM * 1.0);
			glVertex3f(u, 1 - v, 0);
		}
	}

	glEnd();
	glFlush();
}

void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION); 
	glLoadIdentity(); 
	gluPerspective(60.0, (float)w / (float)h, 1.0, 20.0);  
	glMatrixMode(GL_MODELVIEW);
} 

int main()
{
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("OpenGL Hello World!"); 
	glutDisplayFunc(Display); 
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glutReshapeFunc(resize); 
	glutMainLoop(); 
	return 0;
}