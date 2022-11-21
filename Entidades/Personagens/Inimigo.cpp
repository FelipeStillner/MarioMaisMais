
#include "Inimigo.h"

Inimigo::Inimigo(float x, float y, float w, float h, int v, Colisao c, Animacao a, int d): Personagem(x, y, w, h, v, c, a)
{
  danoColisao = d;
}

Inimigo::~Inimigo()
{
}

void Inimigo::levarDano(const int d)
{
  vida -= d;
  if(vida <= 0)
  {
    setAtivo(false);
  }
}

const int Inimigo::getDanoColisao() const
{
  return danoColisao;
}

void Inimigo::setDanoColisao(const int d)
{
  danoColisao = d;
}

