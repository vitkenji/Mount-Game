#include "caixa.h"

Caixa::Caixa() {

}

Caixa::~Caixa() {

}

void Caixa::executa() {

}

void Caixa::prejudicaJogador(Jogador* pJogador){


}

void Caixa::salvar() {
	ofstream arquivoCaixa("../salvamento/caixa.txt");

	arquivoCaixa << estaVivo << ""
		<< tamanho.x << ""
		<< tamanho.y << ""
		<< posicao.x << ""
		<< posicao.y << ""
		<< velocidade.x << ""
		<< velocidade.y << ""
		<< aceleracao.x << ""
		<< aceleracao.y << ""
		<< endl;

	arquivoCaixa.close();


}