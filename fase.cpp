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
	Entidade* chao = new Entidade;
	chao->setPosicao(Coordenadaf(0, 705));
	chao->setTamanho({ 4000,30 });
	chao->setCor(0, 210, 10);
	listaEntidades.adicionaEntidade(chao);
	gerenciadorColisao.entidadesEstaticas.push_back(chao);

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
	listaEntidades.inicializaEntidades();
	gerenciadorGrafico->display();

}

Projetil* Fase::criaProjetil() {

	Projetil* pProjetil = new Projetil;
	pProjetil->setTamanho(Coordenadaf(5,5));
	pProjetil->corpo.setFillColor(sf::Color::Yellow);
	listaEntidades.adicionaEntidade(pProjetil);
	gerenciadorColisao.entidadesMoveis.push_back((Entidade*)pProjetil);
	return pProjetil;

}

void Fase::criaEspinho(Coordenadaf posicao) {

	Espinho* espinho = new Espinho;
	espinho->setTamanho(Coordenadaf(100,20));
	espinho->setPosicao(Coordenadaf(posicao));
	listaEntidades.adicionaEntidade(espinho);
	gerenciadorColisao.entidadesEstaticas.push_back(espinho);

}

void Fase::criaGoblin(Coordenadaf posicao) {

	Goblin* goblin = new Goblin;
	goblin->setTamanho(Coordenadaf(30,30));
	goblin->setPosicao(Coordenadaf(posicao));
	listaEntidades.adicionaEntidade(goblin);
	gerenciadorColisao.entidadesMoveis.push_back(goblin);

}

void Fase::criaCaixa(Coordenadaf posicao) {
	
	Caixa* caixa = new Caixa;
	caixa->setTamanho(Coordenadaf(60, 60));
	caixa->setPosicao(Coordenadaf(posicao));
	listaEntidades.adicionaEntidade(caixa);
	gerenciadorColisao.entidadesEstaticas.push_back(caixa);

}

void Fase::criaEsqueleto(Coordenadaf posicao) {
	
	Esqueleto* esqueleto = new Esqueleto;
	esqueleto->setTamanho(Coordenadaf(30, 30));
	esqueleto->setPosicao(Coordenadaf(posicao));
	esqueleto->setImagem("imagens/esqueleto.png");
	esqueleto->setCor(200, 0, 30);
	listaEntidades.adicionaEntidade(esqueleto);
	gerenciadorColisao.entidadesMoveis.push_back(esqueleto);

}

