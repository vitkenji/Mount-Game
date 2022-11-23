#include "boss.h"

using namespace std;

Boss::Boss():Inimigo() {
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