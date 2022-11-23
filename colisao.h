#pragma once
#include "std.h"
#include "jogador.h"
#include "inimigo.h"
#include "janela.h"
#include "obstaculo.h"
#include "projetil.h"

using namespace std;

class Colisao {
public:
	Janela* janela;
	list<Jogador*> jogadores;
	list<Inimigo*> inimigos;
	list<Projetil*> projeteis;
	list<Obstaculo*> obstaculos;

	Colisao(Janela* pJanela);
	~Colisao();
	void checaColisao();
	void colisaoParede();
	void colisaoInimigo();
	void colisaoObstaculo();
	void colisaoProjetil();
	void colisaoInimigoObstaculo();
	void colisaoprojetilObstaculo();
	Coordenadaf checaColisaoEntidades(Ente* ente1, Ente* ente2);

};