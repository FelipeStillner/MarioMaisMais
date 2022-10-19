#pragma once

#include "Entidade.h"

class Projetil : public Entidade
{
private:
  int vx, vy;
  int dano;
public:
  Projetil(float x = 0, float y = 0, sf::Texture* t = NULL, Colisao c = Colisao(), int vx = 0, int vy = 0, int dano = 0);
  ~Projetil();
  virtual void executar(const float dt);
  virtual void imprimir(sf::RenderWindow *rw);
  const int getDano() const {return dano;};
};
