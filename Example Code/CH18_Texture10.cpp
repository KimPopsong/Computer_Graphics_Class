#include <cstdlib>
#include <iostream>
#include <fstream>
#include <GL/glut.h>

using namespace std;

static GLuint texName[2];
struct BitMapFile
{
    int sizeX;
    int sizeY;
    unsigned char* data;
};

BitMapFile* getBMPData(string filename)
{
    BitMapFile* bmp = new BitMapFile;
    unsigned int size, offset, headerSize;

    // Read input file name.
    ifstream infile(filename.c_str(), ios::binary);

    // Get the starting point of the image data.
    infile.seekg(10);
    infile.read((char*)&offset, 4);

    // Get the header size of the bitmap.
    infile.read((char*)&headerSize, 4);

    // Get width and height values in the bitmap header.
    infile.seekg(18);
    infile.read((char*)&bmp->sizeX, 4);
    infile.read((char*)&bmp->sizeY, 4);

    // Allocate buffer for the image.
    size = bmp->sizeX * bmp->sizeY * 24;
    bmp->data = new unsigned char[size];

    // Read bitmap data.
    infile.seekg(offset);
    infile.read((char*)bmp->data, size);

    // Reverse color from bgr to rgb.
    int temp;
    for (int i = 0; i < size; i += 3)
    {
        temp = bmp->data[i];
        bmp->data[i] = bmp->data[i + 2];
        bmp->data[i + 2] = temp;
    }

    return bmp;
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glShadeModel(GL_FLAT);
    glEnable(GL_DEPTH_TEST);



    glGenTextures(2, texName);
    BitMapFile* image[2];

    // Load the texture.
    image[0] = getBMPData("Textures/sky.bmp");
    image[1] = getBMPData("Textures/grass.bmp");


    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glBindTexture(GL_TEXTURE_2D, texName[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[0]->sizeX,
        image[0]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
        image[0]->data);

    glBindTexture(GL_TEXTURE_2D, texName[1]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,
        GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,
        GL_NEAREST);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image[1]->sizeX,
        image[1]->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE,
        image[1]->data);



}

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_TEXTURE_2D);


    glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
    glBindTexture(GL_TEXTURE_2D, texName[0]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-2.0, 0.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-2.0, 2.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(2.0, 2.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(2.0, 0.0, 0.0);
    glEnd();

    glBindTexture(GL_TEXTURE_2D, texName[1]);
    glBegin(GL_QUADS);
    glTexCoord2f(0.0, 0.0); glVertex3f(-2, -2.0, 0.0);
    glTexCoord2f(0.0, 1.0); glVertex3f(-2, 0.0, 0.0);
    glTexCoord2f(1.0, 1.0); glVertex3f(2, 0.0, 0.0);
    glTexCoord2f(1.0, 0.0); glVertex3f(2, -2.0, 0.0);
    glEnd();

    glFlush();
}
void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-2, 2, -2, 2, -2, 2);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void keyboard(unsigned char key, int x, int y)
{
    switch (key) {
    case 27:
        exit(0);
        break;
    default:
        break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(100, 100);
    glutCreateWindow(argv[0]);
    init();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}