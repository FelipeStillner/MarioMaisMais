#include "Entidade.h"

Entidade::Entidade(float x, float y, float w, float h, int t, Colisao c) : Ente(), col(c)
{
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  x0 = x;
  y0 = y;
  setTextura(t);
  vy = 0;
}

Entidade::~Entidade()
{
}

void Entidade::setColisao(Colisao c)
{
  col = c;
}

void Entidade::setTextura(/*sf::Texture* t*/ int t)
{

  //text = t;
  text = (*gG)[t];
}

void Entidade::setX(float x)
{
  this->x = x;
}

void Entidade::setY(float y)
{
  this->y = y;
}

void Entidade::setXX0(float x)
{
  x0 = this->x;
  this->x = x;
}

void Entidade::setYY0(float y)
{
  y0 = this->y;
  this->y = y;
}

void Entidade::setVy(float v)
{
  vy = v;
}

const Colisao Entidade::getColisao() const 
{
  return col;
}

const sf::Texture* Entidade::getTextura() const 
{
  return text;
}

const float Entidade::getX() const
{
  return x;
}

const float Entidade::getY() const
{
  return y;
}

const float Entidade::getX0() const
{
  return x0;
}

const float Entidade::getY0() const
{
  return y0;
}

const float Entidade::getVy() const
{
  return vy;
}