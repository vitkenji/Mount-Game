#pragma once
#include "std.h"
#include "agua.h"
#include "ente.h"
#include "colisao.h"
#include "grafico.h"
#include "listaentidade.h"
#include "janela.h"
#include "goblin.h"
#include "esqueleto.h"
#include "espinho.h"
#include "caixa.h"
#include "boss.h"

class Fase : public Ente {
protected:
	Colisao gerenciadorColisao;
	Grafico* gerenciadorGrafico;
	ListaEntidade listaEntidades;
	Janela* pJanela;
	Jogador* pJogador;
	sf::Text pontos;
	sf::Text vida;
public:
	
	Fase(Janela* pJanela);
	~Fase();
	Projetil* criaProjetil();
	void gerenciaColisao();
	void criaJogador();
	void criaChao();
	void atualizaJogo();
	void criaCaixa(Coordenadaf posicao);
	void criaEspinho(Coordenadaf posicao);
	void criaEsqueleto(Coordenadaf posicao, float tempo);
	void criaGoblin(Coordenadaf posicao);
	void criaBoss(Coordenadaf posicao, float tempo);
	void criaAgua(Coordenadaf(posicao));
	void criaPontos();
	void criaVida();
};