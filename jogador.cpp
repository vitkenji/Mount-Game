#include "jogador.h"

Jogador::Jogador() : Personagem(), pontos() {
	podePular = false;
	pontos = 0;
	vida = 1000;
	aceleracao.y = 1000;
	desaceleracao = 0;

}

Jogador::~Jogador() {

}
void Jogador::movimenta() {
	velocidadeMovimento = 275;

	if (desaceleracao > 0.05) {
		desaceleracao -= pGrafico->getDt();
		velocidadeMovimento = 50;
		setPulo(false);

	}

	else {
		velocidadeMovimento = 275;
		desaceleracao = 0;

	}

	velocidade.x = 0;
	aceleracao.y = 3000;
	//velocidade.y = 1000;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && podePular == true) {
		velocidade.y += -800;
		podePular = false;
		atualizaPosicao();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		velocidade.x = -velocidadeMovimento;

	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		velocidade.x = velocidadeMovimento;

	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		velocidade.y = velocidadeMovimento;

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

void Jogador::alteraVelocidade() {
	velocidade.x = 100;


}