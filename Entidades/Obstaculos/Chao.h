#pragma once

#include "Obstaculo.h"

namespace Entidades
{

namespace Obstaculos
{

class Chao : public Obstaculo
{
private:
public:
  Chao(float x = 0, float y = 0);
  ~Chao();
  virtual void executar(float dt);
  virtual void imprimir();
  virtual const int getTipo() const;
  void obstacular(Personagem* e, int dir);
};

}

}

using namespace Obstaculos;
