#include "Projetil.h"

Projetil::Projetil(float x, float y, float vx, float vy, int dano) : Entidade(x, y, 80, 80, Colisao(10, 10, 60, 60))
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
  y += vy;
  vy += 2;
}

void Projetil::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[1]);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

const int Projetil::getDano() const 
{
  return dano;
}

int Projetil::getTipo()
{
  return PROJ;
}
