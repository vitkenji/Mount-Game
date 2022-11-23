#include "fase.h"

Fase::Fase(Janela* pJanela, Grafico* pGrafico) :
	gerenciadorColisao(pJanela), listaEntidades(), pJanela(pJanela) {

	gerenciadorGrafico = nullptr;
	gerenciadorGrafico = Grafico::getInstance();
	Ente::pGrafico = Grafico::getInstance();

	criaChao();
	criaJogador();

}

Fase::~Fase() {

}

void Fase::gerenciaColisao() {
	gerenciadorColisao.checaColisao();

}

void Fase::criaChao() {
	Obstaculo* chao = new Obstaculo;
	chao->setPosicao(Coordenadaf(0, 705));
	chao->setTamanho({ 4000,30 });
	chao->setCor(0, 210, 10);
	listaEntidades.adicionaEntidade(chao);
	gerenciadorColisao.obstaculos.push_back(chao);

}

void Fase::criaJogador() {
	Jogador* jogador1 = new Jogador();
	jogador1->setPosicao(Coordenadaf(0, 0));
	jogador1->setTamanho(Coordenadaf(40, 40));
	jogador1->setPontos(0);
	jogador1->setCor(255, 255, 255);
	listaEntidades.adicionaEntidade(jogador1);
	gerenciadorColisao.jogadores.push_back(jogador1);

}

void Fase::atualizaJogo() {

	gerenciadorGrafico->atualizaDt();
	listaEntidades.executaEntidades();
	gerenciadorColisao.checaColisao();
	gerenciadorGrafico->clear();
	//gerenciadorGrafico->imprimeBackground();
	listaEntidades.inicializaEntidades();
	gerenciadorGrafico->display();

}

Projetil* Fase::criaProjetil() {

	Projetil* pProjetil = new Projetil;
	pProjetil->setTamanho(Coordenadaf(5,5));
	pProjetil->corpo.setFillColor(sf::Color::Yellow);
	listaEntidades.adicionaEntidade(pProjetil);
	gerenciadorColisao.projeteis.push_back(pProjetil);
	return pProjetil;

}

void Fase::criaEspinho(Coordenadaf posicao) {

	Espinho* espinho = new Espinho;
	espinho->setTamanho(Coordenadaf(100,20));
	espinho->setPosicao(Coordenadaf(posicao));
	espinho->setCor(50, 50, 50);
	listaEntidades.adicionaEntidade(espinho);
	gerenciadorColisao.obstaculos.push_back(espinho);

}

void Fase::criaGoblin(Coordenadaf posicao) {

	Goblin* goblin = new Goblin;
	goblin->setTamanho(Coordenadaf(30,30));
	goblin->setPosicao(Coordenadaf(posicao));
	goblin->setCor(10, 10, 200);
	goblin->pJogador = pJogador;
	listaEntidades.adicionaEntidade(goblin);
	gerenciadorColisao.inimigos.push_back(goblin);

	for (int i = 0; i < 5; i++) {
		goblin->adicionaProjetil(criaProjetil());

	}
	goblin->i = goblin->projeteis.begin();

}

void Fase::criaCaixa(Coordenadaf posicao) {
	
	Caixa* caixa = new Caixa;
	caixa->setTamanho(Coordenadaf(60, 60));
	caixa->setPosicao(Coordenadaf(posicao));
	caixa->setCor(50, 50, 50);
	listaEntidades.adicionaEntidade(caixa);
	gerenciadorColisao.obstaculos.push_back(caixa);

}

void Fase::criaEsqueleto(Coordenadaf posicao) {
	
	Esqueleto* esqueleto = new Esqueleto;
	esqueleto->setTamanho(Coordenadaf(30, 30));
	esqueleto->setPosicao(Coordenadaf(posicao));
	esqueleto->setImagem("imagens/esqueleto.png");
	esqueleto->setCor(200, 0, 30);
	listaEntidades.adicionaEntidade(esqueleto);
	gerenciadorColisao.inimigos.push_back(esqueleto);

}

