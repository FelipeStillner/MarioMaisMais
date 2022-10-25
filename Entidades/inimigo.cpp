#include "Inimigo.h"

Inimigo::Inimigo(float x, float y, sf::Texture* t, Colisao c, int v, Animacao a): Personagem(x, y, t, c, v, a)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::executar(float dt)
{
  anim.executar(dt);
}