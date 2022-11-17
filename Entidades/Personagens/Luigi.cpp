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

void Luigi::setEstado(const int est)
{
  if(estado == est)
  {
    return;
  }

  switch (est)
  {
  case IDLE:
    if(estado == WALKR)
    {
      setAnimacao(Animacao(sf::IntRect(0, 0 ,16, 32)));
    }
    else
    {
      setAnimacao(Animacao(sf::IntRect(16, 0 ,-16, 32)));
    }
    break;
  
  case WALKR:
    setAnimacao(Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "1232"));
    break;

  case WALKL:
    setAnimacao(Animacao(sf::IntRect(48, 0, -16, 32), 0.25, "1232"));
    break;
  
  case JUMP:
    setAnimacao(Animacao(sf::IntRect(0, 0, 16, 32), 0.3, "12"));
    break;
  
  default:
    break;
  }
  estado = est;
}
