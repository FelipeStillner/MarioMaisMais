#include "Lancador.h"

Lancador::Lancador(Fase* f, float x, float y, int v): Inimigo(x, y, 210, 280, v, Colisao(60, 90, 140, 180), Animacao(sf::IntRect(48, 0, -24, 32), 1.0, "12"), 1)
{
  this->f = f;
  tLan = 0;
}

Lancador::~Lancador()
{
}

void Lancador::executar(const float dt)
{
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
  anim.executar(dt);
  tLan += dt;
  danar();
}

void Lancador::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[9]);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

int const Lancador::getTipo() const
{
  return ENEM2;
}

void Lancador::danar()
{
  if(tLan > 2)
  {  
    tLan = 0;
    Projetil* p = static_cast<Projetil*>(f->createProjetil(x - 80 , y + 100));
    p->setVy(-Vel/2);
    p->setVx(-Vel);
  }
}