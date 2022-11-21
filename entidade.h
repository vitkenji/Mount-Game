#pragma once
#include "std.h"
#include "ente.h"
#include "grafico.h"

class Entidade :public Ente {
protected:

public:
	bool estaVivo;
	Coordenadaf velocidade;
	Coordenadaf aceleracao;
	
	Entidade();
	~Entidade();
	void setEstaVivo(bool vivo);
	void atualizaPosicao();
	void atualizaPosicao(Coordenadaf coordenada);
	virtual void executa();

};