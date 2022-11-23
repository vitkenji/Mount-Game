#pragma once
#include "std.h"
#include "inimigo.h"
#include "projetil.h"
#include "jogador.h"

using namespace std;

class Boss : public Inimigo {
private:
	float cooldown;
	float intervaloTiro;

public:
	list<Projetil*> projeteis;
	list<Projetil*>::iterator i;

	Boss();
	~Boss();
	Jogador* pJogador;
	void adicionaProjetil(Projetil* ptr);
	void atira();
	void executa();
	void setEstaVivo(bool vivo);

};