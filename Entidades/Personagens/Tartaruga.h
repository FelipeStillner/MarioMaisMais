#pragma once 

#include "Inimigo.h"

namespace Entidades
{

namespace Personagens
{

class Tartaruga : public Inimigo
{
private:
  bool casco;
  int vx;
public:
  Tartaruga(float x = 0, float y = 0, int v = 0);
  ~Tartaruga();
  virtual void executar(float dt);
  virtual void imprimir();
  virtual void levarDano(int d = 1);
  int getTipo();
  virtual void danar();
};

}

}
