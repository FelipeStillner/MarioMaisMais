#pragma once

#include "../Afix.h"
#include "../Entidades/Entidade.h"

class ListaEntidades
{
private:
  std::list<Entidade*> lista;
public:
  ListaEntidades();
  ~ListaEntidades();
  void push(Entidade* e);
  std::list<Entidade*> getLista();
  void executar(float dt);
  void imprimir(sf::RenderWindow* w);
  Entidade* operator[](int n); 
};
