#include "GerenciadorColisoes.h"
#include "../Fase.h"

GerenciadorColisoes::GerenciadorColisoes(): jog()
{
  jog =  NULL;
  jog2 = NULL;
}

GerenciadorColisoes::~GerenciadorColisoes()
{
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
    // Projetil X Obstaculo: Projetil eh eliminado
    for (o = obst.begin(); o != obst.end(); o++)
    {
      if (colidindo(*p, *o))
      {
        
        /*(*p)->~Projetil();
        f->getEntidades()->remove(*p);
        *p = NULL;
        break;*/
        
      }
    }
    if(*p == NULL)
    {
      continue;
    }
    // Projetil X Personagem: Inimigo leva dano e projetil eh eliminado
    for (i = inim.begin(); i != inim.end(); i++)
    {
      if (colidindo(*p, *i))
      {
        /*
        (**i) -= (*p)->getDano();
        (*p)->~Projetil();
        f->getEntidades()->remove(*p);
        *p = NULL;*/
        //reak;
        
      }
    }
    if(*p == NULL)
    {
      continue;
    }
    if (colidindo(*p, jog))
    {
      /*
      *jog -= (*p)->getDano();
      (*p)->~Projetil();
      f->getEntidades()->remove(*p);
      */
    }
    if (jog2 && colidindo(*p, jog2))
    {
      /*
      *jog2 -= (*p)->getDano();
      (*p)->~Projetil();
      f->getEntidades()->remove(*p);
      */
    }
  } 
  
  // Inimigo X Jogador: jogador leva dano e mudam posicao dependendo da direcao da colisao
  for (i = inim.begin(); i != inim.end(); i++)
  {
    if (colidindo(jog, *i))
    {
      int dir = direcaoColisao(jog, *i);
      (*jog) -= 1;
    }
       if (jog2 && colidindo(jog2, *i))
    {
      int dir = direcaoColisao(jog2, *i);
      (*jog2) -= 1;
    }
  }
  
  for (o = obst.begin(); o != obst.end(); o++)
  {
    // Obstaculo X Obstaculo: ambos voltam pra coordenada anterior na direcao da colisao
    for (o1 = o; o1 != obst.end(); o1++)
    {
      if (colidindo(*o1, *o))
      {
        //printf("a");
        //std::cout<<"a"<<std::endl;

        int dir = direcaoColisao(*o1, *o);
        (*o)->setY((*o)->getY0());
        (*o1)->setY((*o1)->getY0());
        (*o)->setVy(0);
        (*o1)->setVy(0);
      }
    }
    // Personagem X Obstaculo: Personagem volta pra coordenada anterior na direcao da colisao
    for (i = inim.begin(); i != inim.end(); i++)
    {
      if (colidindo(*o, *i))
      {
        int dir = direcaoColisao(*o, *i);
        (*o)->setY((*o)->getY0());
        (*i)->setY((*i)->getY0());
        (*o)->setVy(0);
        (*i)->setVy(0);
      }
    }
    if (colidindo(*o, jog))
    {
      int dir = direcaoColisao(*o, jog);
      (*o)->setY((*o)->getY0());
      (jog)->setY((jog)->getY0());
      (*o)->setVy(0);
      (jog)->setVy(0);
    }
    if (jog2 && colidindo(*o, jog2))
    {
      int dir = direcaoColisao(*o, jog2);
      (*o)->setY((*o)->getY0());
      (jog2)->setY((jog2)->getY0());
      (*o)->setVy(0);
      (jog2)->setVy(0);
    }
  }

}

void GerenciadorColisoes::incluir(Jogador* j)
{
  if(j)
  { if(!jog)
    {jog=j;}
    else
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
