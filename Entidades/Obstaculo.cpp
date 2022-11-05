#include "Obstaculo.h"

Obstaculo::Obstaculo(float x, float y, float w, float h,  int t, Colisao c)  : Entidade(x, y, w, h, t, c)
{
}

Obstaculo::~Obstaculo()
{
}


void Obstaculo::executar(float dt)
{
}

void Obstaculo::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[2]);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}
