#include "ListaEntes.h"

ListaEntes::ListaEntes()
{
}

ListaEntes::~ListaEntes()
{
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

Ente* ListaEntes::operator[](int n)
{
  std::list<Ente*>::iterator i = lista.begin();
  while (n>0)
  {
    i++;
    if(i == lista.end())
    {
      return NULL;
    }
  }
  if(i == lista.end())
  {
    return NULL;
  }
  return *i;
}