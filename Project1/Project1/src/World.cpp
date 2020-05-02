#include "World.h"
#include "Interaction.h"
#include "InteraccionListas.h"
#include "glut.h"

//////////////////////////////CONSTRUCTOR///////////////////
World::World() {
	
}

World::~World() {
	spheres.Destroy();
	shoots.Destroy();
}
/////////////////////////////MÉTODOS////////////////////////
void World::Draw() {
	//Establecemos punto de vista
	gluLookAt(x_eye, y_eye, z_eye,//posición del ojo
		0.0, y_eye, 0.0, //Miramos al centro de la escena
		0.0, 1.0, 0.0); //orientación del mundo hacia arriba

	//Dibujamos objetos
	bonus.Draw();
	human.Draw();
	platform.Draw();
	box.Draw();
	spheres.Draw();
	shoots.Draw();
}

void World::Move() {
	bonus.Move(0.025f);
	human.Move(0.025f);
	spheres.Move(0.025f);
	shoots.Move(0.025f);

	Sphere* aux = InteraccionListas::Colision(spheres,human);
	if (aux != 0)//detecta choque
		spheres.Delete(aux);
		
	//Interacción entre los objetos
	Interaction::Rebote(human, box);
	InteraccionListas::Rebote(spheres, box);
	InteraccionListas::Rebote(spheres, platform);
	InteraccionListas::Rebote(spheres);
	InteraccionListas::Colision(shoots, platform);
	InteraccionListas::Colision(shoots, box);
}

void World::Initialize() {
	//Posición del ojo
	x_eye = 0;
	y_eye = 7.5;
	z_eye = 30;
	//Inicialización bonus
	bonus.SetPos(5, 10);
	bonus.SetSide(2.5);
	//Inicialización plataforma
	platform.SetLimits(-5.0f, 9.0f, 5.0f, 9.0f);
	//Inicialización de esferas
	Sphere* sphere1 = new Sphere(1.5, 2, 4, 5, 15);
	sphere1->SetColor(255, 0, 0);
	spheres.Add(sphere1);

	Sphere* sphere2 = new Sphere(2, 8, 2, -5, 15);
	sphere2->SetColor(100, 100, 100);
	spheres.Add(sphere2);

	for (int i = 0; i < 6; i++) {
		Sphere* aux = new Sphere(0.75 + i * 0.25, i, 1 + i, i, i);
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

void World::Key(unsigned char key) {
	switch (key) {
		case ' ':
		{
			Shoot* s = new Shoot();
			Vector2D pos = human.GetPos();
			s->SetPos(pos.x, pos.y);
			shoots.Add(s);
			break;
		}
	}
}

