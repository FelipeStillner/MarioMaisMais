#include "Obstaculo.h"

Obstaculo::Obstaculo(GerenciadorGrafico* g, float x, float y, float w, float h, Colisao c)  : Entidade(g, x, y, w, h, c)
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
  r.setTexture((*gGraf)[2]);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gGraf->getWindow()->draw(r);
}
