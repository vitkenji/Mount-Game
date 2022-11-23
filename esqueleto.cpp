#include "esqueleto.h"
#include "grafico.h"

Esqueleto::Esqueleto():Inimigo() {
	tempoDirecao = 5;
	cooldown = 0;

}

Esqueleto::~Esqueleto() {

}

void Esqueleto::executa() {
	cooldown += pGrafico->getDt();
	velocidade.y = 1000;
	if (cooldown >= tempoDirecao) {

		velocidade.x *= -1;
		cooldown -= tempoDirecao;

	}
	atualizaPosicao();

}