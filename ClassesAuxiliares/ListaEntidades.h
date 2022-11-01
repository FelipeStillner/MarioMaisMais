#pragma once

#include "../Afix.h"
#include "../Entidades/Entidade.h"
#include "../Entidades/Inimigo.h"
#include "../Entidades/Obstaculo.h"
#include "../Entidades/Projetil.h"
#include "../Entidades/Jogador.h"

class ListaEntidades
{
private:
  std::list<Inimigo*> inim;
  std::list<Obstaculo*> obst;
  std::list<Projetil*> proj;
  Jogador* jog;
public:
  ListaEntidades();
  ~ListaEntidades();
  void push(Inimigo* e);
  void push(Obstaculo* e);
  void push(Projetil* e);
  std::list<Inimigo*> getInimigos();
  std::list<Obstaculo*> getObstaculos();
  std::list<Projetil*> getProjeteis();
  void remove(Inimigo* e);
  void remove(Obstaculo* e);
  void remove(Projetil* e);
  void setJogador(Jogador* j);
  Jogador* getJogador();
  void executar(float dt);
  void imprimir(sf::RenderWindow* w);
  Entidade* operator[](int n); 
  int size();
};
