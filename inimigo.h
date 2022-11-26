#pragma once
#include "std.h"
#include "personagem.h"
#include "jogador.h"

class Inimigo : public Personagem {
private:
	int dano;

public:
	Inimigo();
	~Inimigo();
	void setDano(int dano);
	int getDano();
	virtual void machucaJogador(Jogador *pJogador);

};
