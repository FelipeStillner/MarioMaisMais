#include "Inimigo.h"

Inimigo::Inimigo(float x, float y, int v): Personagem(x, y, 160, 160, v, Colisao(10, 10, 140, 140), Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12"))
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
  r.setTexture((*gG)[4]);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int Inimigo::getTipo()
{
  return ENEM1;
}
