#pragma once
#include "std.h"
#include "ente.h"
#include "botao.h"

using namespace std;

class Menu : public Ente {
private:
	int opcao;
	int totalOpcoes;
	vector <Botao*> botoes;

public:
	Menu();
	~Menu();
	int executa();
	void imprime();

};