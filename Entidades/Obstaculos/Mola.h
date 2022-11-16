#pragma once

#include "Obstaculo.h"

namespace Entidades
{

namespace Obstaculos
{

class Mola : public Obstaculo
{
private:
  int forca;
public:
  Mola(float x = 0, float y = 0, int f = 0);
  ~Mola();
  virtual void executar(float dt);
  virtual void imprimir();
  virtual int getTipo();
  int getForca();
};

}

}

using namespace Obstaculos;
