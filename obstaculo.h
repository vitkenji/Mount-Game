#pragma once
#include "std.h"
#include "entidade.h"
#include "jogador.h"

class Obstaculo : public Entidade {
protected:
	int forca;

public:
	Obstaculo();
	~Obstaculo();
	virtual void prejudicaJogador(Jogador* pJogador);
	void executa();
	void setForca(int forca);
	int getForca();
	
};
