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

void Espinho::salvar() {
	ofstream arquivoEspinho("../salvamento/espinho.txt", ios_base::app);
	arquivoEspinho << estaVivo << ""
		<< tamanho.x << ""
		<< tamanho.y << ""
		<< posicao.x << ""
		<< posicao.y << ""
		<< velocidade.x << ""
		<< velocidade.y << ""
		<< aceleracao.x << ""
		<< aceleracao.y << ""
		<< dano << ""
		<< endl;

	arquivoEspinho.close();

}