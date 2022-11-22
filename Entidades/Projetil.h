#pragma once

#include "Entidade.h"

namespace Entidades
{

class Projetil : public Entidade
{
private:
  int vx;
  int dano;
  char jogJog;
public:
  Projetil(float x = 0, float y = 0, float vx = 0, float vy = 0, int dano = 0);
  virtual ~Projetil();
  virtual void executar(const float dt);
  virtual void imprimir();
  const int getDano() const;
  int const getTipo() const;
  void setVx(const int vx);
  int const getVx() const;
  void setjogJog(const char vx);
  const char getjogJog() const;
};

}
