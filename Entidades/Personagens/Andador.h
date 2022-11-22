#pragma once 

#include "Inimigo.h"

namespace Entidades
{

namespace Personagens
{

class Andador : public Inimigo
{
private:
  int vx;
public:
  Andador(float x = 0, float y = 0, int v = 0);
  ~Andador();
  virtual void executar(const float dt);
  virtual void imprimir();
  int const getTipo() const;
  virtual void danar();
  virtual const int getPontuacao() const;
};

}

}
