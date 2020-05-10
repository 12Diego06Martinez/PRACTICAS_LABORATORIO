#define _STDC_WANT_IB_EXIT1__1
#define _CRT_SECURE_NO_WARNINGS

#include "glut.h"
#include "Mundo.h"

Mundo miMundo;


//Funciones necesarias
void OnDibujar(void); //esta funcion sera llamada para dibujar
void OnTimer(int value); //esta funcion sera llamada cuando transcurra una temporizacion
void OnKeyboardDown(unsigned char key, int x, int y); //cuando se pulse una tecla	
void OnSpecialKeyboardDown(int key, int x, int y);//para las teclas de cursor

//--------------MAIN--------------
int main(int argc, char* argv[])
{
	//Inicializar el gestor de ventanas GLUT y crear la ventana
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
	glutDisplayFunc(OnDibujar);
	glutTimerFunc(25, OnTimer, 0);//cada 25ms llama a la funcion OnTimer()
	glutKeyboardFunc(OnKeyboardDown);
	glutSpecialFunc(OnSpecialKeyboardDown);

	//Llamada a métodos
	miMundo.Inicializa();

	//pasarle el control a GLUT,que llamara a los callbacks
	glutMainLoop();

	return 0;
}


//------------IMPLEMENTACION FUNCIONES--------------

/*void DibujarTorus(Torus t) {

	glColor3ub(t.rojo, t.verde, t.azul);
	glTranslatef(t.x, t.y, t.z);
	glutSolidTorus(t.in_radio, t.out_radio, 20, 20);

}*/

void OnDibujar(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//Borrado de la pantalla

	//Definimos el punto de vista
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	//LLAMAR AL MÉTODO Dibujar DE LA CLASE MUNDO   (dibuja todos los objetos)
	miMundo.Dibujar();
	

	//NO BORRAR NUNCA ESTAS LINEAS
	glutSwapBuffers();
}

void OnKeyboardDown(unsigned char key, int x_t, int y_t){
	//LLAMAR AL MÉTODO DE LA CLASE MUNDO (gestiona la interacción con el teclado)
	miMundo.Key(key);

	//NO BORRAR ESTAS LINEAS
	glutPostRedisplay();
}

void OnSpecialKeyboardDown(int key, int x_t, int y_t){
	//LLAMAR AL MÉTODO DE LA CLASE MUNDO (gestiona la interacción con el teclado)
	miMundo.SpecialKey(key);

	//NO BORRAR ESTAS LINEAS
	glutPostRedisplay();
}

void OnTimer(int value){
	//LLAMAR AL METODO Mueve DE LA CLASE MUNDO (actualiza mundo y esferas)
	miMundo.Mueve();
	

	//NO BORRAR NUNCA ESTAS LINEAS
	glutTimerFunc(25, OnTimer, 0);
	glutPostRedisplay();
}