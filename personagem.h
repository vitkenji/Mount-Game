#pragma once
#include "std.h"
#include "entidade.h"

class Personagem : public Entidade {
protected:
	int vida;

public:
	Personagem();
	~Personagem();
	void setVida(int v);
	int getVida();
	void alteraVida(int dano);

};