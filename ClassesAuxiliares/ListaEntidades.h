#pragma once

#include "../Afix.h"
#include "../Entidades/Entidade.h"
#include "Lista.h"

using namespace Entidades;

namespace ClassesAuxiliares
{

namespace Listas
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
  void executar(const float dt);
  void imprimir();
  Entidade* operator[](const int n); 
  const int size();
  void limpaLista();
};

}

}

using namespace Listas;
