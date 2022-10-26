#include "Andador.h"

Andador::Andador(float x, float y, float w, float h,  sf::Texture* t, Colisao c, int v ,Animacao a) : Inimigo(x, y, w, h, t, c, v, anim)
{
}

Andador::~Andador()
{
}

void Andador::executar(float dt)
{
  anim.executar(dt);
}
