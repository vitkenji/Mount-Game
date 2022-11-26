#include "inimigo.h"

Inimigo::Inimigo():Personagem() {
	dano = 10;
}

Inimigo::~Inimigo() {

}

void Inimigo::setDano(int dano){
	this->dano = dano;
	dano = dano;

}

int Inimigo::getDano() {
	return dano;

}

void Inimigo::machucaJogador(Jogador* pJogador) {

}