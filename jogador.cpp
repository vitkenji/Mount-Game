#include "jogador.h"

Jogador::Jogador() : Personagem(), pontos() {
	podePular = false;
	pontos = 0;
	vida = 1000;
	aceleracao.y = 1000;
}

Jogador::~Jogador() {

}
void Jogador::movimenta() {

	int acel = 275;

	velocidade.x = 0;
	aceleracao.y = 3000;
	//velocidade.y = 1000;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && podePular == true) {
		velocidade.y += -1000;
		podePular = false;
		atualizaPosicao();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocidade.x = -acel;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocidade.x = acel;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocidade.y = acel;

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