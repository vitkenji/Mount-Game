#pragma once
#include "std.h"
#include "obstaculo.h"

class Caixa : public Obstaculo {
private:
public:
	Caixa();
	~Caixa();
	void executa();
	void prejudicaJogador(Jogador* pJogador);
	void salvar();
};