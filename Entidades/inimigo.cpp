#include "Inimigo.h"

Inimigo::Inimigo(float x, float y, float w, float h, sf::Texture* t, Colisao c, int v, Animacao a): Personagem(x, y, w, h, t, c, v, a)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::executar(float dt)
{
  anim.executar(dt);
}