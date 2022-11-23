#pragma once
#include "std.h"
#include "inimigo.h"

class Esqueleto : public Inimigo {
private:

	float tempoDirecao;
	float cooldown;

public:
	Esqueleto();
	~Esqueleto();
	void executa();
	
};