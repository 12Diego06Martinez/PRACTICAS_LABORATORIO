#include "Mundo.h"
#include "Interaccion.h"
#include "InteraccionListas.h"
#include "EsferaPulsante.h"
#include "ETSIDI.h"
#include "glut.h"

//////////////////////////////CONSTRUCTOR///////////////////
Mundo::Mundo() {
	
}

Mundo::~Mundo() {
	esferas.Destruir();
	disparos.Destruir();
}
/////////////////////////////MÉTODOS////////////////////////
void Mundo::Inicializa() {
	impacto = false;
	nivel = 0;
	//Posición del ojo
	x_eye = 0;
	y_eye = 7.5;
	z_eye = 30;
	//Inicialización bonus
	bonus.SetPos(5, 10);
	bonus.SetSide(2.5);
	//Cargamos el nivel
	CargarNivel();
	/*
	//Inicialización plataforma
	plataforma.SetLimites(-5.0f, 9.0f, 5.0f, 9.0f);
	//Inicialización de esferas
	Esfera* esfera3 = new EsferaPulsante();
	esfera3->SetColor(0, 255, 0);
	esferas.Agregar(esfera3);

	for (int i = 0; i <3; i++) {
		Esfera* aux = new Esfera(0.75 + i * 0.25, i + 2, 1 + i, i*1.5, i*2);
		esferas.Agregar(aux);
	}
	*/
}


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
}

void Mundo::Mueve() {

	bonus.Mueve(0.025f);
	humano.Mueve(0.025f);
	esferas.Mueve(0.025f);
	disparos.Mueve(0.025f);

	//Interacción entre los objetos
	Interaccion::Rebote(humano, caja);
	InteraccionListas::Rebote(esferas, caja);
	InteraccionListas::Rebote(esferas, plataforma);
	InteraccionListas::Rebote(esferas);
	InteraccionListas::Colision(disparos, plataforma);
	InteraccionListas::Colision(disparos, caja);
	InteraccionListas::Colision(disparos, esferas);

	Esfera* aux = InteraccionListas::Colision(esferas, humano);
	if (aux != 0) {//detecta choque
		esferas.Delete(aux);
		impacto = true;
	}
}


void Mundo::TeclaEspecial(unsigned char key){
	switch(key) {
		case GLUT_KEY_LEFT:
			humano.SetVel(-5.0f, 0.0f);
			break;
		case GLUT_KEY_RIGHT:
			humano.SetVel(5.0f, 0.0f);
			break;
	}
}

void Mundo::Tecla(unsigned char key) {

	Disparo* d = new Disparo();
	Vector2D pos = humano.GetPos();
	switch (key) {
		case '1':
			esferas.Agregar(new Esfera(0.5f, 2, 4, 0, 10));
			break;
		case '2':
			esferas.Agregar(new Esfera(1.0f, 3, 5, 0, 10));
			break;
		case '3':
			esferas.Agregar(new Esfera(1.5f, 4, 6, 0, 10));
			break;
		case '4':
			esferas.Agregar(new Esfera(2.0f, 4, 7, 0, 10));
			break;
		case ' ':
			d->SetPos(pos);
			d->SetOrigen(pos);
			disparos.Agregar(d);
			break;
		case 'z':
			DisparoEspecial * ds = new DisparoEspecial();
			Vector2D posH = humano.GetPos();
			ds->SetPos(posH);
			ds->SetOrigen(posH);
			disparos.Agregar(ds);
			break;
	}
}

bool Mundo::CargarNivel() {
	nivel++;  
	humano.SetPos(0, 0); 
	esferas.Destruir(); 
	disparos.Destruir();

	if (nivel == 1) {
		plataforma.SetLimites(-5.0f, 9.0f, 5.0f, 9.0f);  
		Esfera* e1 = new Esfera(1.5f, 2, 4, 5, 15);   
		e1->SetColor(0, 0, 255);
		esferas.Agregar(e1); 
	} 
	if(nivel==2)  {  
		plataforma.SetLimites(-3.0f,6.0f,3.0f,6.0f); 
		plataforma.SetColor(255, 0, 0); 
		Esfera* e3 = new EsferaPulsante;  
		e3->SetPos(0, 12);  
		e3->SetVel(5, 3);  
		esferas.Agregar(e3);
	}  
	if (nivel == 3) {
		plataforma.SetLimites(-10.0f, 12.0f, 4.0f, 10.0f); 
		plataforma.SetColor(255, 0, 255); 
		for (int i = 0; i < 5; i++) { 
			Esfera* aux = new Esfera(1.5, -5 + i, 12, i, 5);  
			aux->SetColor(i * 40, 0, 255 - i * 40);   
			esferas.Agregar(aux);
		} 
	}  
	if (nivel <= 3)  
		return true; 
	return false;
}
