#include "primeirafase.h"

using namespace std;

PrimeiraFase::PrimeiraFase(Janela* pJanela, Grafico* pGrafico) :
	Fase(pJanela, pGrafico) {

	criaCenario();
	criaInimigos();
	
}

PrimeiraFase::~PrimeiraFase() {
	
}

void PrimeiraFase::executar() {

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

void PrimeiraFase::criaInimigos() {
	
	int posicaoInimigo = 400;
	srand(time(NULL));

	for (int i = 0; i < 3 + rand()%3; i++) {
		criaEsqueleto(Coordenadaf(posicaoInimigo, 0));
		//criaGoblin(Coordenadaf(posicaoInimigo, 500));
		posicaoInimigo += 50 + rand()%100;
	}
}

void PrimeiraFase::criaCenario() {

	Entidade* plataforma1 = new Entidade;
	plataforma1->setTamanho(Coordenadaf(900, 15));
	plataforma1->setPosicao(Coordenadaf(650, 300));
	plataforma1->setCor(0, 210, 10);
	listaEntidades.adicionaEntidade(plataforma1);
	gerenciadorColisao.entidadesEstaticas.push_back(plataforma1);

	Entidade* plataforma2 = new Entidade;
	plataforma2->setTamanho(Coordenadaf(1800, 15));
	plataforma2->setPosicao(Coordenadaf(00, 90));
	plataforma2->setCor(0, 210, 10);
	listaEntidades.adicionaEntidade(plataforma2);
	gerenciadorColisao.entidadesEstaticas.push_back(plataforma2);

	Entidade* plataforma3 = new Entidade;
	plataforma3->setTamanho(Coordenadaf(1600,15));
	plataforma3->setPosicao(Coordenadaf(0, 450));
	plataforma3->setCor(0, 210, 10);
	listaEntidades.adicionaEntidade(plataforma3);
	gerenciadorColisao.entidadesEstaticas.push_back(plataforma3);

}