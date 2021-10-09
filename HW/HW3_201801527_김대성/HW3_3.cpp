#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <GL/glut.h>

using namespace std;

vector<double> vertexX;
vector<double> vertexY;
vector<double> vertexZ;
vector<vector<double>> face;
int vertexNumber, faceNumber;

vector<string> SplitVertex(string origin)
{
	string temp1, temp2, temp3, t;
	vector<string> temp;
	int i;
	
	for (i = 0; origin[i] != ' '; i++)
	{
		t = origin[i];
		temp1 += t;
	}

	i += 1;
	for (; origin[i] != ' '; i++)
	{
		t = origin[i];
		temp2 += t;
	}

	i += 1;
	for (; i < origin.length(); i++)
	{
		t = origin[i];
		temp3 += t;
	}
	
	temp.push_back(temp1);
	temp.push_back(temp2);
	temp.push_back(temp3);

	return temp;
}

vector<double> SplitFace(string origin)
{
	string temp1, temp2, temp3, t;
	vector<double> temp;
	int i;

	for (i = 0; origin[i] != ' '; i++)
	{
	}

	i += 1;
	for (; origin[i] != ' '; i++)
	{
		t = origin[i];
		temp1 += t;
	}

	i += 1;
	for (; origin[i] != ' '; i++)
	{
		t = origin[i];
		temp2 += t;
	}

	i += 1;
	for (; i < origin.length(); i++)
	{
		t = origin[i];
		temp3 += t;
	}

	temp.push_back(stod(temp1));
	temp.push_back(stod(temp2));
	temp.push_back(stod(temp3));

	return temp;
}

void DRAW()
{
	gluLookAt(20.0, 20.0, 20.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);

	for (int i = 0; i < faceNumber; i++)
	{
		glBegin(GL_POLYGON);

		if (i % 2 == 0)
			glColor3f(1.0, 0.0, 0.0);

		else
			glColor3f(0.0, 1.0, 0.0);

		for (int j = 0; j < 3; j++)
		{
			glVertex3f(vertexX[face[i][j]], vertexY[face[i][j]], vertexZ[face[i][j]]);
			//cout << vertexX[face[i][j]] << ' ' << vertexY[face[i][j]] << ' ' << vertexZ[face[i][j]] << endl;
		}		

		glEnd();
		glFlush();
	}
}

int main(int argc, char** argv)
{
	ifstream block;
	block.open("block.off");

	string tempString;
	vector<string> tempVector;

	getline(block, tempString);
	getline(block, tempString);

	tempVector = SplitVertex(tempString);

	tempString = tempVector[0];
	vertexNumber = stoi(tempString);

	tempString = tempVector[1];
	faceNumber = stoi(tempString);

	for (int i = 0; i < vertexNumber; i++)
	{
		getline(block, tempString);
		tempVector = SplitVertex(tempString);

		vertexX.push_back(stod(tempVector[0]));
		vertexY.push_back(stod(tempVector[1]));
		vertexZ.push_back(stod(tempVector[2]));
	}

	for (int i = 0; i < faceNumber; i++)
	{
		getline(block, tempString);
		face.push_back(SplitFace(tempString));
	}
	block.close();

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("HW3_201801527");
	glutDisplayFunc(DRAW);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-10.0, 10.0, -10.0, 10.0, 5.0, 100.0);
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glutMainLoop();
	
	return 0;
}