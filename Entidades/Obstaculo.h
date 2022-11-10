#pragma once

#include "Entidade.h"

namespace Entidades
{

namespace Obstaculos
{

class Obstaculo : public Entidade
{
protected:
public:
  Obstaculo(float x = 0, float y = 0, float w = 0, float h = 0, Colisao c = Colisao());
  virtual ~Obstaculo();
  virtual void executar(float dt) = 0;
  virtual void imprimir() = 0;
  virtual int getTipo() = 0;
};

}

}

using namespace Obstaculos;
