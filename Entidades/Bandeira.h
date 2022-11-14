#pragma once

#include "Obstaculo.h"
#include "../ClassesAuxiliares/Animacao.h"

namespace Entidades
{

namespace Obstaculos
{

class Bandeira : public Obstaculo
{
private:
  Animacao anim;
public:
  Bandeira(float x = 0, float y = 0);
  ~Bandeira();
  virtual void imprimir();
  virtual void executar(float dt = 0);
  virtual int getTipo();
};

}

}

using namespace Obstaculos;
