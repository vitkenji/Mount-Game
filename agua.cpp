#include "agua.h"

Agua::Agua():Obstaculo(){
	retardo = 0.21;

}

Agua::~Agua(){}

void Agua::executa() {
	atualizaPosicao();
}

void Agua::prejudicaJogador(Jogador* pJogador){
	if (pJogador->desaceleracao < 0.05) {
		pJogador->velocidadeMovimento *= retardo;

	}
	pJogador->desaceleracao = 0.2;
}

void Agua::salvar() {
	
	ofstream arquivoAgua("../salvamento/agua.txt", ios_base::app);

	arquivoAgua << estaVivo << ""
		<< tamanho.x << ""
		<< tamanho.y << ""
		<< posicao.x << ""
		<< posicao.y << ""
		<< velocidade.x << ""
		<< velocidade.y << ""
		<< aceleracao.x << ""
		<< aceleracao.y << ""
		<< retardo << ""
		<< endl;

	arquivoAgua.close();

}


