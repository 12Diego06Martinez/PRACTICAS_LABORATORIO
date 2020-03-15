#include "glut.h"
#include "Sphere.h"
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
struct Mundo {

	float x;
	float y;
	float z;
};

//Sphere sphere_1 = { 1,3,0,0,0,255,255 }; //esfera colo cyan, quieta en (3,0,0), radio va cambiando con el tiempo
//Sphere sphere_2 = { 1,-3,0,0,255,0,0 }; //esfera que se mueve por el plano XY, cambia de color y radio mediante el teclado
//Torus torus_1 = { 1,6,0,0,0,0,250,0 }; //toroide estático
Mundo miMundo = { -10,10,20 };

//------------DECLARACION FUNCIONES-------------
//Estas funciones se llamaránen la funcion OnDraw para dibujar las distintas formas

//void DrawTorus(Torus t);
//void DrawPolygon();
void Camera(Mundo* m);

//Funciones necesarias
void OnDraw(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	


//--------------MAIN--------------
int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT
	//y crear la ventana
	glutInit(&argc, argv);
	glutInitWindowSize(800, 600);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutCreateWindow("PRACTICA 2");

	//habilitar luces y definir perspectiva
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
void Camera(Mundo* m) {

	

void OnDraw(void)
{

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Borrado de la pantalla

	//Definimos el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(miMundo.x, miMundo.y, miMundo.z,  // posicion del ojo
		0.0, 0, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y)    

	//Dibujo
	Sphere sphere1;
	sphere1.SetColor(255, 0, 0);
	//DrawPolygon();
	//DrawTorus(torus_1);
	

	//NO BORRAR NUNCA ESTAS LINEAS
	glutSwapBuffers();
}
void OnKeyboardDown(unsigned char key, int x_t, int y_t)
{
	//Esfera que se mueve, cambia de color (inicialmente es roja) y radio
	if (key == 'd') {
		sphere_2.x += 0.15f; //se mueve a la derecha
	}
	if (key == 'a') {
		sphere_2.x -= 0.15f; //se mueve a la izquierda
	}
	if (key == 'w') {
		sphere_2.y += 0.15f; //se mueve hacia arriba
	}
	if (key == 's') {
		sphere_2.y -= 0.15f; //se mueve hacia abajo
	}
	if (key == '+' && sphere_2.radius < 5) {
		sphere_2.radius += 0.25f;//aumenta el radio
	}
	if (key == '-' && sphere_2.radius > 1) {
		sphere_2.radius -= 0.25f;//disminuye el radio
	}
	
	if (key == '1') {
		//Cambio de color a verde
		sphere_2.red = 0;
		sphere_2.green = 255;
		sphere_2.blue = 0;
	}
	if (key == '2') {
		//Cambio de color a azul
		sphere_2.red = 0;
		sphere_2.green = 0;
		sphere_2.blue = 255;
	}
	if (key == '3') {
		//Cambio de color a rojo
		sphere_2.red = 255;
		sphere_2.green = 0;
		sphere_2.blue = 0;
	}
	if (key == '4') {
		//Cambio de color a mix
		sphere_2.red = 125;
		sphere_2.green = 100;
		sphere_2.blue = 96;
	}

	//NO BORRAR ESTAS LINEAS
	glutPostRedisplay();
}
void OnTimer(int value)
{
	//Funcion que rota la vista de la camara
	Camera(&miMundo);

	//NO BORRAR NUNCA ESTAS LINEAS
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}