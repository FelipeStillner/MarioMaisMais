#include "Personagem.h"

Personagem::Personagem(float x, float y, float w, float h, int t, Colisao c, int v ,Animacao a) : Entidade(x, y, w, h, t, c), anim(a)
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

void Personagem::setAnimacao(Animacao a)
{
  anim = a;
}

const int Personagem::getVida() const 
{
  return vida;
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
