#pragma once

#include "Jogador.h"

namespace Entidades
{

namespace Personagens
{

class Luigi : public Jogador
{
private:
public:
  Luigi(float x = 0, float y = 0, int v = 0);
  ~Luigi();
  virtual void imprimir();
};

}

}

using namespace Personagens;
