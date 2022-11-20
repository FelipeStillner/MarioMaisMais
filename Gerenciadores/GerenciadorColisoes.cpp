#include "GerenciadorColisoes.h"
#include "../Fases/Fase.h"
#include "../Entidades/Obstaculos/Mola.h"
#include "../Entidades/Obstaculos/Spike.h"

namespace Gerenciadores
{

GerenciadorColisoes::GerenciadorColisoes(Fase* f): jog()
{
  this->f = f;
  jog =  NULL;
  jog2 = NULL;
}

GerenciadorColisoes::~GerenciadorColisoes()
{
  limpagCOL();
  f = NULL;
}

void GerenciadorColisoes::executar()
{
  // Para cada combinacao de {obstaculo, projetil, jogador, inimigo, etc.}
  // Fazer uma interacao diferente
  std::list<Projetil*>::iterator p;
  std::list<Obstaculo*>::iterator o, o1;
  std::list<Inimigo*>::iterator i;
  int dir;
  
  for (p = proj.begin(); p != proj.end(); p++)
  {
    if(!(*p)->getAtivo())
    {
      continue;
    }
    // Projetil X Obstaculo: Projetil eh eliminado
    for (o = obst.begin(); o != obst.end(); o++)
    {
      if (colidindo(*p, *o))
      {
        (*p)->setAtivo(false);
        break;
      }
    }
    if(!(*p)->getAtivo())
    {
      continue;
    }
    // Projetil X Personagem: Inimigo leva dano e projetil eh eliminado
    for (i = inim.begin(); i != inim.end(); i++)
    {
      if(!(*i)->getAtivo())
      {
        continue;
      }
      if (colidindo(*p, *i))
      {
        (*i)->levarDano((*p)->getDano());
        (*p)->setAtivo(false);
        break;        
      }
    }
    if(!(*p)->getAtivo())
    {
      continue;
    }
    if (colidindo(*p, jog))
    {
      *jog -= (*p)->getDano();
      (*p)->setAtivo(false);
    }
    if(!(*p)->getAtivo())
    {
      continue;
    }
    if (jog2 && colidindo(*p, jog2))
    {
      *jog2 -= (*p)->getDano();
      (*p)->setAtivo(false);
    }
  } 
  
  // Inimigo X Jogador: jogador leva dano e mudam posicao dependendo da direcao da colisao
  for (i = inim.begin(); i != inim.end(); i++)
  {
    if(!(*i)->getAtivo())
    {
      continue;
    }
    if (colidindo(jog, *i))
    {
      int dir = direcaoColisao(jog, *i);
      if(dir == HOR || dir == TOTAL)
      {
        (jog)->setX((jog)->getX0());
        (*i)->setX((*i)->getX0());
        (*jog) -= (*i)->getDanoColisao();
      }
      if(dir == VER || dir == TOTAL)
      {
        (*i)->levarDano();
        jog->setVy(-Vel);
      }
    }
    if(!(*i)->getAtivo())
    {
      continue;
    }
    if (jog2 && colidindo(jog2, *i))
    {
      int dir = direcaoColisao(jog2, *i);
      if(dir == HOR || dir == TOTAL)
      {
        (jog2)->setX((jog2)->getX0());
        (*i)->setX((*i)->getX0());
        (*jog2) -= (*i)->getDanoColisao();
      }
      if(dir == VER || dir == TOTAL)
      {
        (*i)->levarDano();
        jog2->setVy(-31);
      }
    }
  }
  
  for (o = obst.begin(); o != obst.end(); o++)
  {
    // Obstaculo X Obstaculo: ambos voltam pra coordenada anterior na direcao da colisao
    for (o1 = o; o1 != obst.end(); o1++)
    {
      if(o1 == o)
      {
        continue;
      }
      if (colidindo(*o1, *o))
      {
        int dir = direcaoColisao(*o1, *o);
        if(dir == VER || dir == TOTAL)
        {
          (*o)->setY((*o)->getY0());
          (*o1)->setY((*o1)->getY0());
          (*o)->setVy(0);
          (*o1)->setVy(0);
        }
      }
    }
    // Personagem X Obstaculo: Personagem volta pra coordenada anterior na direcao da colisao
    for (i = inim.begin(); i != inim.end(); i++)
    {
      if (colidindo(*o, *i))
      {
        int dir = direcaoColisao(*o, *i);
        if(dir == HOR)
        {
          (*o)->setX((*o)->getX0());
          (*i)->setX((*i)->getX0());
        }
        if(dir == VER || dir == TOTAL)
        {
          (*o)->setY((*o)->getY0());
          (*i)->setY((*i)->getY0());
          (*o)->setVy(0);
          (*i)->setVy(0);
          if((*o)->getTipo() == MOLA)
          {
            Mola* m = static_cast<Mola*>(*o);
            (*i)->setVy(-m->getForca());
          }
          else if((*o)->getTipo() == SPIK)
          {
            Spike* s = static_cast<Spike*>(*o);
            (*i)->levarDano(s->getDano());
          }
        }
      }
    }
    if (colidindo(*o, jog))
    {
      if((*o)->getTipo() == SPIK)
      {
        Spike* s = static_cast<Spike*>(*o);
        (*jog) -= s->getDano();
      }
      if((*o)->getTipo() == BAND)
      {
        f->setGanhou(true);
        f->setJogando(false);
      }
      int dir = direcaoColisao(*o, jog);
      if(dir == HOR || dir == TOTAL)
      {
        (*o)->setX((*o)->getX0());
        (jog)->setX((jog)->getX0());
      }
      if(dir == VER || dir == TOTAL)
      {
        (*o)->setY((*o)->getY0());
        (jog)->setY((jog)->getY0());
        (*o)->setVy(0);
        (jog)->setVy(0);
        if((*o)->getTipo() == MOLA)
        {
          Mola* m = static_cast<Mola*>(*o);
          (jog)->setVy(-m->getForca());
        }
      }
    }
    if (jog2 && colidindo(*o, jog2))
    {
      if((*o)->getTipo() == SPIK)
      {
        Spike* s = static_cast<Spike*>(*o);
        (*jog) -= s->getDano();
      }
      int dir = direcaoColisao(*o, jog2);
      if(dir == HOR || dir == TOTAL)
      {
        (*o)->setX((*o)->getX0());
        (jog2)->setX((jog2)->getX0());
      }
      if(dir == VER || dir == TOTAL)
      {
        (*o)->setY((*o)->getY0());
        (jog2)->setY((jog2)->getY0());
        (*o)->setVy(0);
        (jog2)->setVy(0);
        if((*o)->getTipo() == MOLA)
        {
          Mola* m = static_cast<Mola*>(*o);
          (jog2)->setVy(-m->getForca());
        }
      }
    }
  }

}

void GerenciadorColisoes::incluir(Jogador* j)
{
  if(j)
  { if(!jog)
    {jog=j;}
    else if(!jog2)
    {jog2=j;}
  }
}

void GerenciadorColisoes::incluir(Projetil* p)
{
  if(p != NULL)
  {
    proj.push_back(p);
  }
}

void GerenciadorColisoes::incluir(Inimigo* i)
{
  if(i != NULL)
  {
    inim.push_back(i);
  }
}

void GerenciadorColisoes::incluir(Obstaculo* o)
{
  if(o != NULL)
  {
    obst.push_back(o);
  }
}

void GerenciadorColisoes::limpagCOL()
{ 
  proj.clear();
  proj.clear();
  inim.clear();
  obst.clear();
  jog=NULL;
  jog2=NULL;
}

}
