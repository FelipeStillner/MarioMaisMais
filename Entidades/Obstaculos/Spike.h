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
  void executar(const float dt);
  void imprimir();
  const int getTipo() const;
  const int getDano() const;
  void obstacular(Personagem* e, int dir);
};

}

}

using namespace Obstaculos;
