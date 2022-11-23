#pragma once
#include "std.h"
#include "inimigo.h"
#include "jogador.h"
#include "projetil.h"

using namespace std;

class Goblin : public Inimigo {
private:
	float intervaloTiro;
	float cooldown;

public:
	Jogador* pJogador;
	list <Projetil*> projeteis;
	list<Projetil*>::iterator i;
	Goblin();
	~Goblin();
	void adicionaProjetil(Projetil* ptr);
	void atira();
	void executa();
	void setEstaVivo(bool vivo);
};
