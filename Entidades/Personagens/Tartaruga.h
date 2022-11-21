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
  virtual void executar(const float dt);
  virtual void imprimir();
  virtual void levarDano(const int d = 1);
  const int getTipo() const;
  virtual void danar();
  void setVx(const int v);
  const int getVx() const;
};

}

}
