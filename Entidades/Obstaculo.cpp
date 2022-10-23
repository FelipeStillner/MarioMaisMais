#include "Obstaculo.h"

Obstaculo::Obstaculo(float x, float y, sf::Texture* t, Colisao c)  : Entidade(x, y, t, c)
{
}

Obstaculo::~Obstaculo()
{
}


void Obstaculo::executar(float dt)
{
  // A Fazer
}

void Obstaculo::imprimir(sf::RenderWindow *rw)
{
  sf::RectangleShape r;
  r.setTexture(text);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(col.getWidth(), col.getHeight()));
  rw->draw(r);
}
