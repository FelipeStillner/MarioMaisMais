#include "Entidade.h"

Entidade::Entidade(float x, float y, float w, float h, Colisao c) : Ente(), Colisao(c)
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

void Entidade::setX(const float x)
{
  this->x = x;
}

void Entidade::setY(const float y)
{
  this->y = y;
}

void Entidade::setXX0(const float x)
{
  x0 = this->x;
  this->x = x;
}

void Entidade::setYY0(const float y)
{
  y0 = this->y;
  this->y = y;
}

void Entidades::Entidade::setVy(const float v)
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

void Entidade::setAtivo(const bool a)
{
  ativo = a;
}
const bool Entidade::getAtivo() const
{
  return ativo;
}

const Colisao Entidade::getColisao() const 
{
  return static_cast<Colisao>(*this);
}