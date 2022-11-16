#pragma once

#include "Obstaculo.h"

namespace Entidades
{

namespace Obstaculos
{

class Spike : public Obstaculo
{
private:
  int dano;
public:
  Spike(float x = 0, float y = 0, float d = 0);
  ~Spike();
  virtual void executar(float dt);
  virtual void imprimir();
  virtual int getTipo();
  int getDano();
};

}

}

using namespace Obstaculos;
