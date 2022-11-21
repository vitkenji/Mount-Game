#pragma once
#include "std.h"
#include "lista.h"
#include "entidade.h"

class ListaEntidade {
private:
	Lista<Entidade> lista;

public:
	ListaEntidade();
	~ListaEntidade();
	void adicionaEntidade(Entidade* pEntidade);
	void inicializaEntidades();
	void executaEntidades();
};