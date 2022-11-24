#pragma once

#include "Fase.h"
#include "../Entidades/Personagens/Andador.h"

namespace Fases
{

class Fase1 : public Fase
{
private:
public:
  Fase1();
  ~Fase1();
  Andador* createAndador(float x = 0, float y = 0);
  void gravaFase();
  Fase* recFase();
  int getTipo();
};

}
