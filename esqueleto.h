#pragma once
#include "std.h"
#include "inimigo.h"

class Esqueleto : public Inimigo {
private:

	float tempoDirecao;
	float cooldown;

public:
	Esqueleto(float tempo = 2.1 + rand()%4);
	~Esqueleto();
	void executa();
	
};