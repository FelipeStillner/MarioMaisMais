#include "Obstaculo.h"

Obstaculo::Obstaculo(float x, float y, sf::Texture* t, Colisao c)  : Entidade(x, y, t, c)
{
}

Obstaculo::~Obstaculo()
{
}


void Obstaculo::executar(float dt)
{
  
}

void Obstaculo::imprimir(sf::RenderWindow *rw)
{
  sf::Sprite s(*text);
  s.setPosition(x, y);
  s.setScale(10, 10);
  rw->draw(s);
}
