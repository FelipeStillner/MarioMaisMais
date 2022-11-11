#include "Andador.h"

Andador::Andador(float x, float y, int v): Inimigo(x, y, 160, 160, v, Colisao(10, 10, 140, 140), Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12"))
{
}

Andador::~Andador()
{
}

void Andador::executar(float dt)
{
  y0 = y;
  y += vy;
  vy += 2;
  anim.executar(dt);
}

void Andador::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[4]);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int Andador::getTipo()
{
  return ENEM1;
}
