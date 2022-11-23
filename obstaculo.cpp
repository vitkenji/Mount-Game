#include "obstaculo.h"

Obstaculo::Obstaculo():Entidade() {
	estaVivo = true;
	forca = -1000;

}

Obstaculo::~Obstaculo() {


}

void Obstaculo::afetaJogador(Jogador* pJogador) {


}

void Obstaculo::executa() {
	aceleracao.y = 1000 - forca;

}

void Obstaculo::setForca(int forca) {
	this->forca = forca;
	forca = forca;
}

int Obstaculo::getForca() {
	return forca;


}