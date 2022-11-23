#include "Andador.h"

Andador::Andador(float x, float y, int v): Inimigo(x, y, 160, 160, v, Colisao(10, 10, 140, 140), Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "12"), 1)
{
  vx = -300;
}

Andador::~Andador()
{
}

void Andador::executar(const float dt)
{
  if(x0 == x)
  {
    vx = -vx;
  }
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
  x0 = x;
  x = x + vx*dt;
  anim.executar(dt);
  danar();
}

void Andador::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[4]);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

const int Andador::getTipo() const
{
  return ENEM1;
}

const int Andador::getPontuacao() const
{
  return 10;
}
