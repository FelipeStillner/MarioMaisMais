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

void Entidade::imprimir(sf::RenderWindow *rw)
{
  sf::Sprite s(*text);
  s.setPosition(x, y);
  s.setScale(10, 10);
  rw->draw(s);
}

void Entidade::executar(float dt)
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
  this->x = x;
}

void Entidade::setY(int y)
{
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
