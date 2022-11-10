#include "Tubo.h"

Tubo::Tubo(float x, float y) : Obstaculo(x, y, 1920, 320, Colisao(10, 10, 1900, 300))
{
}

Tubo::~Tubo()
{
}

void Tubo::executar(float dt)
{
}

void Tubo::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[5]);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int Tubo::getTipo()
{
  return OBS1;
}
