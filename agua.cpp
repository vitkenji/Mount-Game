#include "agua.h"

Agua::Agua():Obstaculo(){
	retardo = 0.21;

}

Agua::~Agua(){}

void Agua::executa() {
	atualizaPosicao();
}

void Agua::prejudicaJogador(Jogador* pJogador){
	if (pJogador->desaceleracao < 0.05) {
		pJogador->velocidadeMovimento *= retardo;

	}
	pJogador->desaceleracao = 0.2;
}



