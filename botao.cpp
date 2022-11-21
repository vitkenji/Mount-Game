#include "botao.h"
#include "grafico.h"

using namespace std;

Botao::Botao():Entidade(), texto() {
	selecionado = false;
}

Botao::Botao(string arquivo = "../fontes/m5x7.ttf", string string = "botao", int tamanho = 50) :Entidade(), texto() {
	selecionado = false;
	setFonte(arquivo);
	texto.setString(string);
	texto.setCharacterSize(tamanho);

}

Botao::~Botao() {
	delete texto.getFont();

}

void Botao::imprime() {
	pGrafico->imprime(this);
	pGrafico->imprimeTexto(&texto);

}

void Botao::setString(string string) {
	texto.setString(string);

}

void Botao::setFonte(string arquivo) {

	sf::Font* ptr = new sf::Font;

	if (!ptr->loadFromFile(arquivo)) {
		delete ptr;
		return;

	}

	if (texto.getFont()) { delete texto.getFont(); }

	texto.setFont(*ptr);

}

void Botao::setPosicao(Coordenadaf posicao){
	this->posicao = posicao;
	corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));
	texto.setPosition(sf::Vector2f(posicao.x - texto.getCharacterSize() * ((float)texto.getString().getSize() / 4.0f), posicao.y - ((float)texto.getCharacterSize() / 2.0f)));

}
