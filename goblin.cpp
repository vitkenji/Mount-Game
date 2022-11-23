#include "goblin.h"
#include "grafico.h"

using namespace std;

Goblin::Goblin() :Inimigo() {
	pJogador = nullptr;
	intervaloTiro = 0;
	cooldown = 1;

}

Goblin::~Goblin() {
	delete(pJogador);
}

void Goblin::adicionaProjetil(Projetil *ptr) {
	projeteis.push_back(ptr);

}

void Goblin::atira() {
	Projetil* ptr;
	if (i == projeteis.end()) {
		ptr = *(projeteis.begin());
		i = projeteis.begin();

	}

	else {
		ptr = *(i++);
		i = i++;

	}
	ptr->estaVivo = true;
	ptr->velocidade = Coordenadaf(0, 0);
	ptr->setPosicao(this->getPosicao());

	if (this->getPosicao().x > pJogador->getPosicao().x) {
		ptr->velocidade.x = -600;

	}
	else { ptr->velocidade.x = 600; }

}

void Goblin::executa() {
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

