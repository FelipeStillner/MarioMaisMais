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
  void executar(const float dt = 0);
  void imprimir();
  const int getTipo() const;
  int const getForca() const;
  void obstacular(Personagem* e, int dir);
};

}

}

using namespace Obstaculos;
