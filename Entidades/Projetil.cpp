#include "Projetil.h"

Projetil::Projetil(float x, float y, float vx, float vy, int dano) : Entidade(x, y, 80, 80, Colisao(10, 10, 60, 60))
{
  this->vx = vx;
  this->vy = vy;
  this->dano = dano;
  jogJog = false;
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
  vy += Grav;
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

const int Projetil::getTipo() const
{
  return PROJ;
}

void Projetil::setVx(const int vx)
{
  this->vx = vx;
}

const int Projetil::getVx() const
{
  return vx;
}

void Projetil::setjogJog(const char n)
{
  jogJog = n;
}

const char Projetil::getjogJog() const
{
  return jogJog;
}
