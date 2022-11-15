#pragma once

#include "Fase.h"
#include"Entidades/Andador.h"
class Fase1 : public Fase
{
private:
public:
  Andador* createAndador(float x = 0, float y = 0);

  virtual void gravaFase();
  virtual Fase* recFase();
  Fase1(Principal* p = NULL);
  ~Fase1();
};

