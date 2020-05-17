#pragma once
#include "Mundo.h"

class CoordinadorPang
{
public:
	CoordinadorPang();
	~CoordinadorPang();
	void TeclaEspecial(unsigned char key);
	void Tecla(unsigned char key);
	void Mueve();
	void Dibuja();
protected:
	Mundo mimundo;
	enum Estado{INICIO, JUEGO, GAMEOVER, FIN};
	Estado estado;
};

