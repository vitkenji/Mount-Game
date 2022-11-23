#include "espinho.h"

Espinho::Espinho() :Obstaculo() {

}

Espinho::~Espinho() {

}

void Espinho::machucaJogador(Jogador* pJogador) {
	pJogador->alteraVida(10);

}