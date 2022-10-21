#include "Projetil.h"

Projetil::Projetil(float x, float y, sf::Texture* t, Colisao c, int vx, int vy, int dano) : Entidade(x, y, t, c)
{
  this->vx = vx;
  this->vy = vy;
  this->dano = dano;
}

Projetil::~Projetil()
{
}

void Projetil::executar(const float dt)
{
  x0 = x;
  x = x + vx*dt;
  y0 = y;
  y = y + vy*dt;
  // Checar colisoes
}

void Projetil::imprimir(sf::RenderWindow *rw)
{
  sf::Sprite s(*text);
  s.setPosition(x, y);
  s.setScale(10, 10);
  rw->draw(s);
}


