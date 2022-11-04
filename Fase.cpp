#include "Fase.h"
#include "Principal.h"
#include "Entidades/Jogador.h"

Fase::Fase(Principal* p) : Ente(), gCol(this)
{
  jogando = true;
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

void Fase::imprimir(sf::RenderWindow* rw)
{
  sf::RectangleShape r;
  r.setOrigin(- entidades.getJogador()->getX() + (rw->getSize().x/2),0);
  r.setSize(sf::Vector2f(rw->getSize().x, rw->getSize().y));
  r.setTexture(background);
  rw->draw(r);
  entidades.imprimir(rw);
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
