#include "Spike.h"

Spike::Spike(float x, float y, float d) : Obstaculo(x, y, 180, 160, Colisao(10, 10, 160, 140))
{
  dano = d;
}

Spike::~Spike()
{
}

void Spike::executar(float dt)
{
  y0 = y;
  y += vy;
  vy += 2;
}

void Spike::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[15]);
  r.setTextureRect(sf::IntRect(0, 16, 18, -16));
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int Spike::getTipo()
{
  return SPIK;
}

int Spike::getDano()
{
  return dano;
}
