
#include "Mesa.h"


Mesa::Mesa() : mesaNum(0), ocupada(false) {
}


Mesa::Mesa(int num) : mesaNum(num), ocupada(false) {
}

// Método para verificar se a mesa está ocupada ou não.
bool Mesa::checarMesa() {
    return ocupada;
}

// Método para marcar a mesa como ocupada.
void Mesa::ocuparMesa() {
    ocupada = true;
}

// Método para marcar a mesa como desocupada.
void Mesa::desocuparMesa() {
    ocupada = false;
}

// Método para obter o número da mesa.
int Mesa::getNumeroMesa() {
    return mesaNum;
}
