#pragma once
#include "std.h"
#include "obstaculo.h"
#include "jogador.h"

class Espinho : public Obstaculo {
private:

public:

	Espinho();
	~Espinho();
	void machucaJogador(Jogador* pJogador);

};