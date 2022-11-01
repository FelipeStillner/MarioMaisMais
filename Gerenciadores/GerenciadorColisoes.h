#pragma once

#include "../Entidades/Inimigo.h"
#include "../Entidades/Obstaculo.h"
#include "../Entidades/Jogador.h"
#include "../Entidades/Projetil.h"

class Fase;

class GerenciadorColisoes
{
private:
  Fase* fase;
  std::list<Projetil*> proj;
  std::list<Inimigo*> inim;
  std::list<Obstaculo*> obst;
  Jogador* jog;
public:
  GerenciadorColisoes(Fase* f);
  ~GerenciadorColisoes();
  void executar();
  void push(Projetil* p);
  void push(Obstaculo* p);
  void push(Inimigo* p);
};
