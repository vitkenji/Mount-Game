#include "projetil.h"

Projetil::Projetil():Entidade() {
	setPosicao({ 2000,2000 });
	dano = 10;
	estaVivo = false;
}

Projetil::~Projetil() {

}

void Projetil::setDano(int dano) {
	this->dano = dano;
	dano = dano;

}

int Projetil::getDano() {
	return dano;

}

void Projetil::reset(Coordenadaf posicao) {
	estaVivo = true;
	velocidade = Coordenadaf(0, 0);
	aceleracao.y = 1000;
	setPosicao(posicao);

}

void Projetil::salvar() {
	ofstream arquivoProjetil("../salvamento/projetil.txt", ofstream::ios_base::app);
	arquivoProjetil << estaVivo << ""
		<< aceleracao.x << ""
		<< aceleracao.y << ""
		<< velocidade.x << ""
		<< velocidade.y << ""
		<< posicao.x << ""
		<< posicao.y << ""
		<< tamanho.x << ""
		<< tamanho.y << ""
		<< endl;
	
	arquivoProjetil.close();
}