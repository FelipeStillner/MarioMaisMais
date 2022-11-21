#pragma once

#include "Obstaculo.h"
#include "../../ClassesAuxiliares/Animacao.h"

namespace Fases
{
  class Fase;
}

using namespace Fases;

namespace Entidades
{

namespace Obstaculos
{

class Bandeira : public Obstaculo
{
private:
  Fase* f;
  Animacao anim;
public:
  Bandeira(Fase* f, float x = 0, float y = 0);
  ~Bandeira();
  virtual void imprimir();
  virtual void executar(const float dt = 0);
  virtual int const getTipo() const;
  void obstacular(Personagem* e, int dir);
};

}

}

using namespace Obstaculos;
