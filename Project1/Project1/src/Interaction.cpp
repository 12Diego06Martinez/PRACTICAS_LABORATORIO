#include "Interaction.h"
#include <cmath>

//////////////////////////CONSTRUCTOR/////////////////////////
Interaction::Interaction() {

}

///////////////////////////METODOS///////////////////////////
void Interaction::Rebote(Human& h, Box b) {
	float x_max = b.floor.limit2.x;
	float x_min = b.floor.limit1.x;

	if (h.position.x > x_max) h.position.x = x_max;
	if (h.position.x < x_min) h.position.x = x_min;
}

bool Interaction::Rebote(Sphere& s, Wall w) {
	Vector2D dir;  
	float dif = w.Distance(s.position, &dir) - s.radius; //calcula la distancia entre la pared y la esfera y le resta el radio  
	if (dif <= 0.0f) { //han chocado ya 
		//Vf=Vi-2(Vi*direccion)*direccion
		Vector2D v_inicial = s.speed;   
		s.speed = v_inicial - dir * 2.0 * (v_inicial * dir);  
		s.position = s.position - dir * dif;   
		return true; 
	}  
	return false;
}

void Interaction::Rebote(Sphere& s, Box b) {
	Rebote(s, b.floor);
	Rebote(s, b.roof);
	Rebote(s, b.right_wall);
	Rebote(s, b.left_wall);
}

bool Interaction::Rebote(Sphere& sphere1, Sphere& sphere2) {
	//Vector que une los centros
	Vector2D dif = sphere2.position - sphere1.position;
	float d = dif.Modulo();
	float dentro = d - (sphere1.radius + sphere2.radius);

	if (dentro < 0.0f)//si hay colision
	{
		//El modulo y argumento de la velocidad de la pelota1
		float v1 = sphere1.speed.Modulo();
		float ang1 = sphere1.speed.Argumento();

		//El modulo y argumento de la velocidad de la pelota2
		float v2 = sphere2.speed.Modulo();
		float ang2 = sphere2.speed.Argumento();

		//el argumento del vector que une los centros
		float angd = dif.Argumento();

		//Separamos las esferas, lo que se han incrustado
		//la mitad cada una
		Vector2D desp(dentro / 2 * cos(angd), dentro / 2 * sin(angd));
		sphere1.position = sphere1.position + desp;
		sphere2.position = sphere2.position - desp;

		angd = angd - 3.14159f / 2;//la normal al choque

		//El angulo de las velocidades en el sistema relativo antes del choque
		float th1 = ang1 - angd;
		float th2 = ang2 - angd;

		//Las componentes de las velocidades en el sistema relativo ANTES del choque
		float u1x = v1 * cos(th1);
		float u1y = v1 * sin(th1);
		float u2x = v2 * cos(th2);
		float u2y = v2 * sin(th2);

		//Las componentes de las velocidades en el sistema relativo DESPUES del choque
		//la componente en X del sistema relativo no cambia
		float v1x = u1x;
		float v2x = u2x;

		//en el eje Y, rebote elastico
		float m1 = sphere1.radius;
		float m2 = sphere2.radius;
		float py = m1 * u1y + m2 * u2y;//Cantidad de movimiento inicial ejey
		float ey = m1 * u1y * u1y + m2 * u2y * u2y;//Energia cinetica inicial ejey

		//los coeficientes y discriminante de la ecuacion cuadrada
		float a = m2 * m2 + m1 * m2;
		float b = -2 * py * m2;
		float c = py * py - m1 * ey;
		float disc = b * b - 4 * a * c;
		if (disc < 0)disc = 0;

		//las nuevas velocidades segun el eje Y relativo
		float v2y = (-b + sqrt(disc)) / (2 * a);
		float v1y = (py - m2 * v2y) / m1;

		//Modulo y argumento de las velocidades en coordenadas absolutas
		float modv1, modv2, fi1, fi2;
		modv1 = sqrt(v1x * v1x + v1y * v1y);
		modv2 = sqrt(v2x * v2x + v2y * v2y);
		fi1 = angd + atan2(v1y, v1x);
		fi2 = angd + atan2(v2y, v2x);

		//Velocidades en absolutas despues del choque en componentes
		sphere1.speed.x = modv1 * cos(fi1);
		sphere1.speed.y = modv1 * sin(fi1);
		sphere2.speed.x = modv2 * cos(fi2);
		sphere2.speed.y = modv2 * sin(fi2);
	}
	return false;
}
