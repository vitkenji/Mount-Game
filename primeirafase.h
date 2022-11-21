#pragma once
#include "std.h"
#include "fase.h"
#include "esqueleto.h"
#include "goblin.h"
#include "caixa.h"
#include "espinho.h"

class PrimeiraFase : public Fase {
private:

public:
	PrimeiraFase(Janela* pJanela, Grafico* pGrafico);
	~PrimeiraFase();
	void executar();
	void criaCenario();
	void criaInimigos();
};