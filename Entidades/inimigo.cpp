#include "Inimigo.h"

Colisao Inimigo::col = Colisao(10, 10, 140, 140);

Inimigo::Inimigo(float x, float y, float w, float h, int t, int v, Animacao a): Personagem(x, y, w, h, t, v, a)
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

Colisao Inimigo::getColisao()
{
  return col;
}
