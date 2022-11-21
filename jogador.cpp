#include "jogador.h"

Jogador::Jogador() : Personagem(), pontos() {
	podePular = false;
	pontos = 0;
	vida = 1000;
}

Jogador::~Jogador() {

}
void Jogador::movimenta() {

	int aceleracao = 250;

	velocidade.x = 0;
	//velocidade.y = 1300;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && podePular == true) {
		velocidade.y += -950;
		podePular = false;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocidade.x = -aceleracao;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocidade.x = aceleracao;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocidade.y = aceleracao;

	}
}

void Jogador::setPulo(bool pula) {
	podePular = pula;

}

void Jogador::executa() {
	movimenta();
	atualizaPosicao();

}

void Jogador::setPontos(int pontos) {
	pontos = pontos;

}

int Jogador::getPontos() {
	return pontos;

}

void Jogador::pontua() {
	pontos += 100;

}