#include "Personagem.h"

Personagem::Personagem(float x, float y, float w, float h, int v, Colisao c, Animacao a) : Entidade(x, y, w, h, c), anim(a)
{
  vida = v;
}

Personagem::~Personagem()
{
}

void Personagem::setVida(const int n)
{
  vida = n;
}

void Personagem::setAnimacao(const Animacao a)
{
  anim = a;
}

const int Personagem::getVida() const 
{
  return vida;
}

const Animacao Personagem::getAnimacao() const
{
  return anim;
}

void Personagem::operator+=(const int n)
{
  vida += n;
}

void Personagem::operator-=(const int n)
{
  vida -= n;
}

