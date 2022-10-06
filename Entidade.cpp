#include "Entidade.h"

Entidade::Entidade() : Ente(), anim()
{
  text = NULL;
  col = NULL;
}

Entidade::Entidade(int i) : Ente(i), anim()
{
  text = NULL;
  col = NULL;
}

Entidade::Entidade(int i, float x, float y) : Ente(i), anim()
{
  this->x = x;
  this->y = y;
  text = NULL;
  col = NULL;
}

Entidade::Entidade(int i, float x, float y, sf::Texture* t) : Ente(i)
{
  this->x = x;
  this->y = y;
  text = t;
  col = NULL;
}

Entidade::Entidade(int i, float x, float y, sf::Texture* t, Animacao a) : Ente(i)
{
  this->x = x;
  this->y = y;
  text = t;
  anim = new Animacao(a);
  col = NULL;
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