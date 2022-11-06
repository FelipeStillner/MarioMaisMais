#pragma once

#include "../Entidades/Inimigo.h"
#include "../Entidades/Obstaculo.h"
#include "../Entidades/Jogador.h"
#include "../Entidades/Projetil.h"

class Fase;

class GerenciadorColisoes
{
private:
  Jogador* jog;
  Jogador* jog2;
  std::list<Projetil*> proj;
  std::list<Inimigo*> inim;
  std::list<Obstaculo*> obst;
public:
  GerenciadorColisoes();
  ~GerenciadorColisoes();
  void executar();
  void incluir(Jogador* j);
  void incluir(Projetil* p);
  void incluir(Inimigo* i);
  void incluir(Obstaculo* o);
};
