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
	void criaInimigos();
	void criaCenario();
};
