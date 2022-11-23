#include "janela.h"

Janela::Janela(int l = 1080, int a = 720) {
	janela.create(sf::VideoMode(l, a), "game");


}

Janela::~Janela() {

}

int Janela::getLargura() {
	return largura;

}

int Janela::getAltura() {
	return altura;

}
