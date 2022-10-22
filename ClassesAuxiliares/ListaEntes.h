#pragma once

#include "../Afix.h"
#include "../Ente.h"
#include "../Entidades/Entidade.h"

class ListaEntes
{
private:
  std::list<Ente*> lista;
public:
  ListaEntes();
  ~ListaEntes();
  void push(Ente* e);
  void push(Entidade* e);
  std::list<Ente*> getLista();
  void executar(float dt);
  void imprimir(sf::RenderWindow* w);
  Ente* operator[](int n); 
};
