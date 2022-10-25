#include "Jogador.h"


Jogador::Jogador(float x, float y, float w, float h, sf::Texture* t, Colisao c, int v, Animacao a): Personagem(x, y, w, h, t, c, v, a)
{
}

Jogador::~Jogador()
{
}

void Jogador::executar(float dt)
{
  anim.executar(dt);
}