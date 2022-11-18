#include "Luigi.h"

Luigi::Luigi(float x, float y, int v): Jogador(x, y, v)
{
}

Luigi::~Luigi()
{
}

void Luigi::imprimir()
{
  sf::Texture* t = NULL;
  switch (estado)
  {
  case IDLE:
    if(estado == WALKR)
    {
      t = (*gG)[19];
    }
    else
    {
      t = (*gG)[19];
    }
    break;
  
  case WALKR:
      t = (*gG)[18];
    break;

  case WALKL:
      t = (*gG)[18];
    break;
  
  case JUMP:
      t = (*gG)[20];
    break;
  
  default:
    break;
  }
  sf::RectangleShape r;
  r.setTexture(t);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}
