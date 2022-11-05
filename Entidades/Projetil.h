#pragma once

#include "Entidade.h"

class Projetil : public Entidade
{
private:
  int vx, vy;
  int dano;
public:
  Projetil(float x = 0, float y = 0, float w = 0, float h = 0, int t = 0, Colisao c = Colisao(), float vx = 0, float vy = 0, int dano = 0);
  virtual ~Projetil();
  virtual void executar(const float dt);
  virtual void imprimir(sf::RenderWindow *rw);
  const int getDano() const;
};
