#include <math.h>
#include <Gl\glut.h>
#include <C:\Users\lazzi\Desktop\программирование\C++ comp gf\GLAUX\GLAUX.H>
#pragma comment(lib, "C:\\Users\\lazzi\\Desktop\\программирование\\C++ comp gf\\GLAUX\\GLAUX.LIB ")
#pragma comment(lib, "legacy_stdio_definitions.lib")

GLfloat scale = 1;
GLfloat angle = 0;
GLfloat plusangle = 0;
GLfloat angle2 = 0;
GLfloat plusangle2 = 0;
int flagO = 1;
int flagL = 1;

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
	list = glGenLists(1);		//задаем список объектов, там будет ромб со своей текстурой
	glNewList(list, GL_COMPILE);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, image3->sizeX, image3->sizeY, 0, GL_RGB, GL_UNSIGNED_BYTE, image3->data); //включаем текстуру
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);

	//Ромб
		//передняя грань
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glTexCoord2f(0, 0); glVertex3f(1.02, 0.34, 0.05);
	glTexCoord2f(0, 1); glVertex3f(1.22, 0, 0.05);
	glTexCoord2f(1, 0); glVertex3f(1.42, 0.34, 0.05);
	glTexCoord2f(1, 1); glVertex3f(1.22, 0.68, 0.05);
	glEnd();
	//задняя грань
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glTexCoord2f(0, 0); glVertex3f(1.02, 0.34, 0);
	glTexCoord2f(0, 1); glVertex3f(1.22, 0.68, 0);
	glTexCoord2f(1, 0); glVertex3f(1.42, 0.34, 0);
	glTexCoord2f(1, 1); glVertex3f(1.22, 0, 0);
	glEnd();
	//нижняя левая
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glTexCoord2f(0, 0); glVertex3f(1.02, 0.34, 0);
	glTexCoord2f(0, 1); glVertex3f(1.22, 0, 0);
	glTexCoord2f(1, 0); glVertex3f(1.22, 0, 0.05);
	glTexCoord2f(1, 1); glVertex3f(1.02, 0.34, 0.05);
	glEnd();
	//нижняя правая
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glTexCoord2f(0, 0); glVertex3f(1.42, 0.34, 0.05);
	glTexCoord2f(0, 1); glVertex3f(1.22, 0, 0.05);
	glTexCoord2f(1, 0); glVertex3f(1.22, 0, 0);
	glTexCoord2f(1, 1); glVertex3f(1.42, 0.34, 0);
	glEnd();
	//верхняя правая
	glBegin(GL_POLYGON);
	glNormal3f(0.5, 0.5, 0);
	glTexCoord2f(0, 0); glVertex3f(1.22, 0.68, 0.05);
	glTexCoord2f(0, 1); glVertex3f(1.42, 0.34, 0.05);
	glTexCoord2f(1, 0); glVertex3f(1.42, 0.34, 0);
	glTexCoord2f(1, 1); glVertex3f(1.22, 0.68, 0);
	glEnd();
	//верхняя левая
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, 0.5, 0);
	glTexCoord2f(0, 0); glVertex3f(1.22, 0.68, 0);
	glTexCoord2f(0, 1); glVertex3f(1.02, 0.34, 0);
	glTexCoord2f(1, 0); glVertex3f(1.02, 0.34, 0.05);
	glTexCoord2f(1, 1); glVertex3f(1.22, 0.68, 0.05);
	glEnd();

	glDisable(GL_TEXTURE_2D);
	glEndList();
}

