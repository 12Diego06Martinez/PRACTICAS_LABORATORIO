#include "CoordinadorPang.h"
#include "ETSIDI.h"
#include "glut.h"
 
/////////////////////////////////CONSTRUCTOR-DESTRUCTOR///////////////////
CoordinadorPang::CoordinadorPang() {
    estado = INICIO;
}

CoordinadorPang::~CoordinadorPang() {

}

//////////////////////////////////METODOS/////////////////////////
void CoordinadorPang::Dibuja() {
    if (estado == INICIO) {
        //Dibujamos pantalla negra
        gluLookAt(0, 7.5, 30,  // posicion del ojo  
            0.0, 7.5, 0.0,      // hacia que punto mira  (0,7.5,0)    
            0.0, 1.0, 0.0);      // definimos hacia arriba (eje Y) 
        ETSIDI::setTextColor(1, 1, 0);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("Pang", -5, 8);
        ETSIDI::setTextColor(1, 1, 1);
        ETSIDI::setFont("fuentes/Bitwise.ttf", 12);
        ETSIDI::printxy("PULSE LA TECLA -E- PARA EMPEZAR", -5, 7);   
        ETSIDI::printxy("PULSE LA TECLA -S- PARA SALIR", -5, 6);
        ETSIDI::printxy("Diego Martinez", 2, 1);   
    }
    else if (estado == JUEGO) {
        mimundo.Dibujar();
    }
    else if (estado == GAMEOVER) {
        mimundo.Dibujar();  
        ETSIDI::setTextColor(1, 0, 0);  
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);  
        ETSIDI::printxy("GAMEOVER: Has perdido", -5, 10);  
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 5);
        mimundo.~Mundo();
    }
    else if (estado == FIN) { 
        mimundo.Dibujar();  
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16); 
        ETSIDI::printxy("ENHORABUENA, ¡Has triunfado!", -5, 10);  
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 9); 
    }
    else if (estado == PAUSE) {
        mimundo.Dibujar();
        ETSIDI::setFont("fuentes/Bitwise.ttf", 16);
        ETSIDI::printxy("Juego en pausa", -5, 10);
        ETSIDI::printxy("Pulsa -C- para continuar", -5, 9);
    }
}

void CoordinadorPang::Tecla(unsigned char key) {
    if (estado == INICIO) {
        if (key == 'e' || key == 'E') {
            mimundo.Inicializa();
            estado = JUEGO;
        }
        else if (key == 's' || key == 'S')
            exit(0);
    }
    else if (estado == JUEGO) {
        mimundo.Tecla(key);

        if (key == 'p')
            estado = PAUSE;
    }
    else if (estado == GAMEOVER) {
        if (key == 'c' || key == 'C')
            estado = INICIO;
    }
    else if (estado == FIN) {
        if (key == 'c' || key == 'C') 
            estado = INICIO;
    }
    else if (estado == PAUSE) {
        if (key == 'c')
            estado = JUEGO;
    }
}

void CoordinadorPang::TeclaEspecial(unsigned char key) {
    if (estado == JUEGO)
        mimundo.TeclaEspecial(key);
}

void CoordinadorPang::Mueve() {
    if (estado == JUEGO) {
        mimundo.Mueve();
        if (mimundo.GetNumEsferas() == 0) {
            if(!mimundo.CargarNivel())
                estado = FIN;
        }
        if (mimundo.GetImpacto()) {
            estado = GAMEOVER;
        }
    }
}