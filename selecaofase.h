#pragma once
#include "std.h"
#include "menu.h"
#include "botao.h"

class SelecaoFase : public Menu {
private:

public:
	SelecaoFase();
	~SelecaoFase();
	int executa();
	void imprime();

};