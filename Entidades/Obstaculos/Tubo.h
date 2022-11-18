#pragma once

#include "Obstaculo.h"

namespace Entidades
{

namespace Obstaculos
{

class Tubo : public Obstaculo
{
private:
public:
  Tubo(float x = 0, float y = 0);
  ~Tubo();
  virtual void executar(float dt);
  virtual void imprimir();
  virtual int getTipo();
};

}

}

using namespace Obstaculos;