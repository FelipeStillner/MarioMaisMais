#include "Obstaculo.h"

Obstaculo::Obstaculo(float x, float y, float w, float h,  int t, Colisao c)  : Entidade(x, y, w, h, t), col(c)
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
  r.setTexture(text);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int Obstaculo::getTipo()
{
    if(text==(*gG)[2]) {return(OBS1);}
  else if(text==(*gG)[5]){return(OBS2);}
}

Colisao Obstaculo::getColisao()
{
  return col;
}



