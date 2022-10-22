# include "Personagem.h"

Personagem::Personagem(float x, float y, sf::Texture* t, Colisao c, int v ,Animacao a) : Entidade(x, y, t, c), anim(a)
{
  vida = v;
}

Personagem::~Personagem()
{
}

void Personagem::executar(float dt)
{
  anim.executar(dt);
  // Se personagem colidir com Obstaculo volta para posicao anterior/
}

void Personagem::imprimir(sf::RenderWindow *rw)
{
  sf::Sprite s(*text, anim.rect);
  s.setPosition(x, y);
  s.setScale(10, 10);
  rw->draw(s);
}

void Personagem::setAnimacao(Animacao a)
{
  anim = a;
}

const Animacao Personagem::getAnimacao()
{
  return anim;
}

void Personagem::operator++()
{
  vida++;
}

void Personagem::operator--()
{
  vida--;
}
