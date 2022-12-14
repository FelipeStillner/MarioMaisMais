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
  void executar(const float dt);
  void imprimir();
  const int getTipo() const;
  void obstacular(Personagem* e, int dir);
};

}

}

using namespace Obstaculos;
