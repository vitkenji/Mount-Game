#pragma once
#include "std.h"
#include "personagem.h"

class Jogador : public Personagem {
private:
	int pontos;
	bool podePular;

public:

	Jogador();
	~Jogador();
	void setPontos(int pontos);
	int getPontos();
	void pontua();
	void setPulo(bool pula);
	void movimenta();
	void alteraVelocidade();
	virtual void executa();

};