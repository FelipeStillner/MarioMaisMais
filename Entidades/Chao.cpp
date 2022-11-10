#include "Chao.h"

Chao::Chao(float x, float y) : Obstaculo(x, y, 1920, 320, Colisao(10, 10, 1900, 300))
{
}

Chao::~Chao()
{
}

void Chao::executar(float dt)
{
}

void Chao::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[5]);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int Chao::getTipo()
{
  return CHAO;
}
