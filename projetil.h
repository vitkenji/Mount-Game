#pragma once
#include "std.h"
#include "entidade.h"

class Projetil : public Entidade {
private:
	int dano;


public:
	Projetil();
	~Projetil();
};