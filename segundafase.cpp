#include "segundafase.h"

SegundaFase::SegundaFase(Janela* pJanela, Grafico* pGrafico):Fase(pJanela, pGrafico) {

}

SegundaFase::~SegundaFase() {

}

void SegundaFase::criaInimigos() {
	criaBoss();
}

void SegundaFase::executar() {

	sf::Event evento;

	while (pJanela->janela.isOpen()) {
		while (pJanela->janela.pollEvent(evento)) {

			if (evento.type == sf::Event::Closed) {
				pJanela->janela.close();

			}

		}

		atualizaJogo();

	}
}

void SegundaFase::criaBoss() {

	Boss* boss = new Boss;
	boss->setTamanho(Coordenadaf(100, 100));
	boss->setPosicao(Coordenadaf(800, 0));
	listaEntidades.adicionaEntidade(boss);
	gerenciadorColisao.inimigos.push_back(boss);

}