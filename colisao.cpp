#include "colisao.h"

using namespace std;

Colisao::Colisao(Janela* pJanela) {
	janela = pJanela;

}

Colisao::~Colisao() {

}

void Colisao::checaColisao() {

	colisaoInimigo();
	colisaoParede();
	colisaoObstaculo();
	colisaoProjetil();
	colisaoInimigoObstaculo();
	colisaoprojetilObstaculo();

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

void Colisao::colisaoInimigo() {
	
	list<Jogador*>::iterator i;
	list<Inimigo*>::iterator j;
	
	for (i = jogadores.begin(); i != jogadores.end(); i++) {
		(*i)->aceleracao.y = 1000;
		
		for (j = inimigos.begin(); j != inimigos.end(); j++) {
			
			if ((*j)->estaVivo) {

				Coordenadaf contato = checaColisaoEntidades(*i, *j);
				if (contato.y < -0.1 && (*i)->velocidade.y > 0.1) {
					(*i)->atualizaPosicao(contato);
					(*i)->pontua();
					(*j)->alteraVida(10);

				}
				else if (contato.x > 0.1 || contato.x < -0.1 || contato.y > 0.1) {
					(*j)->machucaJogador(*i);
					cout << "vida jogador: " << (*i)->getVida() << endl;
					(*i)->velocidade.x *= -1;
					(*i)->aceleracao.x = 0;
					(*i)->atualizaPosicao();
				
					if (!(*i)->estaVivo) {
						janela->janela.close();
						cout << "morreu" << endl;
						cout << "pontuacao: " << (*i)->getPontos() << endl;
					}
				}
			}
		}
	}
}

void Colisao::colisaoObstaculo() {

	list<Jogador*>::iterator i;
	list<Obstaculo*>::iterator j;
	
	for (i = jogadores.begin(); i != jogadores.end(); i++) {
		(*i)->aceleracao.y = 1000;
		for (j = obstaculos.begin(); j != obstaculos.end(); j++) {

			Coordenadaf contato = checaColisaoEntidades(*i, *j);

			if (contato.x > 0.1 || contato.x < -0.1 || contato.y > 0.1 || contato.y < -0.1) {
				if (contato.y < -0.01) {
					(*i)->setPulo(true);
					(*i)->aceleracao = { 0,0 };
					(*i)->velocidade.y = 0;
					(*j)->prejudicaJogador((*i));
					cout << "vida: " << (*i)->getVida() << endl;

					if (!(*i)->estaVivo) {
						janela->janela.close();
						cout << "morreu" << endl;
						cout << "pontuacao: " << (*i)->getPontos() << endl;
					}
				}

				(*i)->atualizaPosicao(contato);

			}
		}
	}
}

void Colisao::colisaoProjetil() {
	
	list<Jogador*>::iterator i;
	list<Projetil*>::iterator j;

	for (i = jogadores.begin(); i != jogadores.end(); i++) {

		(*i)->aceleracao = Coordenadaf(0, 1000);
		
		for (j = projeteis.begin(); j != projeteis.end(); j++) {
			
			
			if ((*j)->estaVivo) {
				Coordenadaf contato = checaColisaoEntidades(*i, *j);

				if (contato.x > 0.1 || contato.x < -0.1 || contato.y > 0.1 || contato.y < -0.1) {
					(*i)->alteraVida((*j)->getDano());


					if (!(*i)->estaVivo) {
						janela->janela.close();
						cout << "morreu" << endl;
						cout << "pontuacao: " << (*i)->getPontos() << endl;
					}
					return;

				}
			}
		}
	}
}

void Colisao::colisaoParede() {
	
	const int largura = janela->getLargura();
	const int altura = janela->getAltura();
	list<Jogador*>::iterator i;

	for (i = jogadores.begin(); i != jogadores.end(); i++) {
		float tamanho = (*i)->getTamanho().x / 2;
		float posicao = (*i)->getPosicao().x;

		if (tamanho > posicao) {
			Coordenadaf coordenada = Coordenadaf(tamanho - posicao, 0);
			(*i)->atualizaPosicao(coordenada);

		}
	}
}

void Colisao::colisaoprojetilObstaculo() {

	list<Projetil*>::iterator i;
	list<Obstaculo*>::iterator j;

	for (i = projeteis.begin(); i != projeteis.end(); i++) {
		if ((*i)->estaVivo) {
			
			(*i)->aceleracao.y = 1000;
			for (j = obstaculos.begin(); j != obstaculos.end(); j++) {
				Coordenadaf contato = checaColisaoEntidades(*i, *j);

				if (contato.x > 0.1 || contato.x < -0.1 || contato.y > 0.1 || contato.y < -0.1) {
					(*i)->atualizaPosicao(contato);
					if (contato.y < 0.01) {
						(*i)->aceleracao.y = 0;
						(*i)->velocidade.y = 0;
						(*i)->atualizaPosicao();

					}
				}
			}
		}
	}
}

void Colisao::colisaoInimigoObstaculo() {
	
	list<Inimigo*>::iterator i;
	list<Obstaculo*>::iterator j;

	for (i = inimigos.begin(); i != inimigos.end(); i++) {
		if ((*i)->estaVivo) {

			(*i)->aceleracao.y = 1000;

			for (j = obstaculos.begin(); j != obstaculos.end(); j++) {
				Coordenadaf contato = checaColisaoEntidades(*i, *j);

				if (contato.x > 0.1 || contato.x < -0.1 || contato.y > 0.1 || contato.y < -0.1) {
					(*i)->atualizaPosicao(contato);

				}
				if (contato.y < 0.01) {

					(*i)->aceleracao.y = 0;
					(*i)->velocidade.y = 0;

				}
			}
		}
	}
}
