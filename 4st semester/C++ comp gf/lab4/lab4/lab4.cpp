//#include <math.h>
//#include <Gl\glut.h>
//
//GLfloat angle = 0;
//GLfloat plusangle = 0;
//GLfloat angle2 = 0;
//GLfloat plusangle2 = 0;
//int flagO = 1;
//int flagL = 1;
//
//void init(void)
//{
//	glClearColor(1.0, 1.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60, 1, 1, 10);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void myDisplay()
//{
//	glPushMatrix();
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//	gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
//
//	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 };
//	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	glPushMatrix();
//	glRotatef(angle2, 0, 1, 0);
//	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
//	glPopMatrix();
//
//	glPushMatrix();
//	glRotatef(angle, 0, 1, 0);
//
//	// грань f0
//	glBegin(GL_POLYGON);
//	glNormal3f(0.577, 0.577, 0.577);
//	glVertex3f(1, 0, 0);
//	glVertex3f(0, 1, 0);
//	glVertex3f(0, 0, 1);
//	glEnd();
//	// грань f1
//	glBegin(GL_POLYGON);
//	glNormal3f(0, 0, -1);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 1, 0);
//	glVertex3f(1, 0, 0);
//	glEnd();
//	// грань f2
//	glBegin(GL_POLYGON);
//	glNormal3f(-1, 0, 0);
//	glVertex3f(0, 0, 0);
//	glVertex3f(0, 0, 1);
//	glVertex3f(0, 1, 0);
//	glEnd();
//	// грань f3
//	glBegin(GL_POLYGON);
//	glNormal3f(0, -1, 0);
//	glVertex3f(1, 0, 0);
//	glVertex3f(0, 0, 1);
//	glVertex3f(0, 0, 0);
//	glEnd();
//
//	glPopMatrix(); 
//	glDisable(GL_LIGHTING); 
//
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
//	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
//	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
//	glEnd();
//	glRotatef(angle2, 0, 1, 0);
//	glBegin(GL_LINES);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 2, 2);
//	glVertex3f(0.0, 0.0, 0.0);
//	glEnd();
//
//
//
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void myReshape(int width, int height)
//{
//	if (width / height < 1)
//		glViewport(0, 0, width, width);
//	else
//		glViewport(0, 0, height, height);
//}
//
//void myIdle()
//{
//	angle += plusangle;
//	if (angle > 360.0)
//		angle = 0;
//	angle2 += plusangle2;
//	if (angle2 > 360.0)
//		angle2 = 0;
//	glutPostRedisplay();
//}
//
//void keys(unsigned char key, int x, int y)
//{
//	if (key == 'O' || key == 'o')
//	{
//		if (flagO == 1)
//			plusangle = 0.2;
//		else
//			plusangle = 0;
//		flagO *= -1;
//	}
//	else if (key == 'L' || key == 'l')
//	{
//		if (flagL == 1)
//			plusangle2 = 0.2;
//		else
//			plusangle2 = 0;
//		flagL *= -1;
//	}
//
//	if (key == 'F' || key == 'f')
//	{
//		glCullFace(GL_BACK);
//		glEnable(GL_CULL_FACE);
//	}
//	else if (key == 'B' || key == 'b')
//	{
//		glCullFace(GL_FRONT);
//		glEnable(GL_CULL_FACE);
//	}
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("tetrahedron");
//	glutDisplayFunc(myDisplay);
//	glutKeyboardFunc(keys);
//	glutReshapeFunc(myReshape);
//	glutIdleFunc(myIdle);
//	init();
//	glutMainLoop();
//}

