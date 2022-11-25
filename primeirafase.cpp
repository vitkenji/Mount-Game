#include "primeirafase.h"

using namespace std;

PrimeiraFase::PrimeiraFase(Janela* pJanela) :
	Fase(pJanela) {

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
	posicaoX = 400;
	posicaoY = 100;

	for (int i = 0; i < 2 + rand() % 3; i++) {
		criaGoblin(Coordenadaf(posicaoX, posicaoY));
		posicaoX += rand() % 200;
		posicaoY += 100;
		
	}

	criaBoss(Coordenadaf(600, 300), 3 + rand() % 2);
	criaBoss(Coordenadaf(600, 600), 2  + rand() % 3);
	criaBoss(Coordenadaf(200, 600), 3 + rand()% 3);
	
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

	Obstaculo* plataforma4 = new Obstaculo;
	plataforma4->setTamanho(Coordenadaf(300, 20));
	plataforma4->setPosicao(Coordenadaf(930, 500));
	plataforma4->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma4);
	gerenciadorColisao.obstaculos.push_back(plataforma4);

	Obstaculo* plataforma5 = new Obstaculo;
	plataforma5->setTamanho(Coordenadaf(150, 20));
	plataforma5->setPosicao(Coordenadaf(710, 570));
	plataforma5->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma5);
	gerenciadorColisao.obstaculos.push_back(plataforma5);

	for (int i = 0; i < 3 + rand()%2; i++) {

		criaEspinho(Coordenadaf(200 + 200*i, 89));
		criaAgua(Coordenadaf(200 + 200 * i, 409));

	}

	criaCaixa(Coordenadaf(930,215));
	criaCaixa(Coordenadaf(500, 660));

}
