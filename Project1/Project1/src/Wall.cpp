#include "Wall.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Wall::Wall() {
	red = green = blue = 255; //color por defecto=blanco
	//limit1.x = limit1.y = 10;
	//limit2.x = limit2.y = 5;
}

///////////////////////////M�TODOS///////////////////////////
void Wall::Draw() {
	//Una pared es un pol�gono
	glDisable(GL_LIGHTING);
	glColor3ub(red, green, blue);
	glBegin(GL_POLYGON);
		glVertex3d(limit1.x, limit1.y, 10);
		glVertex3d(limit2.x, limit2.y, 10);
		glVertex3d(limit2.x, limit2.y, -10);
		glVertex3d(limit1.x, limit1.y, -10);
	glEnd();
	glEnable(GL_LIGHTING);
}

void Wall::SetColor(unsigned char r, unsigned char g, unsigned char b) {
	red = r;
	green = g;
	blue = b;
}

void Wall::SetLimit1(float x, float y) {
	limit1.x = x;
	limit1.y = y;
}

void Wall::SetLimit2(float x, float y) {
	limit2.x = x;
	limit2.y = y;
}