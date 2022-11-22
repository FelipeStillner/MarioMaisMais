#pragma once 

#include "Inimigo.h"
#include "Tartaruga.h"

namespace Fases
{
  class Fase2;
}

using namespace Fases;

namespace Entidades
{

namespace Personagens
{

class Bowser : public Inimigo
{
private:
  Fase2* f;
  Tartaruga* t;
  float tProj;
public:
  Bowser(Fase2* f, float x = 0, float y = 0, int v = 0);
  ~Bowser();
  virtual void executar(const float dt);
  virtual void imprimir();
  virtual void levarDano(const int d = 1);
  virtual const int getTipo() const;
  virtual void danar();
  virtual const int getPontuacao() const;
};

}

}
