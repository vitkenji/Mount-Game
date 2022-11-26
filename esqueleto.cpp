#include "esqueleto.h"
#include "grafico.h"

Esqueleto::Esqueleto(float tempo):Inimigo() {
	tempoDirecao = tempo;
	cooldown = 0;

}

Esqueleto::~Esqueleto() {

}

void Esqueleto::executa() {
	cooldown += pGrafico->getDt();
	velocidade.y = 1000;
	if (cooldown >= tempoDirecao) {

		velocidade.x *= -1;
		cooldown -= tempoDirecao;

	}
	atualizaPosicao();

}

void Esqueleto::salvar() {
	ofstream arquivoEsqueleto("../salvamento/esqueleto.txt", ios_base::app);
		arquivoEsqueleto << estaVivo << ""
			<< aceleracao.x << ""
			<< aceleracao.y << ""
			<< velocidade.x << ""
			<< velocidade.y << ""
			<< posicao.x << ""
			<< posicao.y << ""
			<< tamanho.x << ""
			<< tamanho.y << ""
			<< tempoDirecao << ""
			<< cooldown << ""
			<< vida << ""
			<< endl;

		arquivoEsqueleto.close();
}

void Esqueleto::machucaJogador(Jogador* pJogador) {
	pJogador->alteraVida(3);

}