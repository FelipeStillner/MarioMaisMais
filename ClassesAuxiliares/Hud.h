#pragma once

#include "../Ente.h"

namespace Fases
{
  class Fase;
}

using namespace Fases;

namespace ClassesAuxiliares
{

class Hud : public Ente
{
private:
  Fase* f;
public:
  Hud(Fase* f);
  ~Hud();
  virtual void imprimir();
  virtual void executar(float dt = 0);
};

}

using namespace ClassesAuxiliares;

