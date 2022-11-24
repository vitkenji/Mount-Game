#pragma once
#include "std.h"
#include "obstaculo.h"
#include "jogador.h"

class Espinho : public Obstaculo {
private:
	int dano;

public:

	Espinho();
	~Espinho();
	void prejudicaJogador(Jogador* pJogador);
	void executa();
};