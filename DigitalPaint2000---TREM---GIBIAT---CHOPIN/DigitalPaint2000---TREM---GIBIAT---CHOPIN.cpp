// DigitalPaint2000---TREM---GIBIAT---CHOPIN.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//


#include<windows.h>
#include<glut.h>
#include<stdlib.h>
#include<stdio.h>
bool writeFlag = false;
float posX, posY;


void initGL()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}


void idle()
{
	glutPostRedisplay();
}


void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0f, 0.0f, 1.0f);


	glBegin(GL_LINE_STRIP);
	while (writeFlag)
	{
		glVertex2f(posX, posY);
	}
	glEnd();

	glutSwapBuffers();
}


void reshape(GLsizei width, GLsizei height)
{

	if (height == 0) height = 1;                // To prevent divide by 0
	GLfloat aspect = (GLfloat)width / (GLfloat)height;


	glViewport(0, 0, width, height);


	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if (width >= height)
	{

		gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
	}
	else
	{

		gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '1':
		writeFlag = true;
		break;
	case '2':
		writeFlag = false;
		break;
	case 27:
		exit(0);
		break;
	}
}
void Motion(int x, int y)
{

	posX = x;
	posY = y;
}


int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("Simple Paint program by GLUT");
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutMotionFunc(Motion);  // mouse click and move
	glutIdleFunc(idle);
	initGL();
	glutMainLoop();
	return 0;
}