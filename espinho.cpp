#include "espinho.h"

Espinho::Espinho() :Obstaculo() {
	dano = 1;

}

Espinho::~Espinho() {

}

void Espinho::prejudicaJogador(Jogador* pJogador) {
	pJogador->alteraVida(dano);
	pJogador->alteraVelocidade();

}

void Espinho::executa() {
	atualizaPosicao();

}