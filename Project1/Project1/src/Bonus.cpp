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
	position = position	+ speed * t + aceleration * (0.5f * t * t);
	speed = speed + aceleration * t;
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