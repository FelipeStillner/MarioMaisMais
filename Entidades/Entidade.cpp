#include "Entidade.h"

Entidade::Entidade(int i, float x, float y, sf::Texture* t, Animacao* a, Colisao* c) : Ente(i)
{
  this->x = x;
  this->y = y;
  text = t;
  anim = a;
  col = c;
}

Entidade::~Entidade()
{
  anim->~Animacao();
  free(anim);
  free(col);
}

void Entidade::imprimir(sf::RenderWindow *rw)
{
  sf::Sprite s(*text, anim->rect);
  s.setPosition(x, y);
  s.setScale(10, 10);
  rw->draw(s);
}

void Entidade::executar(float dt)
{
  if (!(anim == NULL))
  {
    anim->executar(dt);
  }
  y += vy;
  vy += 1;
}

void Entidade::setAnimacao(Animacao a)
{
  if(anim == NULL)
  {
    anim = new Animacao;
  }
  *anim = a;
}

void Entidade::setColisao(Colisao c)
{
  if(col == NULL)
  {
    col = new Colisao;
  }
  *col = c;
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

const Animacao* Entidade::getAnimacao()
{
  return anim;
}

const Colisao* Entidade::getColisao()
{
  return col;
}

const sf::Texture* Entidade::getTextura()
{
  return text;
}

const int Entidade::getX()
{
  x0 = x;
  return x;
}

const int Entidade::getY()
{
  y0 = y;
  return y;
}

const int Entidade::getX0()
{
  return x0;
}

const int Entidade::getY0()
{
  return y0;
}
