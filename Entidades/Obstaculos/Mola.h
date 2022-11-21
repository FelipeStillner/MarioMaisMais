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
  virtual void executar(const float dt);
  virtual void imprimir();
  virtual const int getTipo() const;
  int const getForca() const;
  void obstacular(Personagem* e, int dir);
};

}

}

using namespace Obstaculos;
