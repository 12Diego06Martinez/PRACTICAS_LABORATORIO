#define _STDC_WANT_LIB_EXIT1__1
#define _CRT_SECURE_NO_WARNINGS


#include "glut.h"
#include "Sphere.h"
#include "World.h"
#include <iostream>
#include <math.h>

//---------OBJETOS STRUCT-----------
/*struct Torus {

	float in_radius;
	float out_radius;
	float x;
	float y;
	float z;
	unsigned char red;
	unsigned char green;
	unsigned char blue;
};*/

//Torus torus_1 = { 1,6,0,0,0,0,250,0 }; //toroide estático


//------------DECLARACION FUNCIONES-------------
//Estas funciones se llamaránen la funcion OnDraw para dibujar las distintas formas

//void DrawTorus(Torus t);
//void DrawPolygon();


//Funciones necesarias
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	

World miMundo;

//--------------MAIN--------------
int main(int argc, char* argv[])
{
	

	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("PRACTICA 2");

	//Habilitar luces y definir perspectiva
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHTING);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_COLOR_MATERIAL);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(40.0, 800 / 600.0f, 0.1, 150);

	//Registramos los callbacks
	glutDisplayFunc(OnDraw);
	glutTimerFunc(25, OnTimer, 0);//cada 25ms llama a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);

	//Llamada a métodos
	

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}


//------------IMPLEMENTACION FUNCIONES--------------

/*void DrawTorus(Torus t) {

	glColor3ub(t.red, t.green, t.blue);
	glTranslatef(t.x, t.y, t.z);
	glutSolidTorus(t.in_radius, t.out_radius, 20, 20);

}*/
/*void DrawPolygon() {

	glDisable(GL_LIGHTING);
	glBegin(GL_POLYGON);
	glColor3ub(255, 0, 0);
	glVertex3f(5.0f, 0.0f, 5.0f);
	glColor3ub(255, 255, 0);
	glVertex3f(5.0f, 0.0f, -5.0f);
	glColor3ub(0, 255, 255);
	glVertex3f(-5.0f, 0.0f, -5.0f);
	glColor3ub(255, 255, 255);
	glVertex3f(-5.0f, 0.0f, 5.0f);
	glEnd();
	glEnable(GL_LIGHTING);
}*/

void OnDraw(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Borrado de la pantalla

	//Definimos el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//LLAMAR AL MÉTODO DRAW DE LA CLASE MUNDO   (dibuja todos los objetos)

	

	

	//NO BORRAR NUNCA ESTAS LINEAS
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{


	//NO BORRAR ESTAS LINEAS
	glutPostRedisplay();
}
void OnTimer(int value)
{
	//LLAMAR AL METODO MOVE DE LA CLASE MUNDO
	

	//NO BORRAR NUNCA ESTAS LINEAS
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}