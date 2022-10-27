#include "Fase.h"

Fase::Fase(Principal* p) : Ente()
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
  entidades.imprimir(rw);
}
