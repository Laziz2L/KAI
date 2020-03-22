/*#include "pch.h"
#include <Gl/glut.h>
#include <math.h>
GLfloat angle = 0;
GLfloat k = 1;

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-15, 15, -15, 15);
	//glClearColor(1.0, 1.0, 1.0, 0.0);
	//glClear(GL_COLOR_BUFFER_BIT);

}
void figure1(void)
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_QUADS);	// движущийся зеленый квадрат
	glVertex2f(1, 1);
	glVertex2f(-1, 1);
	glVertex2f(-1, -1);
	glVertex2f(1, -1);
	glEnd();
}

void figure2(void)
{
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_QUADS);	//неподвижный красный квадрат
	glVertex2f(6, 6);
	glVertex2f(4, 6);
	glVertex2f(4, 4);
	glVertex2f(6, 4);
	glEnd();
}

void axis(void) // рисование осей
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0, -12);
	glVertex2f(0, 12);
	glVertex2f(-12, 0);
	glVertex2f(12, 0);
	glEnd();
}

void display(void)	//функция рисования и обновления окна
{
	glMatrixMode(GL_MODELVIEW);//matrix
	glLoadIdentity();//matrix1
	glClearColor(1.0, 1.0, 1.0, 0.0);//color
	//glClear(GL_COLOR_BUFFER_BIT);//coloring the background
	axis();
	glTranslatef(5, 5, 0);
	glRotatef(angle, 0, 0, 1);
	glTranslatef(-5, -5, 0);
	figure2();
	glLoadIdentity();
	glTranslatef(5, 5, 0);
	glRotatef(-angle, 0, 0, 1);
	glTranslatef(-5, -5, 0);
	glScalef(k, k, 0);
	figure1();
	glFlush();
}

void timer(int value)
{
	k -= 0.1;
	if (k < 0.1) k = 1;
	angle += 5;
	if (angle >= 360)
	{
		k = 1;
		angle = 0;
		glClearColor(1.0, 1.0, 1.0, 0.0);
		glClear(GL_COLOR_BUFFER_BIT);
	}
	glutPostRedisplay();
	glutTimerFunc(100, timer, 0);
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Преобразования модели");
	glutDisplayFunc(display);
	glutTimerFunc(500, timer, 0);
	init();
	glutMainLoop();
}
*/




/*#include "pch.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#define PI 3.1459
GLfloat R = 640.0 / 480; //Форматное соотношение
GLfloat w = 40; //Ширина мирового окна
GLfloat h; //Высота мирового окна
GLfloat l, r, b, t; //Параметры мирового окна
GLfloat f = 30.0;
void init(void)
{ //Расчет параметров мирового окна
	h = w / R; l = -w / 2; r = w / 2; b = -h / 2; t = h / 2;
	glClearColor(1.0, 1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(l, r, b, t);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void reshape(GLsizei W, GLsizei H)
{
	if (R > W / H) glViewport(0, 0, W, W / R);
	else glViewport(0, 0, H*R, H);
}
void showAxis(void)
{
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, t);
	glVertex2f(0, 0);
	glVertex2f(r, 0);
	glEnd();
}
void fig0(void)
{
	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 3.0);
	glVertex2f(5.0, 2.0);
	glVertex2f(5.0, 0.0);
	glEnd();
}
void scene(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	showAxis();
	fig0();
	glPushMatrix();
	glTranslatef(4.5, 8.0, 0.0);
	glRotatef(f, 0.0, 0.0, 1.0);
	glScalef(1.0, -1.0, 1.0);
	fig0();
	glPopMatrix( );
	glFlush();
	glutSwapBuffers();
	f+=30; if(f==360) f=0;
	Sleep(200);
}
void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	//glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(640, 480);
	glutInitWindowPosition(20, 20);
	glutCreateWindow("Myprog");
	glutReshapeFunc(reshape);
	glutDisplayFunc(scene);
	glutIdleFunc(scene);
	init();
	glutMainLoop();
}*/

#include "pch.h"
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>
#include <windows.h>

void init(void)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-15, 15, -15, 15);

	glClearColor(1.0, 1.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
}
void figure1(void) // треугольники
{
	glColor3f(0.0, 0.0, 1.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(0, 5);
	glVertex2f(-2.5, 0);
	glVertex2f(2.5, 0);
	glEnd();
}
void figure2(void) // квадрат
{
	glColor3f(1.0, 1.0, 0.0);
	glBegin(GL_QUADS); 
	glVertex2f(5, 5);
	glVertex2f(-5, 5);
	glVertex2f(-5, -5);
	glVertex2f(5, -5);
	glEnd();
}
void axis2(void) // оси треугольников
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0, 0);
	glVertex2f(0, 6);
	glVertex2f(-3.5, 0);
	glVertex2f(0, 0);
	glEnd();
}
void axis(void) // оси квадрата
{
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	glVertex2f(0, -12);
	glVertex2f(0, 12);
	glVertex2f(-12, 0);
	glVertex2f(12, 0);
	glEnd();
}
void display(void) //функция рисования и обновления окна
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	figure2();
	axis();

	glTranslatef(0, 5, 0);
	figure1();
	axis2();
	glLoadIdentity();

	glTranslatef(-5, 0, 0);
	glRotatef(90, 0, 0, 1);
	figure1();
	axis2();
	glLoadIdentity();

	glTranslatef(0, -5, 0);
	glRotatef(180, 0, 0, 1);
	figure1();
	axis2();
	glLoadIdentity();

	glTranslatef(5, 0, 0);
	glRotatef(270, 0, 0, 1);
	axis2();
	figure1();
	glFlush();
}
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("n3");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
}