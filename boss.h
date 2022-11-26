#pragma once
#include "std.h"
#include "inimigo.h"
#include "projetil.h"
#include "jogador.h"

using namespace std;

class Boss : public Inimigo {
private:
	float tempoDirecao;
	float cooldown;
	float intervaloTiro;


public:
	list<Projetil*> projeteis;
	list<Projetil*>::iterator i;

	Boss(float tempo);
	~Boss();
	Jogador* pJogador;
	void adicionaProjetil(Projetil* ptr);
	void atira();
	void executa();
	void setEstaVivo(bool vivo);
	void salvar();
	void machucaJogador(Jogador* pJogador);

};