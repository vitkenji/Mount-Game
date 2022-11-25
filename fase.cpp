#include "fase.h"

using namespace std;

Fase::Fase(Janela* pJanela) :
	gerenciadorColisao(pJanela), listaEntidades(), pJanela(pJanela) {

	gerenciadorGrafico = nullptr;
	gerenciadorGrafico = Grafico::getInstance();
	Ente::pGrafico = Grafico::getInstance();

	criaJogador();
	criaPontos();
	//criaVida();

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
	chao->setImagem("imagens/chao.png");
	//chao->setCor(0, 210, 10);
	listaEntidades.adicionaEntidade(chao);
	gerenciadorColisao.obstaculos.push_back(chao);

}

void Fase::criaJogador() {


	Obstaculo* background = new Obstaculo;
	background->setTamanho(Coordenadaf(1080, 720));
	background->setPosicao(Coordenadaf(540, 360));
	background->setImagem("imagens/background.jpg");
	listaEntidades.adicionaEntidade(background);

	Obstaculo* chao = new Obstaculo;
	chao->setPosicao(Coordenadaf(0, 705));
	chao->setTamanho({ 4000,30 });
	chao->setImagem("imagens/chao.png");
	//chao->setCor(0, 210, 10);
	listaEntidades.adicionaEntidade(chao);
	gerenciadorColisao.obstaculos.push_back(chao);

	pJogador = new Jogador;
	pJogador->setPosicao(Coordenadaf(0, 0));
	pJogador->setTamanho(Coordenadaf(45, 45));
	pJogador->setPontos(0);
	pJogador->setImagem("imagens/player.png");
	listaEntidades.adicionaEntidade(pJogador);
	gerenciadorColisao.jogadores.push_back(pJogador);

}

void Fase::atualizaJogo() {

	gerenciadorGrafico->atualizaDt();
	listaEntidades.executaEntidades();
	gerenciadorColisao.checaColisao();
	gerenciadorGrafico->clear();
	listaEntidades.inicializaEntidades();
	gerenciadorGrafico->imprimeHud(pontos);
	gerenciadorGrafico->imprimeHud(vida);
	gerenciadorGrafico->display();

}

Projetil* Fase::criaProjetil() {

	Projetil* pProjetil = new Projetil;
	pProjetil->setTamanho(Coordenadaf(7,7));
	pProjetil->corpo.setFillColor(sf::Color::Yellow);
	listaEntidades.adicionaEntidade(pProjetil);
	gerenciadorColisao.projeteis.push_back(pProjetil);
	return pProjetil;

}

void Fase::criaEspinho(Coordenadaf posicao) {

	Espinho* espinho = new Espinho;
	espinho->setTamanho(Coordenadaf(100,20));
	espinho->setPosicao(Coordenadaf(posicao));
	espinho->setCor(200, 50, 50);
	listaEntidades.adicionaEntidade(espinho);
	gerenciadorColisao.obstaculos.push_back(espinho);

}

void Fase::criaGoblin(Coordenadaf posicao) {

	Goblin* goblin = new Goblin;
	goblin->setTamanho(Coordenadaf(40,40));
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

void Fase::criaCaixa(Coordenadaf posicao) {
	
	Caixa* caixa = new Caixa;
	caixa->setTamanho(Coordenadaf(60, 60));
	caixa->setPosicao(Coordenadaf(posicao));
	caixa->setImagem("imagens/caixa.png");
	listaEntidades.adicionaEntidade(caixa);
	gerenciadorColisao.obstaculos.push_back(caixa);

}

void Fase::criaBoss(Coordenadaf posicao, float tempo) {
	Boss* boss = new Boss(rand()%6 + 2);
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

void Fase::criaEsqueleto(Coordenadaf posicao, float tempo) {
	
	srand(time(NULL));
	Esqueleto* esqueleto = new Esqueleto(tempo);
	esqueleto->setTamanho(Coordenadaf(40, 40));
	esqueleto->setPosicao(Coordenadaf(posicao));
	esqueleto->setImagem("imagens/esqueleto.png");
	esqueleto->velocidade.x = 60;
	listaEntidades.adicionaEntidade(esqueleto);
	gerenciadorColisao.inimigos.push_back(esqueleto);

}

void Fase::criaAgua(Coordenadaf(posicao)){
	
	Agua* agua = new Agua;
	agua->setTamanho(Coordenadaf(80, 20));
	agua->setPosicao(Coordenadaf(posicao));
	agua->setImagem("imagens/agua.png");
	listaEntidades.adicionaEntidade(agua);
	gerenciadorColisao.obstaculos.push_back(agua);

}

void Fase::criaPontos() {

	sf::Font* ptr = new sf::Font;

	if (!ptr->loadFromFile("m5x7.ttf")) {
		delete ptr;
		return;

	}

	if (pontos.getFont()) { delete pontos.getFont(); }

	pontos.setFont(*ptr);
	pontos.setPosition(20, 20);
	pontos.setString("Pontuacao:");

}

void Fase::criaVida() {
	sf::Font* ptr = new sf::Font;

	if (!ptr->loadFromFile("m5x7.ttf")) {
		delete ptr;
		return;

	}

	if (pontos.getFont()) { delete pontos.getFont(); }

	vida.setFont(*ptr);
	vida.setPosition(800, 20);
	vida.setString("Vida restante:");

}