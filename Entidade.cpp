#include "Entidade.h"

Entidade::Entidade() : Ente(), anim()
{
  text = NULL;
}

Entidade::Entidade(int i) : Ente(i), anim()
{
  text = NULL;
}

Entidade::Entidade(int i, float x, float y) : Ente(i), anim()
{
  this->x = x;
  this->y = y;
  text = NULL;
}

Entidade::Entidade(int i, float x, float y, sf::Texture* t) : Ente(i)
{
  this->x = x;
  this->y = y;
  text = t;
}

Entidade::Entidade(int i, float x, float y, sf::Texture* t, Animacao a) : Ente(i)
{
  this->x = x;
  this->y = y;
  text = t;
  anim = a;
}

Entidade::~Entidade()
{
  anim.~Animacao();
}

void Entidade::imprimir(sf::RenderWindow *rw)
{
  sf::Sprite s(*text, anim.rect);
  s.setPosition(x, y);
  rw->draw(s);
}

void Entidade::executar(int dt)
{
  anim.executar(dt);
}
