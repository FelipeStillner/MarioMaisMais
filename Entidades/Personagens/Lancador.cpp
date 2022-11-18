#include "Lancador.h"

Lancador::Lancador(Fase* f, float x, float y, int v): Inimigo(x, y, 160, 160, v, Colisao(10, 10, 140, 140), Animacao(sf::IntRect(0, 0, 64, 64), 0.25, "12"), 1)
{
  this->f = f;
  tLan = 0;
}

Lancador::~Lancador()
{
}

void Lancador::executar(float dt)
{
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
  anim.executar(dt);
  tLan += dt;
  if(tLan > 2)
  {  
    tLan = 0;
    Projetil* p = static_cast<Projetil*>(f->createProjetil(x + col.getX() + col.getWidth(), y));
    p->setVy(-31);
    p->setVx(1000);
    danar();
  }
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

int Lancador::getTipo()
{
  return ENEM2;
}

void Lancador::danar()
{
  
}