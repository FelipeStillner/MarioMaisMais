#include "ListaEntidades.h"

ListaEntidades::ListaEntidades()
{
  jog = NULL;
}

ListaEntidades::~ListaEntidades()
{
  inim.clear();
  obst.clear();
  proj.clear();
}

void ListaEntidades::push(Inimigo* e)
{
  inim.push_back(e);
}

void ListaEntidades::push(Obstaculo* e)
{
  obst.push_back(e);
}

void ListaEntidades::push(Projetil* e)
{
  proj.push_back(e);
}

std::list<Inimigo*> ListaEntidades::getInimigos()
{
  return inim;
}

std::list<Obstaculo*> ListaEntidades::getObstaculos()
{
  return obst;
}

std::list<Projetil*> ListaEntidades::getProjeteis()
{
  return proj;
}

void ListaEntidades::remove(Inimigo* e)
{
  inim.remove(e);
}

void ListaEntidades::remove(Obstaculo* e)
{
  obst.remove(e);
}

void ListaEntidades::remove(Projetil* e)
{
  proj.remove(e);
}

void ListaEntidades::setJogador(Jogador* j)
{
  jog = j;
}

Jogador* ListaEntidades::getJogador()
{
  return jog;
}

void ListaEntidades::executar(float dt)
{
  std::list<Inimigo*>::iterator i;
  for (i = inim.begin(); i != inim.end(); i++)
  {
    (*i)->executar(dt);
  }
  std::list<Obstaculo*>::iterator o;
  for (o = obst.begin(); o != obst.end(); o++)
  {
    (*o)->executar(dt);
  }
  std::list<Projetil*>::iterator p;
  for (p = proj.begin(); p != proj.end(); p++)
  {
    (*p)->executar(dt);
  }
  jog->executar(dt);
}

void ListaEntidades::imprimir(sf::RenderWindow* w)
{
  std::list<Inimigo*>::iterator i;
  for (i = inim.begin(); i != inim.end(); i++)
  {
    (*i)->imprimir(w);
  }
  std::list<Obstaculo*>::iterator o;
  for (o = obst.begin(); o != obst.end(); o++)
  {
    (*o)->imprimir(w);
  }
  std::list<Projetil*>::iterator p;
  for (p = proj.begin(); p != proj.end(); p++)
  {
    (*p)->imprimir(w);
  }
  jog->imprimir(w);
}

Entidade* ListaEntidades::operator[](int n)
{
  if(n < inim.size())
  {
    std::list<Inimigo*>::iterator i = inim.begin();
    while(n > 0)
    {
      i++;
      n--;
    }
    return *i;
  }
  n -= inim.size();
  if(n < obst.size())
  {
    std::list<Obstaculo*>::iterator o = obst.begin();
    while(n > 0)
    {
      o++;
      n--;
    }
    return *o;
  }
  n -= obst.size();
  if(n < proj.size())
  {
    std::list<Projetil*>::iterator p = proj.begin();
    while(n > 0)
    {
      p++;
      n--;
    }
    return *p;
  }
  n -= proj.size();
  if(n == 0)
  {
    return jog;
  }
  return NULL;
}

int ListaEntidades::size()
{
  return inim.size() + proj.size() + obst.size() + 1;
}
