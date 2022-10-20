#include "Entidade.h"

Entidade::Entidade(float x, float y, sf::Texture* t, Colisao c) : Ente(), col(c)
{
  this->x = x;
  this->y = y;
  text = t;
}

Entidade::~Entidade()
{
}

void Entidade::setColisao(Colisao c)
{
  col = c;
}

void Entidade::setTextura(sf::Texture* t)
{
  text = t;
}

void Entidade::setX(int x)
{
  x0 = this->x;
  this->x = x;
}

void Entidade::setY(int y)
{
  y0 = this->y;
  this->y = y;
}

const Colisao Entidade::getColisao() const 
{
  return col;
}

const sf::Texture* Entidade::getTextura() const 
{
  return text;
}

const int Entidade::getX() const
{
  return x;
}

const int Entidade::getY() const
{
  return y;
}

const int Entidade::getX0() const
{
  return x0;
}

const int Entidade::getY0() const
{
  return y0;
}
