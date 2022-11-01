#include "Fase.h"
#include "Principal.h"
#include "Entidades/Jogador.h"

Fase::Fase(Principal* p) : Ente(), gCol(this)
{
  isPlaying = true;
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
}

void Fase::imprimir(sf::RenderWindow* rw)
{
  sf::RectangleShape r;
  r.setOrigin(0, 0);
  r.setSize(sf::Vector2f(rw->getSize().x, rw->getSize().y));
  r.setTexture(background);
  rw->draw(r);
  entidades.imprimir(rw);
}
