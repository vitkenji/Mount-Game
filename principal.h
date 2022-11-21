#pragma once
#include "std.h"
#include "grafico.h"
#include "janela.h"
#include "jogador.h"
#include "primeirafase.h"
#include "segundafase.h"
#include "menu.h"

class Principal {
private:
	PrimeiraFase fase1;
	SegundaFase fase2;
	Menu menu;
	Grafico* grafico;
	Janela janela;
	Jogador jogador;

public:
	Principal();
	~Principal();
	void executar();
};
