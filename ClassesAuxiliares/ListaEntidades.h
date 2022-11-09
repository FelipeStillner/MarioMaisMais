#pragma once

#include "../Afix.h"
#include "../Entidades/Entidade.h"
#include "Lista.h"

using namespace Entidades;

namespace ClassesAuxiliares
{

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
  void imprimir();
  Entidade* operator[](int n); 
  int size();
};

}
