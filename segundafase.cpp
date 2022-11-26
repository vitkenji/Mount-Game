#include "segundafase.h"

SegundaFase::SegundaFase(Janela* pJanela):Fase(pJanela) {
	criaCenario();
	criaInimigos();
}

SegundaFase::~SegundaFase() {

}

void SegundaFase::criaInimigos() {

	int posicaoX = 400;

	for (int i = 0; i < 3 + rand()%2; i++) {
		criaEsqueleto(Coordenadaf(400 + 50 * i, 0),1.7 + rand()%3);
		criaEsqueleto(Coordenadaf(posicaoX, 200), 2.1 + rand()%4);
		posicaoX += rand() % 100;
	}
	posicaoX = 400;

	for (int i = 0; i < 3 + rand() % 2; i++) {
		criaBoss(Coordenadaf(posicaoX, 600), 2.1 + rand() % 4);
		posicaoX += 100 + rand() % 300;
	}
}

void SegundaFase::executar() {
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

void SegundaFase::criaCenario() {
	criaCaixa(Coordenadaf(190, 670));
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

	criaAgua(Coordenadaf(490, 499));

	Obstaculo* plataforma3= new Obstaculo;
	plataforma3->setTamanho(Coordenadaf(250, 20));
	plataforma3->setPosicao(Coordenadaf(800, 440));
	plataforma3->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma3);
	gerenciadorColisao.obstaculos.push_back(plataforma3);

	criaAgua(Coordenadaf(820,439));

	Obstaculo* plataforma4 = new Obstaculo;
	plataforma4->setTamanho(Coordenadaf(250, 20));
	plataforma4->setPosicao(Coordenadaf(1100, 380));
	plataforma4->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma4);
	gerenciadorColisao.obstaculos.push_back(plataforma4);

	Obstaculo* plataforma5 = new Obstaculo;
	plataforma5->setTamanho(Coordenadaf(600, 20));
	plataforma5->setPosicao(Coordenadaf(00, 300));
	plataforma5->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma5);
	gerenciadorColisao.obstaculos.push_back(plataforma5);

	Obstaculo* plataforma6 = new Obstaculo;
	plataforma6->setTamanho(Coordenadaf(400, 20));
	plataforma6->setPosicao(Coordenadaf(500, 210));
	plataforma6->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma6);
	gerenciadorColisao.obstaculos.push_back(plataforma6);

	Obstaculo* plataforma7 = new Obstaculo;
	plataforma7->setTamanho(Coordenadaf(200, 20));
	plataforma7->setPosicao(Coordenadaf(900, 300));
	plataforma7->setImagem("imagens/chao.png");
	listaEntidades.adicionaEntidade(plataforma7);
	gerenciadorColisao.obstaculos.push_back(plataforma7);

	criaAgua(Coordenadaf(1090, 379));


	for (int i = 0; i < 3 + rand() % 2; i++) {
		criaEspinho(Coordenadaf(600.f + 200.f * i, 699.f));

	}

}

void SegundaFase::criaBoss(Coordenadaf posicao, float tempo) {
	Boss* boss = new Boss(tempo);
	boss->setTamanho(Coordenadaf(100, 100));
	boss->setPosicao(Coordenadaf(posicao));
	boss->setImagem("imagens/feiticeiro.png");
	boss->pJogador = pJogador;
	boss->velocidade.x = (30);
	listaEntidades.adicionaEntidade(boss);
	gerenciadorColisao.inimigos.push_back(boss);

	for (int i = 0; i < 5; i++) {
		boss->adicionaProjetil(criaProjetil());

	}
	boss->i = boss->projeteis.begin();


}