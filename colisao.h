#pragma once
#include "std.h"
#include "jogador.h"
#include "inimigo.h"
#include "janela.h"
#include "obstaculo.h"

using namespace std;

class Colisao {
public:
	Janela* janela;
	list <Jogador*> jogadores;
	list <Entidade*> entidadesEstaticas;
	list <Entidade*> entidadesMoveis;

	Colisao(Janela* pJanela);
	~Colisao();
	void checaColisao();
	Coordenadaf checaColisaoEntidades(Ente* ente1, Ente* ente2);

};