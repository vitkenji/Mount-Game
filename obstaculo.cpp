#include "obstaculo.h"

Obstaculo::Obstaculo():Entidade() {
	estaVivo = true;
	forca = -1000;

}

Obstaculo::~Obstaculo() {


}

void Obstaculo::prejudicaJogador(Jogador* pJogador) {


}

void Obstaculo::executa() {

	atualizaPosicao();
}

void Obstaculo::setForca(int forca) {
	this->forca = forca;
	forca = forca;
}

int Obstaculo::getForca() {
	return forca;


}