#include "ListaEntes.h"

ListaEntes::ListaEntes()
{
}

ListaEntes::~ListaEntes()
{
  std::list<Ente*>::iterator i;
  for (i = lista.begin(); i != lista.end(); i++)
  {
    delete *i;
  }
  lista.clear();
}

void ListaEntes::push(Ente* e)
{
  lista.push_back(e);
}

void ListaEntes::push(Entidade* e)
{
  lista.push_back(static_cast<Ente*>(e));
}

std::list<Ente*> ListaEntes::getLista()
{
  return lista;
}

void ListaEntes::executar(float dt)
{
  std::list<Ente*>::iterator i;
  for (i = lista.begin(); i != lista.end(); i++)
  {
    (*i)->executar(dt);
  }
}

void ListaEntes::imprimir(sf::RenderWindow* w)
{
  std::list<Ente*>::iterator i;
  for (i = lista.begin(); i != lista.end(); i++)
  {
    (*i)->imprimir(w);
  }
}