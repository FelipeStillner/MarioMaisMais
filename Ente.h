#pragma once

#include "Afix.h"

class Ente
{
protected:
  int id;
  static int nEntes;
public:
  Ente(int i = nEntes);
  virtual ~Ente();
  virtual void executar(float dt = 0) = 0;
  virtual void imprimir(sf::RenderWindow* w) = 0;
};
