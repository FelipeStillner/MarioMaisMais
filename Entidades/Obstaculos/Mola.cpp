#include "Mola.h"

Mola::Mola(float x, float y, int f) : Obstaculo(x, y, 160, 160, Colisao(10, 10, 140, 140))
{
  forca = f;
}

Mola::~Mola()
{
}

void Mola::executar(float dt)
{
  y0 = y;
  y += vy;
  vy += 2;
}

void Mola::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[12]);
  r.setTextureRect(sf::IntRect(0,0, 16, 16));
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int Mola::getTipo()
{
  return MOLA;
}

int Mola::getForca()
{
  return forca;
}