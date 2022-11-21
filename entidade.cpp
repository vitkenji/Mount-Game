#include "entidade.h"

Entidade::Entidade() :Ente(),
estaVivo(true), velocidade(Coordenadaf(0,0)), aceleracao(Coordenadaf(0, 0)) {
	estaVivo = true;
}

Entidade::~Entidade() {

}

void Entidade::atualizaPosicao(Coordenadaf coordenada) {
	posicao += coordenada;
	corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));


}

void Entidade::atualizaPosicao() {
	float dt = pGrafico->getDt();
	velocidade += aceleracao * dt;
	posicao += velocidade * dt;
	corpo.setPosition(sf::Vector2f(posicao.x, posicao.y));

}

void Entidade::executa() {
	atualizaPosicao();

}
