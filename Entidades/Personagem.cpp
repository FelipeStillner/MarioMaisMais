# include "Personagem.h"

Personagem::Personagem()
{
  anim = NULL;
}

Personagem::~Personagem()
{
}

void Personagem::executar(float dt)
{
  if(anim != NULL)
  {
    anim->executar(dt);
  }
}

void Personagem::imprimir(sf::RenderWindow *rw)
{
  sf::Sprite s(*text, anim->rect);
  s.setPosition(x, y);
  s.setScale(10, 10);
  rw->draw(s);
}

void Personagem::setAnimacao(Animacao a)
{
  if(anim == NULL)
  {
    anim = new Animacao();
  }
  *anim = a;
}

const Animacao* Personagem::getAnimacao()
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
