#include "Inimigo.h"

Inimigo::Inimigo(GerenciadorGrafico* g, float x, float y, float w, float h, Colisao c, int v, Animacao a): Personagem(g, x, y, w, h, c, v, a)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::executar(float dt)
{
  y0 = y;
  y += vy;
  vy += 2;
  anim.executar(dt);
}

void Inimigo::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gGraf)[4]);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gGraf->getWindow()->draw(r);
}