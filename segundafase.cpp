#include "segundafase.h"

SegundaFase::SegundaFase(Janela* pJanela):Fase(pJanela) {
	criaCenario();
	criaInimigos();
}

SegundaFase::~SegundaFase() {

}

void SegundaFase::criaInimigos() {

	int posicaoX = 400;

	for (int i = 0; i < 2 + rand()%3; i++) {
		criaEsqueleto(Coordenadaf(posicaoX, 600), 2.1 + rand()%4);
		posicaoX += rand() % 100;
	}

	posicaoX = 400;
	for (int i = 0; i < 2 + rand()%3; i++) {
		criaGoblin(Coordenadaf(posicaoX, 200));
		posicaoX += rand() % 200;
	}

	posicaoX = 400;
	int posicaoY = 0;
	for (int i = 0; i < 2 + rand()%3; i++) {
		criaBoss(Coordenadaf(posicaoX, posicaoY), 2.1 + rand() % 4);
		posicaoX += 100 + rand() % 300;
		posicaoY += 100;
	}
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

void SegundaFase::criaCenario() {
	criaCaixa(Coordenadaf(200, 670));
	criaCaixa(Coordenadaf(300, 670));
	criaCaixa(Coordenadaf(300, 620));
	
	Obstaculo* plataforma1 = new Obstaculo;
	plataforma1->setTamanho(Coordenadaf(350, 20));
	plataforma1->setPosicao(Coordenadaf(0, 500));
	plataforma1->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma1);
	gerenciadorColisao.obstaculos.push_back(plataforma1);

	Obstaculo* plataforma2 = new Obstaculo;
	plataforma2->setTamanho(Coordenadaf(250, 20));
	plataforma2->setPosicao(Coordenadaf(450, 500));
	plataforma2->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma2);
	gerenciadorColisao.obstaculos.push_back(plataforma2);

	criaCaixa(Coordenadaf(550,460));
	criaEspinho(Coordenadaf(490, 499));

	Obstaculo* plataforma3= new Obstaculo;
	plataforma3->setTamanho(Coordenadaf(250, 20));
	plataforma3->setPosicao(Coordenadaf(800, 440));
	plataforma3->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma3);
	gerenciadorColisao.obstaculos.push_back(plataforma3);

	criaEspinho(Coordenadaf(820,439));

	Obstaculo* plataforma4 = new Obstaculo;
	plataforma4->setTamanho(Coordenadaf(250, 20));
	plataforma4->setPosicao(Coordenadaf(1100, 380));
	plataforma4->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma4);
	gerenciadorColisao.obstaculos.push_back(plataforma4);

	criaEspinho(Coordenadaf(1090, 379));


	for (int i = 0; i < 3 + rand() % 2; i++) {
		criaAgua(Coordenadaf(200 + 200*i,700));

	}

}