#include "Fase.h"
#include "Principal.h"
#include "Entidades/Jogador.h"

Fase::Fase(Principal* p) : Ente()
{
  prin = p;
  jogando = true;
  mltply= false;
}

Fase::~Fase()
{
  
}

void Fase::executar(float dt)
{
  entidades.executar(dt);
}

void Fase::gerenciarColisoes()
{
  gCol.executar();
}

void Fase::imprimir()
{
  sf::RectangleShape r;
  sf::RenderWindow* w =gG->getWindow();
  r.setOrigin(- jog->getX() + (w->getSize().x/2),0);
  r.setSize(sf::Vector2f(w->getSize().x, w->getSize().y));
  r.setTexture(background);
  w->draw(r);
  entidades.imprimir();
}

ListaEntidades* Fase::getEntidades()
{
  return &entidades;
}

bool Fase::getJogando()
{
  return jogando;
}

void Fase::setJogando(bool n)
{
  jogando = n;
}

Jogador* Fase::getJogador(int i)
{
  if(i==1||!mltply){return jog;}
  else if(i==2){return jog2;}
  
}

void Fase::setJogador(Jogador* j,int i)
{
  if(i==1||!mltply){jog = j;}
  else if(i==2){jog2=j;}
}

  void Fase::setMltplyr(bool m)
  {
    mltply = m;
  }
  const bool Fase::getMltplyr() const 
  {
    return(mltply);
  }