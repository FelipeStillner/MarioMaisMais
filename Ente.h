#pragma once

#include "Afix.h"

class Ente
{
protected:
  int id;
  static int nEntes;
public:
  Ente();
  Ente(int i);
  virtual ~Ente();
  virtual void executar(float dt) = 0;
  virtual void imprimir(sf::RenderWindow* w) = 0;
};
