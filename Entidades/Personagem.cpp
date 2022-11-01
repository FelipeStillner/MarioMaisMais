#include "Personagem.h"

Personagem::Personagem(float x, float y, float w, float h, sf::Texture* t, Colisao c, int v ,Animacao a) : Entidade(x, y, w, h, t, c), anim(a)
{
  vida = v;
}

Personagem::~Personagem()
{
}

void Personagem::executar(float dt)
{
  anim.executar(dt);
}

void Personagem::imprimir(sf::RenderWindow *rw)
{
  sf::RectangleShape r;
  r.setTexture(text);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  rw->draw(r);
}

void Personagem::setAnimacao(Animacao a)
{
  anim = a;
}

const Animacao Personagem::getAnimacao()
{
  return anim;
}

void Personagem::operator+=(int n)
{
  vida += n;
}

void Personagem::operator-=(int n)
{
  vida -= n;
}
