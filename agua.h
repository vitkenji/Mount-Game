#pragma once
#include "std.h"
#include "obstaculo.h"
#include "jogador.h"

class Agua : public Obstaculo {
private:
	float retardo;

public:
	Agua();
	~Agua();
	void executa();
	void prejudicaJogador(Jogador* pJogador);
	
};