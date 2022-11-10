#include "Entidade.h"

Entidade::Entidade(float x, float y, float w, float h, Colisao c) : Ente(), col(c)
{
  this->x = x;
  this->y = y;
  this->w = w;
  this->h = h;
  x0 = x;
  y0 = y;
  vy = 0;
  setAtivo(true);
}

Entidade::~Entidade()
{
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

void Entidades::Entidade::setVy(float v)
{
  vy = v;
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

void Entidade::setAtivo(bool a)
{
  ativo = a;
}
const bool Entidade::getAtivo() const
{
  return ativo;
}

Colisao Entidade::getColisao()
{
  return col;
}