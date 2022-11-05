#include "Projetil.h"

Projetil::Projetil(GerenciadorGrafico* g, float x, float y, float w, float h, Colisao c, float vx, float vy, int dano) : Entidade(g, x, y, w, h, c)
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
}

void Projetil::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gGraf)[1]);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gGraf->getWindow()->draw(r);
}

const int Projetil::getDano() const 
{
  return dano;
}


