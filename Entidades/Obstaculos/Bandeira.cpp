#include "Bandeira.h"
#include "../../Fases/Fase.h"

Bandeira::Bandeira(Fase* f, float x, float y) : Obstaculo(x, y, 160, 1600, Colisao(10, 10, 140, 1580))
{
  this->f = f;
  anim = Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "1234");
}

Bandeira::~Bandeira()
{
}

void Bandeira::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[13]);
  r.setTextureRect(sf::IntRect(0, 0, 16, 160));
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
  r.setTexture((*gG)[14]);
  r.setTextureRect(anim.rect);
  r.setPosition(x+80, y+ 160);
  r.setSize(sf::Vector2f(160, 160));
  gG->getWindow()->draw(r);
}

void Bandeira::executar(const float dt)
{
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
  anim.executar(dt);
}

const int Bandeira::getTipo() const
{
  return BAND;
}

void Bandeira::obstacular(Personagem* e, int dir)
{
  if(e->getTipo() == PLAYER)
  {
    f->setGanhou(true);
    f->setJogando(false);
  }
}
