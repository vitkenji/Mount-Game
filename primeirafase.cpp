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
	bool pausado = false;

	while (pJanela->janela.isOpen()) {
		while (pJanela->janela.pollEvent(evento)) {

			if (evento.type == sf::Event::Closed) {
				pJanela->janela.close();

			}

			if (evento.type == sf::Event::KeyPressed) {
				if (evento.key.code == sf::Keyboard::Escape) {
					if (pausado == false) { pausado = true; }
					else {
						listaEntidades.salvaEntidades();
						return;

					}
				}
				else if (evento.key.code == sf::Keyboard::Enter) {
					pausado = false;

				}
			}
		}
		if (!pausado) { atualizaJogo(); }
		else { pGrafico->atualizaDt(); }
	}
}
void PrimeiraFase::criaInimigos(){
	
	int posicaoX = 400;
	for (int i = 0; i < 3 + rand()%3; i++) {
		float tempo = 3 + rand() % 5;
		criaEsqueleto(Coordenadaf(posicaoX, 0), tempo);
		criaEsqueleto(Coordenadaf(posicaoX, 600), tempo);
		criaEsqueleto(Coordenadaf(0 + 200*i, 300), tempo);
		posicaoX += 20 + rand()%100;

	}

	posicaoX = 400;

	for (int i = 0; i < 3 + rand() % 3; i++) {
		criaGoblin(Coordenadaf(posicaoX, 200));
		criaGoblin(Coordenadaf(140*i, 600));
		posicaoX += rand() % 200;
		
	}
	
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
		criaCaixa(Coordenadaf(130*i, 660));

	}

	criaCaixa(Coordenadaf(930,215));
}

void PrimeiraFase::criaGoblin(Coordenadaf posicao) {

	Goblin* goblin = new Goblin;
	goblin->setTamanho(Coordenadaf(40, 40));
	goblin->setPosicao(Coordenadaf(posicao));
	goblin->setImagem("imagens/goblin.png");
	goblin->pJogador = pJogador;
	listaEntidades.adicionaEntidade(goblin);
	gerenciadorColisao.inimigos.push_back(goblin);

	for (int i = 0; i < 5; i++) {
		goblin->adicionaProjetil(criaProjetil());

	}
	goblin->i = goblin->projeteis.begin();

}