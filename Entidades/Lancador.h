#pragma once 

#include "Inimigo.h"

namespace Entidades
{

namespace Personagens
{

class Lancador : public Inimigo
{
private:
  float tLan;
public:
  Lancador(float x = 0, float y = 0, int v = 0);
  ~Lancador();
  virtual void executar(float dt);
  virtual void imprimir();
  int getTipo();
  virtual void danar();
};

}

}
