#include "ente.h"
#include "grafico.h"

Ente::Ente() : corpo(),
posicao(Coordenadaf(posicao)), tamanho(Coordenadaf(tamanho)) {

}

Ente::~Ente() {

}

void Ente::setImagem(string arquivo) {
	
	if (!imagem.loadFromFile(arquivo)) { cout << "error" << endl; }
	
	sprite.setTexture(imagem);
	

}

void Ente::setPosicao(Coordenadaf posicao) {
	this->posicao = posicao;
	corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));
	sprite.setPosition(sf::Vector2f(posicao.x, posicao.y));

}

Coordenadaf Ente::getPosicao() {
	return posicao;

}

void Ente::setTamanho(Coordenadaf tamanho) {
	this->tamanho = tamanho;
	corpo.setSize(sf::Vector2f(tamanho.x, tamanho.y));;
	corpo.setOrigin(sf::Vector2f(tamanho.x / 2, tamanho.y / 2));

}

Coordenadaf Ente::getTamanho() {
	return tamanho;

}

void Ente::imprimir() {
	pGrafico->imprime(this);

}

void Ente::setCor(float x, float y, float z) {
	corpo.setFillColor(sf::Color(x, y, z));


}