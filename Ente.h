#pragma once

#include "Afix.h"

class Ente
{
public:
  int id;
public:
  Ente();
  Ente(int i);
  virtual ~Ente();
  virtual void executar(float dt) = 0;
  virtual void imprimir(sf::RenderWindow* w) = 0;
};