//#include <math.h>
//#include <Gl\glut.h>
//
//GLfloat angle = 0;
//GLfloat plusangle = 0;
//GLfloat angle2 = 0;
//GLfloat plusangle2 = 0;
//int flagO = 1;
//int flagL = 1;
//
//void init(void)
//{
//	glClearColor(1.0, 1.0, 0.0, 0.0);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	gluPerspective(60, 1, 1, 10);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//}
//
//void myDisplay()
//{
//	glPushMatrix();
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glEnable(GL_DEPTH_TEST);
//	gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);
//
//	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 };
//
//	GLfloat myDiffuse[] = { 0.427451, 0.470588, 0.541176, 1 };
//	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
//	GLfloat myShininess[] = { 9.84615 };
//	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
//	GLfloat myAmbient[] = { 0.10588, 0.058824, 0.113725, 1 };
//	glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient);
//	GLfloat mySpecular[] = { 0.3333, 0.3333, 0.521569, 1 };
//	glMaterialfv(GL_FRONT, GL_SPECULAR, mySpecular);
//
//	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
//	glEnable(GL_LIGHTING);
//	glEnable(GL_LIGHT0);
//
//	glPushMatrix();
//	glRotatef(angle2, 0, 1, 0);
//	glBegin(GL_LINES);
//	glColor3f(1, 1, 1);
//	glVertex3f(1, 2, 2);
//	glVertex3f(0.0, 0.0, 0.0);
//	glEnd();
//	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
//	glPopMatrix();
//
//	glPushMatrix();
//	glRotatef(angle, 0, 1, 0);
//
	//glBegin(GL_POLYGON);
	//glNormal3f(0, 0.557, 0.557);
	//glVertex3f(0, 0, 1.5);
	//glVertex3f(1.5, 0, 1.5);
	//glVertex3f(0.75, 1, 0.75);
	//glEnd();

	//glBegin(GL_POLYGON);
	//glNormal3f(-0.557, 0.557, 0);
	//glVertex3f(0, 0, 0);
	//glVertex3f(0, 0, 1.5);
	//glVertex3f(0.75, 1, 0.75);
	//glEnd();

	//glBegin(GL_POLYGON);
	//glNormal3f(0, 0.557, -0.557);
	//glVertex3f(1.5, 0, 0);
	//glVertex3f(0, 0, 0);
	//glVertex3f(0.75, 1, 0.75);
	//glEnd();

	//glBegin(GL_POLYGON);
	//glNormal3f(0.557, 0.557, 0);
	//glVertex3f(1.5, 0, 1.5);
	//glVertex3f(1.5, 0, 0);
	//glVertex3f(0.75, 1, 0.75);
	//glEnd();

	//glBegin(GL_POLYGON);
	//glNormal3f(0, -1, 0);
	//glVertex3f(0, 0, 0);
	//glVertex3f(1.5, 0, 0);
	//glVertex3f(1.5, 0, 1.5);
	//glVertex3f(0, 0, 1.5);
	//glEnd();
//
//
//	glPopMatrix();
//	glDisable(GL_LIGHTING);
//
//	glBegin(GL_LINES);
//	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
//	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
//	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
//	glEnd();
//
//
//
//	glPopMatrix();
//	glutSwapBuffers();
//}
//
//void myReshape(int width, int height)
//{
//	if (width / height < 1)
//		glViewport(0, 0, width, width);
//	else
//		glViewport(0, 0, height, height);
//}
//
//void myIdle()
//{
//	angle += plusangle;
//	if (angle > 360.0)
//		angle = 0;
//	angle2 += plusangle2;
//	if (angle2 > 360.0)
//		angle2 = 0;
//	glutPostRedisplay();
//}
//
//void keys(unsigned char key, int x, int y)
//{
//	if (key == 'O' || key == 'o')
//	{
//		if (flagO == 1)
//			plusangle = 0.2;
//		else
//			plusangle = 0;
//		flagO *= -1;
//	}
//	else if (key == 'L' || key == 'l')
//	{
//		if (flagL == 1)
//			plusangle2 = 0.2;
//		else
//			plusangle2 = 0;
//		flagL *= -1;
//	}
//
//	if (key == 'F' || key == 'f')
//	{
//		glCullFace(GL_BACK);
//		glEnable(GL_CULL_FACE);
//	}
//	else if (key == 'B' || key == 'b')
//	{
//		glCullFace(GL_FRONT);
//		glEnable(GL_CULL_FACE);
//	}
//}
//
//int main(int argc, char* argv[])
//{
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
//	glutInitWindowPosition(0, 0);
//	glutCreateWindow("tetrahedron");
//	glutDisplayFunc(myDisplay);
//	glutKeyboardFunc(keys);
//	glutReshapeFunc(myReshape);
//	glutIdleFunc(myIdle);
//	init();
//	glutMainLoop();
//}

#include <math.h>
#include <Gl\glut.h>
#include <C:\Users\lazzi\Desktop\программирование\C++ comp gf\GLAUX\GLAUX.H>
#pragma comment(lib, "C:\\Users\\lazzi\\Desktop\\программирование\\C++ comp gf\\GLAUX\\GLAUX.LIB ")
#pragma comment(lib, "legacy_stdio_definitions.lib")

GLfloat angle = 0;
GLfloat plusangle = 0;
GLfloat angle2 = 0;
GLfloat plusangle2 = 0;
int flagO = 1;
int flagL = 1;

