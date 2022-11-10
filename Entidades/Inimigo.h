#pragma once 

#include "Personagem.h"

namespace Entidades
{

namespace Personagens
{

class Inimigo : public Personagem
{
private:
public:
  Inimigo(float x = 0, float y = 0, int v = 0);
  ~Inimigo();
  virtual void executar(float dt);
  virtual void imprimir();
  int getTipo();
};

}

}
