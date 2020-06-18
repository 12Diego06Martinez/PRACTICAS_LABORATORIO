#include "DisparoEspecial.h"
#include "glut.h"

DisparoEspecial::DisparoEspecial() {
    radio = 0.5f;
}

DisparoEspecial::~DisparoEspecial() {

}

void DisparoEspecial::Dibuja() {

    glColor3f(5.0f, 255.0f, 255.0f);
    glPushMatrix();
    glTranslatef(posicion.x, posicion.y, 0);
    glutSolidSphere(radio, 20, 20);
    glPopMatrix();

    glDisable(GL_LIGHTING);
    glColor3f(0.0f, 255.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3d(posicion.x - 0.3, 0, 0);
    glVertex3d(posicion.x - 0.3, posicion.y, 0);
    glVertex3d(posicion.x - 0.15, posicion.y, 0);
    glVertex3d(posicion.x - 0.15, 0, 0);
    glEnd();
    glEnable(GL_LIGHTING);

    glDisable(GL_LIGHTING);
    glColor3f(0.0f, 255.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex3d(posicion.x + 0.15, 0, 0);
    glVertex3d(posicion.x + 0.15, posicion.y, 0);
    glVertex3d(posicion.x + 0.3, posicion.y, 0);
    glVertex3d(posicion.x + 0.3, 0, 0);
    glEnd();
    glEnable(GL_LIGHTING);
}
