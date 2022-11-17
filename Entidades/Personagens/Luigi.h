#pragma once

#include "Jogador.h"

namespace Entidades
{

namespace Personagens
{

class Luigi : public Jogador
{
private:
  int estado;
  float tProj;
public:
  Luigi(float x = 0, float y = 0, int v = 0);
  ~Luigi();
  virtual void imprimir();
  void setEstado(const int est);
};

}

}

using namespace Personagens;

#define IDLE 0
#define WALKR 1
#define WALKL 2
#define JUMP 3