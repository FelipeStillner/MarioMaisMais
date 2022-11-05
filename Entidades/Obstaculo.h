#pragma once

#include "Entidade.h"

class Obstaculo : public Entidade
{
protected:
public:
  Obstaculo(float x = 0, float y = 0, float w = 0, float h = 0, int t = 0, Colisao c = Colisao());
  virtual ~Obstaculo();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow *rw);
};
