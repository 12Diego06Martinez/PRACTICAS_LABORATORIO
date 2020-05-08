#include "Mundo.h"
#include "Interaccion.h"
#include "InteraccionListas.h"
#include "glut.h"

//////////////////////////////CONSTRUCTOR///////////////////
Mundo::Mundo() {
	
}

Mundo::~Mundo() {
	esferas.Destruir();
	disparos.Destruir();
}
/////////////////////////////MÉTODOS////////////////////////
void Mundo::Dibujar() {
	//Establecemos punto de vista
	gluLookAt(x_eye, y_eye, z_eye,//posición del ojo
		0.0, y_eye, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba

	//Dibujamos objetos
	bonus.Dibujar();
	humano.Dibujar();
	plataforma.Dibujar();
	caja.Dibujar();
	esferas.Dibujar();
	disparos.Dibujar();
	esfera_pulsante.Dibujar();
}

void Mundo::Mueve() {
	bonus.Mueve(0.025f);
	humano.Mueve(0.025f);
	esferas.Mueve(0.025f);
	disparos.Mueve(0.025f);
	esfera_pulsante.Mueve(0.025f);

	Esfera* aux = InteraccionListas::Colision(esferas,humano);
	if (aux != 0)//detecta choque
		esferas.Delete(aux);
		
	//Interacción entre los objetos
	Interaccion::Rebote(humano, caja);
	InteraccionListas::Rebote(esferas, caja);
	InteraccionListas::Rebote(esferas, plataforma);
	InteraccionListas::Rebote(esferas);
	InteraccionListas::Colision(disparos, plataforma);
	InteraccionListas::Colision(disparos, caja);
	Interaccion::Rebote(esfera_pulsante, caja);
	Interaccion::Rebote(esfera_pulsante, plataforma);

	for (int i = 0; i < esferas.GetNum(); i++) {
		Interaccion::Rebote(esfera_pulsante, *esferas[i]);
	}
}

void Mundo::Inicializa() {
	//Posición del ojo
	x_eye = 0;
	y_eye = 7.5;
	z_eye = 30;
	//Inicialización bonus
	bonus.SetPos(5, 10);
	bonus.SetSide(2.5);
	//Inicialización plataforma
	plataforma.SetLimites(-5.0f, 9.0f, 5.0f, 9.0f);
	//Inicialización de esferas
	Esfera* esfera1 = new Esfera(1.5, 2, 4, 5, 15);
	esfera1->SetColor(255, 0, 0);
	esferas.Agregar(esfera1);

	Esfera* esfera2 = new Esfera(2, 8, 2, -5, 15);
	esfera2->SetColor(100, 100, 100);
	esferas.Agregar(esfera2);

	for (int i = 0; i < 6; i++) {
		Esfera* aux = new Esfera(0.75 + i * 0.25, i, 1 + i, i, i);
		esferas.Agregar(aux);
	}

}

void Mundo::SpecialKey(unsigned char key){
	switch(key) {
		case GLUT_KEY_LEFT:
			humano.SetVelocidad(-5.0f, 0.0f);
			break;
		case GLUT_KEY_RIGHT:
			humano.SetVelocidad(5.0f, 0.0f);
			break;
	}
}

void Mundo::Key(unsigned char key) {
	switch (key) {
		case ' ':
		{
			Disparo* d = new Disparo();
			Vector2D pos = humano.GetPos();
			d->SetPos(pos.x, pos.y);
			disparos.Agregar(d);
			break;
		}
	}
}

