#include "ListaEntidades.h"

ListaEntidades::ListaEntidades(): entidades()
{

}

ListaEntidades::~ListaEntidades()
{
  
}

void ListaEntidades::push(Entidade* e)
{
  entidades.incluaInfo(e);
}

Lista<Entidade>* ListaEntidades::getEntidades()
{
  return &entidades;
}

void ListaEntidades::remove(Entidade* e)
{
  // A fazer
}

void ListaEntidades::executar(float dt)
{
  int i;
  for (i = 0; i != entidades.getSize(); i++)
  {
    Entidade* e = entidades[i];
    if(e != NULL)
    {
       e->executar(dt);
    }
  }
}

void ListaEntidades::imprimir()
{
  int i;
  for (i = 0; i != entidades.getSize(); i++)
  {
    Entidade* e = entidades[i];
    if(e != NULL)
    {
       e->imprimir();
    }
  }
}

Entidade* ListaEntidades::operator[](int n)
{
  return entidades[n];
}

int ListaEntidades::size()
{
  return entidades.getSize();
}
