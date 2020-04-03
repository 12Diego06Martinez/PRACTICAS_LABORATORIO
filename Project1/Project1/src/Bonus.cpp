#include <stdlib.h>
#include "glut.h"
#include "Bonus.h"


Bonus::Bonus() {
	//TODO--
	side = 2;
}

void Bonus::Draw() {
	//TODO--
	glPushMatrix();  
	glTranslatef(position.x, position.y, 0);  
	glRotatef(30, 1, 1, 1);  
	glColor3f(	rand() / (float)RAND_MAX, rand() / (float)RAND_MAX, 
				rand() / (float)RAND_MAX); //color aleatorio    
		glutSolidCube(side);  
	glPopMatrix(); 
}

void Bonus::Move(float t) {
	//TODO--
	position.x = position.x + speed.x * t + 0.5f * aceleration.x * t * t;  
	position.y = position.y + speed.y * t + 0.5f * aceleration.y * t * t;  
	speed.x = speed.x + aceleration.x * t; 
	speed.y = speed.y + aceleration.y * t;
}