#include "Inimigo.h"

Inimigo::Inimigo(float x, float y, float w, float h, int v, Colisao c, Animacao a, int d): Personagem(x, y, w, h, v, c, a)
{
  danoColisao = d;
}

Inimigo::~Inimigo()
{
}
