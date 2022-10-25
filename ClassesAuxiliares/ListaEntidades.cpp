#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
}

ListaEntidades::~ListaEntidades()
{
  lista.clear();
}

void ListaEntidades::push(Entidade* e)
{
  lista.push_back(e);
}

std::list<Entidade*> ListaEntidades::getLista()
{
  return lista;
}

void ListaEntidades::executar(float dt)
{
  std::list<Entidade*>::iterator i;
  for (i = lista.begin(); i != lista.end(); i++)
  {
    (*i)->executar(dt);
  }
}

void ListaEntidades::imprimir(sf::RenderWindow* w)
{
  std::list<Entidade*>::iterator i;
  for (i = lista.begin(); i != lista.end(); i++)
  {
    (*i)->imprimir(w);
  }
}

Entidade* ListaEntidades::operator[](int n)
{
  std::list<Entidade*>::iterator i = lista.begin();
  if(n > lista.size())
  {
    return NULL;
  }
  while (n>0)
  {
    i++;
    n--;
  }
  return *i;
}