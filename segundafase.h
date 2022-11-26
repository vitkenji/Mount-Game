#pragma once
#include "std.h"
#include "fase.h"
#include "boss.h"

class SegundaFase : public Fase {
private:
public:
	
	SegundaFase(Janela* pJanela);
	~SegundaFase();
	void executar();
	void criaBoss(Coordenadaf posicao, float tempo);
	void criaInimigos();
	void criaCenario();
};
