#include "Tartaruga.h"

Tartaruga::Tartaruga(float x, float y, int v): Inimigo(x, y, 120, 240, v, Colisao(10, 10, 100, 220), Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "12"), 1)
{
  casco = false;
  vx = -5;
}

Tartaruga::~Tartaruga()
{
}

void Tartaruga::executar(const float dt)
{
  if(x0 == x)
  {
    vx = -vx;
    if (!casco)
    {
      if(vx > 0)
      {
        anim = Animacao(sf::IntRect(0, 0, 16, 32), 0.25, "12");
      }
      else
      {
        anim = Animacao(sf::IntRect(32, 0, -16, 32), 0.25, "12");
      }
    }
  }
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
  x0 = x;
  x += vx;
  anim.executar(dt);
  danar();
}

void Tartaruga::imprimir()
{
  sf::RectangleShape r;
  if(casco)
  {
    r.setTexture((*gG)[11]);
    r.setTextureRect(anim.rect);
    r.setPosition(x, y);
    r.setSize(sf::Vector2f(w, h));
    gG->getWindow()->draw(r);
    return;
  }
  r.setTexture((*gG)[10]);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

void Tartaruga::levarDano(int d)
{
  vida -= d;
  if(vida <= 0)
  {
    setAtivo(false);
  }
  else if (vida == 1)
  {
    casco = true;
    anim = Animacao(sf::IntRect(0, 0, 16, 16), 0.25, "1234");
    h = 120;
    setHeight(100);
    vx *= 2;
  }
  
}

const int Tartaruga::getTipo() const
{
  return ENEM3;
}

void Tartaruga::danar()
{

}

void Tartaruga::setVx(const int v)
{
  vx = v;
}

const int Tartaruga::getVx() const
{
  return vx;
}