#include "Wall.h"
#include "glut.h"

////////////////////////CONSTRUCTOR////////////////////////////
Wall::Wall() {
	//TODO--
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