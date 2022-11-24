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
	
	srand(time(NULL));
	int posicaoX = 400;
	int posicaoY = 0;
	for (int i = 0; i < 3 + rand()%3; i++) {
		float tempo = 3 + rand() % 4;
		criaEsqueleto(Coordenadaf(posicaoX, posicaoY), tempo);
		posicaoX += 20 + rand()%200;
		posicaoY += rand() % 100;
	}
	posicaoX = 200;
	posicaoY = 100;

	for (int i = 0; i < 2 + rand() % 3; i++) {
		criaGoblin(Coordenadaf(posicaoX, posicaoY));
		posicaoX += rand() % 200;
		posicaoY += 100;
		
	}
	criaBoss(Coordenadaf(600, 300), 5);
	
}

void PrimeiraFase::criaCenario() {

	Obstaculo* plataforma1 = new Obstaculo;
	plataforma1->setTamanho(Coordenadaf(900, 20));
	plataforma1->setPosicao(Coordenadaf(650, 250));
	plataforma1->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma1);
	gerenciadorColisao.obstaculos.push_back(plataforma1);

	Obstaculo* plataforma2 = new Obstaculo;
	plataforma2->setTamanho(Coordenadaf(1800, 20));
	plataforma2->setPosicao(Coordenadaf(00, 90));
	plataforma2->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma2);
	gerenciadorColisao.obstaculos.push_back(plataforma2);


	Obstaculo* plataforma3 = new Obstaculo;
	plataforma3->setTamanho(Coordenadaf(1600,20));
	plataforma3->setPosicao(Coordenadaf(0, 410));
	plataforma3->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma3);
	gerenciadorColisao.obstaculos.push_back(plataforma3);

	for (int i = 0; i < 3; i++) {
		criaEspinho(Coordenadaf(200 + 200*i, 89));

	}

	criaCaixa(Coordenadaf(930,215));
}
