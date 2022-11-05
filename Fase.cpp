#include "Fase.h"
#include "Principal.h"
#include "Entidades/Jogador.h"

Fase::Fase(Principal* p) : Ente(p->getGerenciadorGrafico())
{
  prin = p;
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

void Fase::imprimir()
{
  sf::RectangleShape r;
  sf::RenderWindow* w = prin->getGerenciadorGrafico()->getWindow();
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

Jogador* Fase::getJogador()
{
  return jog;
}

void Fase::setJogador(Jogador* j)
{
  jog = j;
}
