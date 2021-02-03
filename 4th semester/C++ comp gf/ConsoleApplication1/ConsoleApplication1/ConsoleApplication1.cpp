
#include "pch.h"
#include <iostream>
#include <GL/glut.h>
#include <math.h>

//задание 1
/*void init();
void draw();

void main(int argc, char **argv) //Главная функция
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Myprog");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}

void init() //Функция инициализации
{
	glClearColor(0.9, 0.9, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-8.0, 8.0, -2.0, 2.0);
}
void draw() //Функция рисования
{
	GLfloat PI = 3.14, x, y, a = 0.5, b = 1;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glViewport(10, 10, 600, 400);
	glBegin(GL_LINE_STRIP);
		for (x = -2 * PI - 2; x <= 2 * PI + 2; x += PI / 18)
		{
			y = sin(a*x);
			glVertex2f(x, y);
		}
	glEnd();
	glColor3f(0.5, 0.3, 0.8);
	glBegin(GL_LINE_STRIP);
		for (x = -2 * PI - 2; x <= 2 * PI + 2; x += PI / 18) 
		{
			y = cos(b*x);
			glVertex2f(x, y);
		}
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_LINES);
	glVertex2f(-8.0, 0.0); glVertex2f(8.0, 0.0);
	glVertex2f(0.0, 2.0); glVertex2f(0.0, -2.0);
	glEnd();
	glFlush();
}*/



void init();
void draw();

void main(int argc, char **argv) //Главная функция
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(660, 480);
	glutInitWindowPosition(50, 50);
	glutCreateWindow("Myprog");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
}

void init() //Функция инициализации
{
	glClearColor(0.9, 0.9, 0.9, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
}

void draw()
{
	GLfloat m = 60;
	GLint x = 0, y = 0;
	glClear(GL_COLOR_BUFFER_BIT);
	for (x = 0; x <= 600; x += m)
		for (y = 0; y <= 480; y += m)
		{
			glViewport(x, y, m, m);
			glColor3f(1.0, 0.0, 0.0);
			glBegin(GL_POLYGON);
			glVertex2f(-m , m);
			glColor3f(1.0, 1.0, 0.0);
			glVertex2f(-m,-m);
			glColor3f(1.0, 0.0, 0.0);
			glVertex2f(m, m);
			glColor3f(1.0, 1.0, 0.0);
			glVertex2f(m, -m);
			glEnd();
		}
	glFlush();
}