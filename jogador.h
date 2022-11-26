#pragma once
#include "std.h"
#include "personagem.h"

class Jogador : public Personagem {
private:
	int id;
	int pontos;
	bool podePular;
	int teclas[4];

public:

	float velocidadeMovimento;
	float desaceleracao;

	Jogador(int id);
	~Jogador();
	void setPontos(int pontos);
	int getPontos();
	void pontua();
	void setPulo(bool pula);
	void movimenta();
	void alteraVelocidade();
	virtual void executa();
	void salvar();
};