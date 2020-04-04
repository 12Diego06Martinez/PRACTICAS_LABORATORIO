#include "Wall.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Wall::Wall() {
	red = green = blue = 255; //color por defecto=blanco
}

///////////////////////////MÉTODOS///////////////////////////
void Wall::Draw() {
	//Una pared es un polígono
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

void Wall::SetLimits(float x1, float y1, float x2, float y2) {
	limit1.x = x1;
	limit1.y = y1;
	limit2.x = x2;
	limit2.y = y2;
}