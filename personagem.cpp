#include "personagem.h"

Personagem::Personagem() :Entidade() {

	vida = 100;
	aceleracao.y = 1000;
	
}

Personagem::~Personagem() {

}

void Personagem::setVida(int vida) {
	vida = vida;

}

int Personagem::getVida() {
	return vida;

}

void Personagem::alteraVida(int dano) {
	vida -= dano;
	if (vida <= 0) { estaVivo = false; }

}