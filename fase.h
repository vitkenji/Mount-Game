#pragma once
#include "std.h"
#include "ente.h"
#include "colisao.h"
#include "grafico.h"
#include "listaentidade.h"
#include "janela.h"
#include "goblin.h"
#include "esqueleto.h"
#include "espinho.h"
#include "caixa.h"

class Fase : public Ente {
protected:
	Colisao gerenciadorColisao;
	Grafico* gerenciadorGrafico;
	ListaEntidade listaEntidades;
	Janela* pJanela;
	Jogador* pJogador;

public:
	Fase(Janela* pJanela, Grafico* pGrafico);
	~Fase();
	Projetil* criaProjetil();
	void gerenciaColisao();
	void criaJogador();
	void criaChao();
	void atualizaJogo();
	void criaCaixa(Coordenadaf posicao);
	void criaEspinho(Coordenadaf posicao);
	void criaEsqueleto(Coordenadaf posicao);
	void criaGoblin(Coordenadaf posicao);

};