#pragma once

#include "Entidade.h"

namespace Entidades
{

namespace Obstaculos
{

class Obstaculo : public Entidade
{
protected:
  Colisao col;
public:
  Obstaculo(float x = 0, float y = 0, float w = 0, float h = 0, int t = 0, Colisao c = Colisao());
  virtual ~Obstaculo();
  virtual void executar(float dt);
  virtual void imprimir();
  int getTipo();
  Colisao getColisao();
};

}

}

using namespace Obstaculos;
