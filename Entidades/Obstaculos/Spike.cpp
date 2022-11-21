#include "Spike.h"
#include "../Personagens/Inimigo.h"

Spike::Spike(float x, float y, float d) : Obstaculo(x, y, 180, 160, Colisao(10, 10, 160, 140))
{
  dano = d;
}

Spike::~Spike()
{
}

void Spike::executar(const float dt)
{
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
}

void Spike::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[15]);
  r.setTextureRect(sf::IntRect(0, 16, 18, -16));
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

const int Spike::getTipo() const
{
  return SPIK;
}

const int Spike::getDano() const
{
  return dano;
}

void Spike::obstacular(Personagem* e, int dir)
{
  if(e->getTipo() == PLAYER)
  {
    (*e) -= dano;
  }
  else
  {
    static_cast<Inimigo*>(e)->levarDano(dano);
  }
}
