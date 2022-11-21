#include "Bowser.h"
#include "../../Fases/Fase2.h"

Bowser::Bowser(Fase2* f, float x, float y, int v): Inimigo(x, y, 320, 480, v, Colisao(40, 10, 270, 460), Animacao(sf::IntRect(0, 0, 32, 48), 0.25, "1234"), 2)
{
  this->f = f;
  tProj = 0.1;
  t = NULL;
}

Bowser::~Bowser()
{
}

void Bowser::executar(float dt)
{
  y0 = y;
  y = y + vy*dt;
  vy += Grav;
  anim.executar(dt);
  tProj += dt;
  danar();
}

void Bowser::imprimir()
{
  sf::RectangleShape r;
  r.setTexture((*gG)[21]);
  r.setTextureRect(anim.rect);
  r.setPosition(x, y);
  r.setSize(sf::Vector2f(w, h));
  gG->getWindow()->draw(r);
}

void Bowser::levarDano(int d)
{
  vida -= d;
  if(vida <= 0)
  {
    setAtivo(false);
  }  
}

int Bowser::getTipo()
{
  return BOSS;
}

void Bowser::danar()
{
  if(tProj > 2)
  {  
    tProj = 0;
    int n = rand()%3+1;
    Projetil* p = static_cast<Projetil*>(f->createProjetil(x - 20, y + 140));
    p->setVy(-(Vel/4)*n+1);
    p->setVx(-Vel/2);
  }
  if (!t || !(t->getAtivo()))
  {
    t = f->createTartaruga(x+100, y+200);
    t->setVx(5);
  }
}
