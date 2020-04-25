#include "World.h"
#include "Interaction.h"
#include "glut.h"

//////////////////////////////CONSTRUCTOR///////////////////
World::World() {
	
}

/////////////////////////////MÉTODOS////////////////////////
void World::Draw() {
	//Establecemos punto de vista
	gluLookAt(x_eye, y_eye, z_eye,//posición del ojo
		0.0, y_eye, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba

	//Dibujamos objetos
	sphere1.Draw();
	sphere2.Draw();
	bonus.Draw();
	human.Draw();
	shoot.Draw();
	platform.Draw();
	box.Draw();
	spheres.Draw();
}

void World::Move() {
	sphere1.Move(0.025f);
	sphere2.Move(0.025f);
	bonus.Move(0.025f);
	human.Move(0.025f);
	shoot.Move(0.025f);
	spheres.Move(0.025f);
	Interaction::Rebote(human, box);
	Interaction::Rebote(sphere1, box);
	Interaction::Rebote(sphere2, box);
	Interaction::Rebote(sphere1, platform);
	Interaction::Rebote(sphere1, sphere2);
	//spheres.Rebote(box);
	//spheres.Rebote(platform);
}

void World::Initialize() {
	//Posición del ojo
	x_eye = 0;
	y_eye = 7.5;
	z_eye = 30;
	//Inicialización esfera 1
	sphere1.SetColor(255, 0, 0);
	sphere1.SetPos(2, 4);
	sphere1.SetRadius(1.5);
	sphere1.SetSpeed(5, 15);
	//Inicialización esfera 2
	sphere2.SetColor(0, 100, 100);
	sphere2.SetPos(8, 2);
	sphere2.SetRadius(2);  
	sphere2.SetSpeed(-5, 15);
	//Inicialización bonus
	bonus.SetPos(5, 10);
	bonus.SetSide(2.5);
	//Inicialización disparo
	shoot.SetPos(5, 5);
	//Inicialización plataforma
	platform.SetLimits(-5.0f, 9.0f, 5.0f, 9.0f);
	//Inicialización lista de esferas
	for (int i = 0; i < 6; i++) {
		Sphere* aux = new Sphere(0.75 + i * 0.25, i, 1 + i, i, i);
		/*Sphere* aux = new Sphere();
		aux->SetPos(i, 1 + i);
		aux->SetSpeed(i, i);
		aux->SetRadius(0.75 + i * 0.25);*/
		spheres.Add(aux);
	}
}

void World::SpecialKey(unsigned char key){
	switch(key) {
		case GLUT_KEY_LEFT:
			human.SetSpeed(-5.0f, 0.0f);
			break;
		case GLUT_KEY_RIGHT:
			human.SetSpeed(5.0f, 0.0f);
			break;
	}
}

