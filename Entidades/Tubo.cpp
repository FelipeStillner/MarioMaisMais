#include "Tubo.h"

Tubo::Tubo(float x, float y) : Obstaculo(x, y, 320, 320, Colisao(10, 10, 300, 300))
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
  r.setTexture((*gG)[2]);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int Tubo::getTipo()
{
  return TUBO;
}