void myDisplay()
{
	glPushMatrix(); //Сохраняем VM = 1
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //очистка буферов цвета и глубины
	glEnable(GL_DEPTH_TEST); //проверка глубины
	gluLookAt(scale*3, scale*3, scale*3, 0, 0, 0, 0, 1, 0); //позиция наблюдателя

	GLfloat myLightPosition[] = { 1.0, 2.0, 2.0, 1.0 }; // Источник света в CKw
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glEnable(GL_LIGHTING); //Включение расчета освещенности
	glEnable(GL_LIGHT0); //Включаем этот конкретный источник

	glPushMatrix(); //Сохраняем VM=Fwe
	glRotatef(angle2, 0, 1, 0); //Вращаем источник света
	glBegin(GL_LINES); //Создаем линию источника света
	glColor3f(1, 1, 1);
	glVertex3f(1, 2, 2);
	glVertex3f(0.0, 0.0, 0.0);
	glEnd();
	glLightfv(GL_LIGHT0, GL_POSITION, myLightPosition);
	glPopMatrix();

	glPushMatrix();
	glRotatef(angle, 0, 1, 0); //Вращаем объект

	GLfloat mmyDiffuse[] = { 0, 0, 1, 1 }; // задаем цвет крыльев
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mmyDiffuse);

	glCallList(list); //ромб
	//левое крыло
		//нижняя полоса
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.59, 0.11, 0.1);
	glVertex3f(0.66, 0.05, 0.1);
	glVertex3f(1.05, 0.05, 0.1);
	glVertex3f(1.12, 0.11, 0.1);
	glEnd();
	//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.59, 0.11, 0);
	glVertex3f(1.12, 0.11, 0);
	glVertex3f(1.05, 0.05, 0);
	glVertex3f(0.66, 0.05, 0);
	glEnd();
	//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(0.59, 0.11, 0);
	glVertex3f(0.66, 0.05, 0);
	glVertex3f(0.66, 0.05, 0.1);
	glVertex3f(0.59, 0.11, 0.1);
	glEnd();
	//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.66, 0.05, 0);
	glVertex3f(1.05, 0.05, 0);
	glVertex3f(1.05, 0.05, 0.1);
	glVertex3f(0.66, 0.05, 0.1);
	glEnd();
	//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(1.12, 0.11, 0.1);
	glVertex3f(1.05, 0.05, 0.1);
	glVertex3f(1.05, 0.05, 0);
	glVertex3f(1.12, 0.11, 0);
	glEnd();
	//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.59, 0.11, 0.1);
	glVertex3f(1.12, 0.11, 0.1);
	glVertex3f(1.12, 0.11, 0);
	glVertex3f(0.59, 0.11, 0);
	glEnd();
	//вторая снизу полоса
		//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.39, 0.225, 0.1);
	glVertex3f(0.47, 0.13, 0.1);
	glVertex3f(0.77, 0.13, 0.1);
	glVertex3f(0.67, 0.225, 0.1);
	glEnd();
	//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.39, 0.225, 0);
	glVertex3f(0.67, 0.225, 0);
	glVertex3f(0.77, 0.13, 0);
	glVertex3f(0.47, 0.13, 0);
	glEnd();
	//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(0.39, 0.225, 0);
	glVertex3f(0.67, 0.225, 0);
	glVertex3f(0.47, 0.13, 0.1);
	glVertex3f(0.39, 0.225, 0.1);
	glEnd();
	//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.47, 0.13, 0);
	glVertex3f(0.77, 0.13, 0);
	glVertex3f(0.77, 0.13, 0.1);
	glVertex3f(0.47, 0.13, 0.1);
	glEnd();
	//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, 0.5, 0);
	glVertex3f(0.67, 0.225, 0.1);
	glVertex3f(0.77, 0.13, 0.1);
	glVertex3f(0.77, 0.13, 0);
	glVertex3f(0.67, 0.225, 0);
	glEnd();
	//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.39, 0.225, 0.1);
	glVertex3f(0.67, 0.225, 0.1);
	glVertex3f(0.67, 0.225, 0);
	glVertex3f(0.39, 0.225, 0);
	glEnd();
	//третья снизу полоса
		//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.07, 0.34, 0.1);
	glVertex3f(0.15, 0.25, 0.1);
	glVertex3f(0.66, 0.25, 0.1);
	glVertex3f(0.66, 0.34, 0.1);
	glEnd();
	//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.66, 0.34, 0);
	glVertex3f(0.66, 0.25, 0);
	glVertex3f(0.15, 0.25, 0);
	glVertex3f(0.07, 0.34, 0);
	glEnd();
	//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(0.07, 0.34, 0);
	glVertex3f(0.15, 0.25, 0);
	glVertex3f(0.15, 0.25, 0.1);
	glVertex3f(0.07, 0.34, 0.1);
	glEnd();
	//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.15, 0.25, 0);
	glVertex3f(0.66, 0.25, 0);
	glVertex3f(0.66, 0.25, 0.1);
	glVertex3f(0.15, 0.25, 0.1);
	glEnd();
	//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(0.66, 0.34, 0.1);
	glVertex3f(0.66, 0.25, 0.1);
	glVertex3f(0.66, 0.25, 0);
	glVertex3f(0.66, 0.34, 0);
	glEnd();
	//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.66, 0.34, 0);
	glVertex3f(0.07, 0.34, 0);
	glVertex3f(0.07, 0.34, 0.1);
	glVertex3f(0.66, 0.34, 0.1);
	glEnd();
	//верхняя полоса
		//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0, 0.45, 0.1);
	glVertex3f(0.06, 0.36, 0.1);
	glVertex3f(0.67, 0.36, 0.1);
	glVertex3f(0.77, 0.45, 0.1);
	glEnd();
	//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0, 0.45, 0);
	glVertex3f(0.77, 0.45, 0);
	glVertex3f(0.67, 0.36, 0);
	glVertex3f(0.06, 0.36, 0);
	glEnd();
	//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(0, 0.45, 0);
	glVertex3f(0.06, 0.36, 0);
	glVertex3f(0.06, 0.36, 0.1);
	glVertex3f(0, 0.45, 0.1);
	glEnd();
	//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.06, 0.36, 0);
	glVertex3f(0.67, 0.36, 0);
	glVertex3f(0.67, 0.36, 0.1);
	glVertex3f(0.06, 0.36, 0.1);
	glEnd();
	//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(0.77, 0.45, 0.1);
	glVertex3f(0.67, 0.36, 0.1);
	glVertex3f(0.67, 0.36, 0);
	glVertex3f(0.77, 0.45, 0);
	glEnd();
	//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.77, 0.45, 0);
	glVertex3f(0, 0.45, 0);
	glVertex3f(0, 0.45, 0.1);
	glVertex3f(0.77, 0.45, 0.1);
	glEnd();

	//правое крыло
		//нижняя полоса
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.32, 0.11, 0.1);
	glVertex3f(1.37, 0.05, 0.1);
	glVertex3f(1.78, 0.05, 0.1);
	glVertex3f(1.85, 0.11, 0.1);
	glEnd();
	//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.32, 0.11, 0);
	glVertex3f(1.85, 0.11, 0);
	glVertex3f(1.78, 0.05, 0);
	glVertex3f(1.37, 0.05, 0);
	glEnd();
	//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(1.32, 0.11, 0);
	glVertex3f(1.37, 0.05, 0);
	glVertex3f(1.37, 0.05, 0.1);
	glVertex3f(1.32, 0.11, 0.1);
	glEnd();
	//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.37, 0.05, 0);
	glVertex3f(1.78, 0.05, 0);
	glVertex3f(1.78, 0.05, 0.1);
	glVertex3f(1.37, 0.05, 0.1);
	glEnd();
	//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(1.85, 0.11, 0.1);
	glVertex3f(1.78, 0.05, 0.1);
	glVertex3f(1.78, 0.05, 0);
	glVertex3f(1.85, 0.11, 0);
	glEnd();
	//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.85, 0.11, 0);
	glVertex3f(1.32, 0.11, 0);
	glVertex3f(1.32, 0.11, 0.1);
	glVertex3f(1.85, 0.11, 0.1);
	glEnd();
	//вторая снизу полоса
		//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.77, 0.225, 0.1);
	glVertex3f(1.67, 0.13, 0.1);
	glVertex3f(1.97, 0.13, 0.1);
	glVertex3f(2.05, 0.225, 0.1);
	glEnd();
	//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.77, 0.225, 0);
	glVertex3f(2.05, 0.225, 0);
	glVertex3f(1.97, 0.13, 0);
	glVertex3f(1.67, 0.13, 0);
	glEnd();
	//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, 0.5, 0);
	glVertex3f(1.77, 0.225, 0);
	glVertex3f(1.67, 0.13, 0);
	glVertex3f(1.67, 0.13, 0.1);
	glVertex3f(1.77, 0.225, 0.1);
	glEnd();
	//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.67, 0.13, 0);
	glVertex3f(1.97, 0.13, 0);
	glVertex3f(1.97, 0.13, 0.1);
	glVertex3f(1.67, 0.13, 0.1);
	glEnd();
	//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(2.05, 0.225, 0.1);
	glVertex3f(1.97, 0.13, 0.1);
	glVertex3f(1.97, 0.13, 0);
	glVertex3f(2.05, 0.225, 0);
	glEnd();
	//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(2.05, 0.225, 0);
	glVertex3f(1.77, 0.225, 0);
	glVertex3f(1.77, 0.225, 0.1);
	glVertex3f(2.05, 0.225, 0.1);
	glEnd();
	//третья снизу полоса
		//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.78, 0.34, 0.1);
	glVertex3f(1.78, 0.25, 0.1);
	glVertex3f(2.29, 0.25, 0.1);
	glVertex3f(2.37, 0.34, 0.1);
	glEnd();
	//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.78, 0.34, 0);
	glVertex3f(2.37, 0.34, 0);
	glVertex3f(2.29, 0.25, 0);
	glVertex3f(1.78, 0.25, 0);
	glEnd();
	//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1.78, 0.34, 0);
	glVertex3f(1.78, 0.25, 0);
	glVertex3f(1.78, 0.25, 0.1);
	glVertex3f(1.78, 0.34, 0.1);
	glEnd();
	//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.78, 0.25, 0);
	glVertex3f(2.29, 0.25, 0);
	glVertex3f(2.29, 0.25, 0.1);
	glVertex3f(1.78, 0.25, 0.1);
	glEnd();
	//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(2.37, 0.34, 0.1);
	glVertex3f(2.29, 0.25, 0.1);
	glVertex3f(2.29, 0.25, 0);
	glVertex3f(2.37, 0.34, 0);
	glEnd();
	//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(2.37, 0.34, 0);
	glVertex3f(1.78, 0.34, 0);
	glVertex3f(1.78, 0.34, 0.1);
	glVertex3f(2.37, 0.34, 0.1);
	glEnd();
	//верхняя полоса
		//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.67, 0.45, 0.1);
	glVertex3f(1.77, 0.36, 0.1);
	glVertex3f(2.38, 0.36, 0.1);
	glVertex3f(2.44, 0.45, 0.1);
	glEnd();
	//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.67, 0.45, 0);
	glVertex3f(2.44, 0.45, 0);
	glVertex3f(2.38, 0.36, 0);
	glVertex3f(1.77, 0.36, 0);
	glEnd();
	//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(1.67, 0.45, 0);
	glVertex3f(1.77, 0.36, 0);
	glVertex3f(1.77, 0.36, 0.1);
	glVertex3f(1.67, 0.45, 0.1);
	glEnd();
	//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.77, 0.36, 0);
	glVertex3f(2.38, 0.36, 0);
	glVertex3f(2.38, 0.36, 0.1);
	glVertex3f(1.77, 0.36, 0.1);
	glEnd();
	//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(2.44, 0.45, 0.1);
	glVertex3f(2.38, 0.36, 0.1);
	glVertex3f(2.38, 0.36, 0);
	glVertex3f(2.44, 0.45, 0);
	glEnd();
	//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(2.44, 0.45, 0);
	glVertex3f(1.67, 0.45, 0);
	glVertex3f(1.67, 0.45, 0.1);
	glVertex3f(2.44, 0.45, 0.1);
	glEnd();

	GLfloat myDiffuse[] = { 1, 0, 0, 1 }; // задаем цвет букв
	glMaterialfv(GL_FRONT, GL_DIFFUSE, myDiffuse);

	//буква К 
	//			|/
	//			|\
	//разделим на 3 части - правый вертикальный прямоугольник, левый верхний (/), левый нижний (\) 
		//правая часть
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.77, 0.41, 0.1);
	glVertex3f(0.77, 0.17, 0.1);
	glVertex3f(0.84, 0.17, 0.1);
	glVertex3f(0.84, 0.41, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.77, 0.41, 0.05);
	glVertex3f(0.84, 0.41, 0.05);
	glVertex3f(0.84, 0.17, 0.05);
	glVertex3f(0.77, 0.17, 0.05);
	glEnd();
			//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(0.77, 0.41, 0.05);
	glVertex3f(0.77, 0.17, 0.05);
	glVertex3f(0.77, 0.17, 0.1);
	glVertex3f(0.77, 0.41, 0.1);
	glEnd();
			//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(0.77, 0.17, 0.05);
	glVertex3f(0.84, 0.17, 0.05);
	glVertex3f(0.84, 0.17, 0.1);
	glVertex3f(0.77, 0.17, 0.1);
	glEnd();
			//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(0.84, 0.41, 0.1);
	glVertex3f(0.84, 0.17, 0.1);
	glVertex3f(0.84, 0.17, 0.05);
	glVertex3f(0.84, 0.41, 0.05);
	glEnd();
			//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(0.77, 0.41, 0.1);
	glVertex3f(0.84, 0.41, 0.1);
	glVertex3f(0.84, 0.41, 0.05);
	glVertex3f(0.77, 0.41, 0.05);
	glEnd();
		//левая верхняя часть (/)
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.92, 0.41, 0.1);
	glVertex3f(0.84, 0.29, 0.1);
	glVertex3f(0.92, 0.29, 0.1);
	glVertex3f(1.00, 0.41, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.92, 0.41, 0.05);
	glVertex3f(1.00, 0.41, 0.05);
	glVertex3f(0.92, 0.29, 0.05);
	glVertex3f(0.84, 0.29, 0.05);
	glEnd();
			//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, 0.5, 0);
	glVertex3f(0.92, 0.41, 0.05);
	glVertex3f(0.84, 0.29, 0.05);
	glVertex3f(0.84, 0.29, 0.1);
	glVertex3f(0.92, 0.41, 0.1);
	glEnd();
			//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(1.00, 0.41, 0.1);
	glVertex3f(0.92, 0.29, 0.1);
	glVertex3f(0.92, 0.29, 0.05);
	glVertex3f(1.00, 0.41, 0.05);
	glEnd();
			//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.00, 0.41, 0.05);
	glVertex3f(0.92, 0.41, 0.05);
	glVertex3f(0.92, 0.41, 0.1);
	glVertex3f(1.00, 0.41, 0.1);
	glEnd();
		//левая нижняя часть (\) 
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(0.84, 0.29, 0.1);
	glVertex3f(0.92, 0.17, 0.1);
	glVertex3f(1.00, 0.17, 0.1);
	glVertex3f(0.92, 0.29, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(0.84, 0.29, 0.05);
	glVertex3f(0.92, 0.29, 0.05);
	glVertex3f(1.00, 0.17, 0.05);
	glVertex3f(0.92, 0.17, 0.05);
	glEnd();
			//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(0.84, 0.29, 0.05);
	glVertex3f(0.92, 0.17, 0.05);
	glVertex3f(0.92, 0.17, 0.1);
	glVertex3f(0.84, 0.29, 0.1);
	glEnd();
			//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.00, 0.17, 0.1);
	glVertex3f(0.92, 0.17, 0.1);
	glVertex3f(0.92, 0.17, 0.05);
	glVertex3f(1.00, 0.17, 0.05);
	glEnd();
			//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, 0.5, 0);
	glVertex3f(0.92, 0.29, 0.1);
	glVertex3f(1.00, 0.17, 0.1);
	glVertex3f(1.00, 0.17, 0.05);
	glVertex3f(0.92, 0.29, 0.05);
	glEnd();

	//буква А
	//				/_\
	//			   /   \
	//разделим на 3 части: левую (/), среднюю (-), правую (\)
		//левая часть
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.17, 0.41, 0.1);
	glVertex3f(1.07, 0.17, 0.1);
	glVertex3f(1.15, 0.17, 0.1);
	glVertex3f(1.22, 0.37, 0.1);
	glVertex3f(1.22, 0.41, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.17, 0.41, 0.05);
	glVertex3f(1.22, 0.41, 0.05);
	glVertex3f(1.22, 0.37, 0.05);
	glVertex3f(1.15, 0.17, 0.05);
	glVertex3f(1.07, 0.17, 0.05);
	glEnd();
			//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, 0.5, 0);
	glVertex3f(1.17, 0.41, 0.05);
	glVertex3f(1.07, 0.17, 0.05);
	glVertex3f(1.07, 0.17, 0.1);
	glVertex3f(1.17, 0.41, 0.1);
	glEnd();
			//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.07, 0.17, 0.05);
	glVertex3f(1.15, 0.17, 0.05);
	glVertex3f(1.15, 0.17, 0.1);
	glVertex3f(1.07, 0.17, 0.1);
	glEnd();
			//правая грань
				//нижняя часть
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(1.17, 0.23, 0.1);
	glVertex3f(1.15, 0.17, 0.1);
	glVertex3f(1.15, 0.17, 0.05);
	glVertex3f(1.17, 0.23, 0.05);
	glEnd();
				//верхняя часть
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(1.22, 0.37, 0.1);
	glVertex3f(1.19, 0.28, 0.1);
	glVertex3f(1.19, 0.28, 0.05);
	glVertex3f(1.22, 0.37, 0.05);
	glEnd();
		//правая часть
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.22, 0.41, 0.1);
	glVertex3f(1.22, 0.37, 0.1);
	glVertex3f(1.29, 0.17, 0.1);
	glVertex3f(1.37, 0.17, 0.1);
	glVertex3f(1.27, 0.41, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.22, 0.41, 0.05);
	glVertex3f(1.27, 0.41, 0.05);
	glVertex3f(1.37, 0.17, 0.05);
	glVertex3f(1.29, 0.17, 0.05);
	glVertex3f(1.22, 0.37, 0.05);
	glEnd();
			//левая грань
				//нижняя часть
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(1.27, 0.23, 0.05);
	glVertex3f(1.29, 0.17, 0.05);
	glVertex3f(1.29, 0.17, 0.1);
	glVertex3f(1.27, 0.23, 0.1);
	glEnd();
				//верхняя часть
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, -0.5, 0);
	glVertex3f(1.22, 0.37, 0.05);
	glVertex3f(1.25, 0.28, 0.05);
	glVertex3f(1.25, 0.28, 0.1);
	glVertex3f(1.22, 0.37, 0.1);
	glEnd();
			//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.29, 0.17, 0.05);
	glVertex3f(1.37, 0.17, 0.05);
	glVertex3f(1.37, 0.17, 0.1);
	glVertex3f(1.29, 0.17, 0.1);
	glEnd();
			//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, 0.5, 0);
	glVertex3f(1.27, 0.23, 0.05);
	glVertex3f(1.29, 0.17, 0.05);
	glVertex3f(1.29, 0.17, 0.1);
	glVertex3f(1.27, 0.23, 0.1);
	glEnd();
			//верх буквы А
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.27, 0.41, 0.05);
	glVertex3f(1.17, 0.41, 0.05);
	glVertex3f(1.17, 0.41, 0.1);
	glVertex3f(1.27, 0.41, 0.1);
	glEnd();
		//средняя часть
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.19, 0.28, 0.1);
	glVertex3f(1.17, 0.23, 0.1);
	glVertex3f(1.27, 0.23, 0.1);
	glVertex3f(1.25, 0.28, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.19, 0.28, 0.05);
	glVertex3f(1.25, 0.28, 0.05);
	glVertex3f(1.27, 0.23, 0.05);
	glVertex3f(1.17, 0.23, 0.05);
	glEnd();
			//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.17, 0.23, 0.05);
	glVertex3f(1.27, 0.23, 0.05);
	glVertex3f(1.27, 0.23, 0.1);
	glVertex3f(1.17, 0.23, 0.1);
	glEnd();
			//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.19, 0.28, 0.05);
	glVertex3f(1.19, 0.28, 0.1);
	glVertex3f(1.25, 0.28, 0.1);
	glVertex3f(1.25, 0.28, 0.05);
	glEnd();

	//буква И
	//			|/|
	//разделим на левую (|), среднюю (/), и правую части (|)
		//левая часть
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.41, 0.41, 0.1);
	glVertex3f(1.41, 0.17, 0.1);
	glVertex3f(1.48, 0.17, 0.1);
	glVertex3f(1.48, 0.41, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.41, 0.41, 0.05);
	glVertex3f(1.48, 0.41, 0.05);
	glVertex3f(1.48, 0.17, 0.05);
	glVertex3f(1.41, 0.17, 0.05);
	glEnd();
			//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1.41, 0.41, 0.05);
	glVertex3f(1.41, 0.17, 0.05);
	glVertex3f(1.41, 0.17, 0.1);
	glVertex3f(1.41, 0.41, 0.1);
	glEnd();
			//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.41, 0.17, 0.05);
	glVertex3f(1.50, 0.17, 0.05);
	glVertex3f(1.50, 0.17, 0.1);
	glVertex3f(1.41, 0.17, 0.1);
	glEnd();
			//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(1.48, 0.41, 0.1);
	glVertex3f(1.48, 0.26, 0.1);
	glVertex3f(1.48, 0.26, 0.05);
	glVertex3f(1.48, 0.41, 0.05);
	glEnd();
			//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.48, 0.41, 0.05);
	glVertex3f(1.41, 0.41, 0.05);
	glVertex3f(1.41, 0.41, 0.1);
	glVertex3f(1.48, 0.41, 0.1);
	glEnd();
		//средняя часть
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.48, 0.26, 0.1);
	glVertex3f(1.48, 0.17, 0.1);
	glVertex3f(1.50, 0.17, 0.1);
	glVertex3f(1.59, 0.32, 0.1);
	glVertex3f(1.59, 0.41, 0.1);
	glVertex3f(1.57, 0.41, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.48, 0.26, 0.05);
	glVertex3f(1.57, 0.41, 0.05);
	glVertex3f(1.59, 0.41, 0.05);
	glVertex3f(1.59, 0.32, 0.05);
	glVertex3f(1.50, 0.17, 0.05);
	glVertex3f(1.48, 0.17, 0.05);
	glEnd();
			//левая-верхняя грань
	glBegin(GL_POLYGON);
	glNormal3f(-0.5, 0.5, 0);
	glVertex3f(1.57, 0.41, 0.05);
	glVertex3f(1.48, 0.26, 0.05);
	glVertex3f(1.48, 0.26, 0.1);
	glVertex3f(1.57, 0.41, 0.1);
	glEnd();
			//правая-нижняя грань
	glBegin(GL_POLYGON);
	glNormal3f(0.5, -0.5, 0);
	glVertex3f(1.59, 0.32, 0.1);
	glVertex3f(1.50, 0.17, 0.1);
	glVertex3f(1.50, 0.17, 0.05);
	glVertex3f(1.59, 0.32, 0.05);
	glEnd();
		//правая часть
			//перед
			//перед
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, 1);
	glVertex3f(1.59, 0.41, 0.1);
	glVertex3f(1.59, 0.17, 0.1);
	glVertex3f(1.66, 0.17, 0.1);
	glVertex3f(1.66, 0.41, 0.1);
	glEnd();
			//зад
	glBegin(GL_POLYGON);
	glNormal3f(0, 0, -1);
	glVertex3f(1.59, 0.41, 0.05);
	glVertex3f(1.66, 0.41, 0.05);
	glVertex3f(1.66, 0.17, 0.05);
	glVertex3f(1.59, 0.17, 0.05);
	glEnd();
			//левая грань
	glBegin(GL_POLYGON);
	glNormal3f(-1, 0, 0);
	glVertex3f(1.59, 0.32, 0.05);
	glVertex3f(1.59, 0.17, 0.05);
	glVertex3f(1.59, 0.17, 0.1);
	glVertex3f(1.59, 0.32, 0.1);
	glEnd();
			//низ
	glBegin(GL_POLYGON);
	glNormal3f(0, -1, 0);
	glVertex3f(1.59, 0.17, 0.05);
	glVertex3f(1.66, 0.17, 0.05);
	glVertex3f(1.66, 0.17, 0.1);
	glVertex3f(1.59, 0.17, 0.1);
	glEnd();
			//правая грань
	glBegin(GL_POLYGON);
	glNormal3f(1, 0, 0);
	glVertex3f(1.66, 0.41, 0.1);
	glVertex3f(1.66, 0.17, 0.1);
	glVertex3f(1.66, 0.17, 0.05);
	glVertex3f(1.66, 0.41, 0.05);
	glEnd();
			//верх
	glBegin(GL_POLYGON);
	glNormal3f(0, 1, 0);
	glVertex3f(1.66, 0.41, 0.05);
	glVertex3f(1.57, 0.41, 0.05);
	glVertex3f(1.57, 0.41, 0.1);
	glVertex3f(1.66, 0.41, 0.1);
	glEnd();



	glPopMatrix(); //Восстанавливаем VM=Fwe
	glDisable(GL_LIGHTING); //Выключаем освещение

	glBegin(GL_LINES); //Рисуем координаты осей
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

