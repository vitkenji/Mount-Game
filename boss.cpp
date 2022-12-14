#include "boss.h"

using namespace std;

Boss::Boss(float tempo):Inimigo() {

	tempoDirecao = tempo;
	cooldown = 1;
	intervaloTiro = 0;
	pJogador = nullptr;

}

Boss::~Boss() {
	list<Projetil*>::iterator i;
	for (i = projeteis.begin(); i != projeteis.end(); i++) {
		delete(*i);

	}
}

void Boss::atira() {
	Projetil* pProjetil;
	if (i == projeteis.end()) {
		pProjetil = *(projeteis.begin());
		i = projeteis.begin();

	}

	else {
		pProjetil = *(i++);
		i = i++;

	}

	pProjetil->estaVivo = true;
	pProjetil->velocidade = Coordenadaf(0, 0);
	pProjetil->setPosicao(this->getPosicao());
	if (this->getPosicao().x > pJogador->getPosicao().x) {
		pProjetil->velocidade.x = -600;

	}
	else { pProjetil->velocidade.x = 600; }

}

void Boss::executa() {
	
	cooldown += pGrafico->getDt();
	velocidade.y = 1000;
	if (cooldown >= tempoDirecao) {

		velocidade.x *= -1;
		cooldown -= tempoDirecao;

	}
	atualizaPosicao();

	intervaloTiro += pGrafico->getDt();

	float distanciay;
	if (pJogador->getPosicao().y - this->getPosicao().y > 0) {
		distanciay = pJogador->getPosicao().y - this->getPosicao().y;

	}
	else { distanciay = this->getPosicao().y - pJogador->getPosicao().y; }

	if (!pJogador->getEstaVivo()) { return; }

	if (pJogador->getPosicao().y + pJogador->getTamanho().y / 2 > this->getPosicao().y) {
		if (intervaloTiro > cooldown) {

			intervaloTiro = 0;
			atira();

		}
	}
}

void Boss::adicionaProjetil(Projetil* ptr) {
	projeteis.push_back(ptr);

}

void Boss::setEstaVivo(bool vivo) {
	this->estaVivo = vivo;
	estaVivo = vivo;

}

void Boss::salvar() {
	ofstream arquivoBoss("../salvamento/boss.txt", ios_base::app);
	
	arquivoBoss << estaVivo << ""
		<< aceleracao.x << ""
		<< aceleracao.y << ""
		<< velocidade.x << ""
		<< velocidade.y << ""
		<< tamanho.x << ""
		<< tamanho.y << ""
		<< posicao.x << ""
		<< posicao.y << ""
		<< vida << ""
		<< intervaloTiro << ""
		<< tempoDirecao << ""
		<< cooldown << ""
		<< endl;

	arquivoBoss.close();
	
	list<Projetil*>::iterator j;
	for (j = i; j != i; j++) {

		(*j)->salvar();
		if (j == projeteis.end()) { j = projeteis.begin(); }

	}

}

void Boss::machucaJogador(Jogador* pJogador){
	pJogador->alteraVida(10);

}