AUX_RGBImageRec* image1 = auxDIBImageLoadA("C:\\Users\\lazzi\\Desktop\\программирование\\C++ comp gf\\GLAUX\\tx1.bmp");
AUX_RGBImageRec* image2 = auxDIBImageLoadA("C:\\Users\\lazzi\\Desktop\\программирование\\C++ comp gf\\GLAUX\\tx2.bmp");
AUX_RGBImageRec* image3 = auxDIBImageLoadA("C:\\Users\\lazzi\\Desktop\\программирование\\C++ comp gf\\GLAUX\\tx3.bmp");

GLuint list = 0;

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60, 1, 1, 10);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	list = glGenLists(1);
	glNewList(list, GL_COMPILE);

	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.5, 0, 1.5);
	glVertex3f(1.5, 0, 0);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 0, 1.5);
	glEnd();

	glBegin(GL_POLYGON);
	glNormal3f(0, 0.557, -0.557);
	glVertex3f(0.75, 1, 0.75);
	glVertex3f(0, 0, 0);
	glVertex3f(1.5, 0, 0);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image1->sizeX, image1->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image1->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glBegin(GL_POLYGON);
	glNormal3f(0, 0.557, 0.557);
	glTexCoord2f(0, 0); glVertex3f(1.5, 0, 1.5);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 1.5);
	glTexCoord2f(0, 1); glVertex3f(0.75, 1, 0.75);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image2->sizeX, image2->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image2->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glBegin(GL_POLYGON);
	glNormal3f(-0.557, 0.557, 0);
	glTexCoord2f(0, 0); glVertex3f(0, 0, 1.5);
	glTexCoord2f(1, 0); glVertex3f(0, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(0.75, 1, 0.75);
	glEnd();

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image3->sizeX, image3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->data);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	glBegin(GL_POLYGON);
	glNormal3f(0.557, 0.557, 0);
	glTexCoord2f(0, 0); glVertex3f(0.75, 1, 0.75);
	glTexCoord2f(1, 0); glVertex3f(1.5, 0, 0);
	glTexCoord2f(0, 1); glVertex3f(1.5, 0, 1.5);
	glEnd();

	glEndList();
}

void myDisplay()
{
	glPushMatrix();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	gluLookAt(3, 3, 3, 0, 0, 0, 0, 1, 0);

	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 };
	GLfloat myDiffuse[] = { 0.427451, 0.470588, 0.541176, 1 };
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);
	GLfloat myShininess[] = { 9.84615 };
	glMaterialfv(GL_FRONT, GL_SHININESS, myShininess);
	GLfloat myAmbient[] = { 0.10588, 0.058824, 0.113725, 1 };
	glMaterialfv(GL_FRONT, GL_AMBIENT, myAmbient);
	GLfloat mySpecular[] = { 0.3333, 0.3333, 0.521569, 1 };
	glMaterialfv(GL_FRONT, GL_SPECULAR, mySpecular);

	glPushMatrix();
	glRotatef(angle2, 0, 1, 0);
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glBegin(GL_LINES); 
	glColor3f(1, 1, 1); 
	glVertex3f(1, 2, 2); 
	glVertex3f(0.0, 0.0, 0.0); 
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(angle, 0, 1, 0);
	glCallList(list);
	glPopMatrix();
	glDisable(GL_LIGHTING);

	glBegin(GL_LINES);
	glColor3f(1, 0, 0); glVertex3f(0, 0, 0); glVertex3f(2, 0, 0);
	glColor3f(0, 1, 0); glVertex3f(0, 0, 0); glVertex3f(0, 2, 0);
	glColor3f(0, 0, 1); glVertex3f(0, 0, 0); glVertex3f(0, 0, 2);
	glEnd();
	glPopMatrix();

	glutSwapBuffers();
}

void myReshape(int width, int height)
{
	if (width / height < 1)
		glViewport(0, 0, width, width);
	else
		glViewport(0, 0, height, height);
}

void myIdle()
{
	angle += plusangle;
	if (angle > 360.0)
		angle = 0;
	angle2 += plusangle2;
	if (angle2 > 360.0)
		angle2 = 0;
	glutPostRedisplay();
}

void keys(unsigned char key, int x, int y)
{
	if (key == 'O' || key == 'o')
	{
		if (flagO == 1)
			plusangle = 0.2;
		else
			plusangle = 0;
		flagO *= -1;
	}
	else if (key == 'L' || key == 'l')
	{
		if (flagL == 1)
			plusangle2 = 0.2;
		else
			plusangle2 = 0;
		flagL *= -1;
	}

	if (key == 'F' || key == 'f')
	{
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}
	else if (key == 'B' || key == 'b')
	{
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
	}
}

void mouseButton(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON) glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	else if (button == GLUT_RIGHT_BUTTON) glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("lab5");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keys);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	glutMouseFunc(mouseButton);
	init();
	glutMainLoop();
}








