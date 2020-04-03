#include "glut.h"
#include "World.h"
#include <math.h>

void World::Initialize() {
	//Se llamará a este método en el main

	//Damos valor iniciala la posición del ojo
	x_eye = 0.0;
	y_eye = 7.5;
	z_eye = 30.0;

	//Valor incial esfera
	sphere.position.x = 2;
	sphere.positicion.y = 4;
	sphere.radius = 1.5f;
	sphere.red = 0;
	sphere.green = 0;
	sphere.blue = 255;

	//Valor inicial bonus
	bonus.position.x = 5.0f;
	bonus.positon.y = 5.0f;

	//Valor inicial disparo
	shoot.position.x = -5.0f;
	shoot.position.y = 0.0f;

	//Valor inicial plataforma
	platform.limit1.x = -5.0f;  
	platform.limite2.x = 5.0f;  
	platform.limit1.y = 9.0f;  
	platform.limit2.y = 9.0f;



}

void World::Draw() {
	//Se llamará a este método en la funcion OnDraw

	//Situamos la vista del ojo
	gluLookAt(x_eye, y_eye, z_eye,  // posicion del ojo
		0.0, y_eye, 0.0,      // hacia que punto mira  (0,0,0) 
		0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 

	//Pintamos los objetos
	sphere.Draw();
	box.Draw();
	human.Draw();
	shoot.Draw();
	platform.Draw();
	bonus.Draw();
}

void World::Move(float t) {
	//Se llamará a este método en la función Timer

	//Actualización posición cámara
	/*float distance = sqrt(((double)x_eye * (double)x_eye) + ((double)z_eye * (double)z_eye));
	float angle = atan2(z_eye, x_eye);
	angle += 0.015f;
	x_eye = distance * cos(angle);
	z_eye = distance * sin(angle);
	*/

	human.Move(0.025f);  
	sphere.Move(0.025f);  
	bonus.Move(0.025f);  
	shoot.Move(0.025f);
	
}

/*void World::Key(unsigned char key) {
	//Se llamará a este método en la función OnKeyboardDown

	//float radius = sphere_2.GetRadius();
	
	//CAMBIOS DE POSICIÓN
	//sphere_2.ChangePos(key);

	//TODO--CAMBIOS DE RADIO
	/*if (key == '+' && sphere_2.GetRadius() <= 5.0) {
		sphere_2.SetRadius(radius += 0.15); //aumenta radio
	}

	if (key == '-' && sphere_2.GetRadius() >= 1.0) {
		//float radius = sphere_2.GetRadius();
		sphere_2.SetRadius(radius -= 0.15); //disminuye radio
	}
	

	//CAMBIOS DE COLOR
	/*if (key == '0') {
		sphere_1.SetColor(255, 255, 255); //ambas esferas blancas
		sphere_2.SetColor(255, 255, 255);
	}
	if (key == '1') {
		sphere_1.SetColor(255, 0, 0); //e1 rojo
	}
	if (key == '2') {
		sphere_1.SetColor(0, 255, 0); //e1 verde
	}
	if (key == '3') {
		sphere_1.SetColor(0, 0, 255); //e1 azul
	}
	if (key == '4') {
		sphere_2.SetColor(255, 0, 0); //e2 roja
	}
	if (key == '5') {
		sphere_2.SetColor(0, 255, 0); //e2 verde
	}
	if (key == '6') {
		sphere_2.SetColor(0, 0, 255); //e2 azul
	}
}
*/
