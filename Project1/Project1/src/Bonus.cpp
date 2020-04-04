#include "Bonus.h"
#include <stdlib.h>
#include "glut.h"



////////////////////////CONSTRUCTOR////////////////////////////
Bonus::Bonus() {
	side = 2;
	aceleration.y = -9.8f;
}

///////////////////////////MÉTODOS///////////////////////////
void Bonus::Draw() {
	//Dibujamos el bonus como un cubo de color aleatorio
	glPushMatrix();  
	glTranslatef(position.x, position.y, 0);  
	glRotatef(30, 1, 1, 1);  
	glColor3f(	rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, 
				rand() / (float)RAND_MAX); //color aleatorio    
		glutSolidCube(side);  
	glPopMatrix(); 
}

void Bonus::Move(float t) {
	//Definimos las ecuaciones de movimiento
	position.x = position.x + speed.x * t + 0.5f * aceleration.x * t * t;  
	position.y = position.y + speed.y * t + 0.5f * aceleration.y * t * t;  
	speed.x = speed.x + aceleration.x * t; 
	speed.y = speed.y + aceleration.y * t;
}

void Bonus::SetPos(float x, float y) {
	position.x = x;
	position.y = y;
}

void Bonus::SetSide(float s) {
	if (s > 0) {
		side = s;
	}
}