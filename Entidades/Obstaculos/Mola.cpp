#include "Mola.h"

Mola::Mola(float x, float y, int f) : Obstaculo(x, y, 160, 160, Colisao(10, 10, 140, 140))
{
  forca = f;
}

Mola::~Mola()
{
}

void Mola::executar(const float dt)
{
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
}

void Mola::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[12]);
  r.setTextureRect(sf::IntRect(0,0, 16, 16));
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

const int Mola::getTipo() const
{
  return MOLA;
}

const int Mola::getForca() const
{
  return forca;
}

void Mola::obstacular(Personagem* e, int dir)
{
  if(dir == VER)
  {
    if(e->getTipo() == PLAYER)
    {
      e->setVy(-forca);
    }
    else
    {
      e->setVy(-2*forca/3);
    }
  }
}