//функция возвращает угол поворота на начальное положение при проходе целого круга
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
	if (key == '+') //приблизить объект
	{
		scale -= 0.1;
	}
	else if (key == '-') //отдалить объект
	{
		scale += 0.1;
	}

	if (key == 'O' || key == 'o') //вращение объекта
	{
		if (flagO == 1)
			plusangle = 0.1;
		else
			plusangle = 0;
		flagO *= -1;
	}
	else if (key == 'L' || key == 'l') //вращение источника света
	{
		if (flagL == 1)
			plusangle2 = 0.1;
		else
			plusangle2 = 0;
		flagL *= -1;
	}

	if (key == 'F' || key == 'f') //показать лицевые грани
	{
		glCullFace(GL_BACK);
		glEnable(GL_CULL_FACE);
	}
	else if (key == 'B' || key == 'b') //показать нелицевые грани
	{
		glCullFace(GL_FRONT);
		glEnable(GL_CULL_FACE);
	}
}

void mouseButton(int button, int state, int x, int y) {
	if (button == GLUT_LEFT_BUTTON) glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
	else if (button == GLUT_RIGHT_BUTTON) glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
}

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("KAI");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(keys);
	glutReshapeFunc(myReshape);
	glutIdleFunc(myIdle);
	glutMouseFunc(mouseButton);
	init();
	glutMainLoop();
}