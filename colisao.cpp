#include "colisao.h"

using namespace std;

Colisao::Colisao(Janela* pJanela) {
	janela = pJanela;

}

Colisao::~Colisao() {

}

void Colisao::checaColisao() {

	const int altura = janela->getAltura();
	const int largura = janela->getLargura();

	list<Jogador*>::iterator i; //jogador
	list<Entidade*>::iterator j; //entidade estatica
	list<Entidade*>::iterator k; //entidade movel

	for (i = jogadores.begin(); i != jogadores.end(); i++) {
		(*i)->aceleracao = { 0,3000 };
		//checa colisao de jogador com entidades estaticas
		for (j = entidadesEstaticas.begin(); j != entidadesEstaticas.end(); j++) {
			Coordenadaf contato = checaColisaoEntidades(*i, *j);
			if (contato.x > 0.1 || contato.x < -0.1 || contato.y > 0.1 || contato.y < -0.1) {
				if (contato.y < -0.01) {
					(*i)->setPulo(true);
					(*i)->aceleracao = { 0,0 };
					(*i)->velocidade.y = 0;
				}

				(*i)->atualizaPosicao(contato);

			}
		}

		//checa colisao de jogador com entidades moveis
		for (k = entidadesMoveis.begin(); k != entidadesMoveis.end(); k++) {
			if ((*k)->estaVivo) {
				Coordenadaf contato = checaColisaoEntidades(*i, *k);

				if (contato.y < -0.1) { //mata inimigos se pisar em cima
					(*i)->atualizaPosicao(contato);
					(*k)->estaVivo = false;
					(*i)->pontua();

				}

				else if (contato.x > 0.1 || contato.x < -0.1 || contato.y > 0.1) {
				
					(*i)->alteraVida(1);
					cout << "vida jogador: " << (*i)->getVida() << endl;
					(*i)->velocidade.x *= -1;
					(*i)->aceleracao.x = 0;
					(*i)->atualizaPosicao(contato);

					if (!(*i)->estaVivo) {
						janela->janela.close();
						cout << "morreu" << endl;
						cout << "pontuacao: " << (*i)->getPontos() << endl;
					}
				}
			}
		}
	}


	//checa colisao de jogador com parede
	for (i = jogadores.begin(); i != jogadores.end(); i++) {

		float posicao = (*i)->getPosicao().x;
		float tamanho = (*i)->getTamanho().x / 2;

		if (tamanho > posicao) {

			Coordenadaf coordenada = Coordenadaf(tamanho - posicao, 0);
			(*i)->atualizaPosicao(coordenada);
		}
	}

	//checa colisao de entidades moveis e estaticas
	for (k = entidadesMoveis.begin(); k != entidadesMoveis.end(); k++) {
		if ((*k)->estaVivo) {
			for (j = entidadesEstaticas.begin(); j != entidadesEstaticas.end(); j++) {

				Coordenadaf contato = checaColisaoEntidades(*k, *j);

				if (contato.x > 0.1 || contato.x < -0.1 || contato.y > 0.1 || contato.y < -0.1) {
					(*k)->aceleracao.y = 0;
					(*k)->atualizaPosicao(contato);

					if (contato.x > 0.2 || contato.x < -0.2) { (*k)->velocidade *= -1; }

				}
			}
		}
	}
}

Coordenadaf Colisao::checaColisaoEntidades(Ente* pEnte1, Ente* pEnte2) {

	Coordenadaf posicaoEnte1 = pEnte1->getPosicao();
	Coordenadaf posicaoEnte2 = pEnte2->getPosicao();

	Coordenadaf tamanhoEnte1 = pEnte1->getTamanho();
	Coordenadaf tamanhoEnte2 = pEnte2->getTamanho();

	Coordenadaf soma = (tamanhoEnte1 + tamanhoEnte2) / 2;

	float distanciaX, distanciaY;

	if (posicaoEnte2.x - posicaoEnte1.x >= 0) { distanciaX = posicaoEnte2.x - posicaoEnte1.x; }

	else { distanciaX = posicaoEnte1.x - posicaoEnte2.x; }

	if (posicaoEnte2.y - posicaoEnte1.y >= 0) { distanciaY = posicaoEnte2.y - posicaoEnte1.y; }

	else { distanciaY = posicaoEnte1.y - posicaoEnte2.y; }

	float diferencaX = soma.x - distanciaX;
	float diferencaY = soma.y - distanciaY;

	bool colidiu = (soma.x >= distanciaX) && (soma.y >= distanciaY);

	if (colidiu) {
		if (diferencaY > diferencaX) {
			if (posicaoEnte1.x > posicaoEnte2.x) { return Coordenadaf(diferencaX, 0); }
			else { return Coordenadaf(-diferencaX, 0); }

		}

		else {
			if (posicaoEnte1.y > posicaoEnte2.y) { return Coordenadaf(0, diferencaY); }
			else { return Coordenadaf(0, -diferencaY); }

		}
	}
	return Coordenadaf(0, 0);

}