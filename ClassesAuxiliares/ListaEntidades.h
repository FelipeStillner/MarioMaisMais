#pragma once

#include "../Afix.h"
#include "../Entidades/Entidade.h"
#include "Lista.h"

class ListaEntidades
{
private:
  Lista<Entidade> entidades;
public:
  ListaEntidades();
  ~ListaEntidades();
  void push(Entidade* e);
  Lista<Entidade>* getEntidades();
  void remove(Entidade* e);
  void executar(float dt);
  void imprimir(sf::RenderWindow* w);
  Entidade* operator[](int n); 
  int size();
};
