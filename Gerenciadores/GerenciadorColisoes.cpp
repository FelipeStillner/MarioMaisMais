#include "GerenciadorColisoes.h"
#include "../Fase.h"

GerenciadorColisoes::GerenciadorColisoes(Fase* f)
{
  this->f = f;
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

void GerenciadorColisoes::executar()
{
  // Para cada combinacao de {obstaculo, projetil, jogador, inimigo, etc.}
  // Fazer uma interacao diferente
  std::list<Inimigo*> inim = f->getEntidades()->getInimigos();
  std::list<Obstaculo*> obst = f->getEntidades()->getObstaculos();
  std::list<Projetil*> proj = f->getEntidades()->getProjeteis();
  Jogador* jog = f->getEntidades()->getJogador();
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
        (*p)->~Projetil();
        f->getEntidades()->remove(*p);
      }
    }
    // Projetil X Personagem: Inimigo leva dano e projetil eh eliminado
    for (i = inim.begin(); i != inim.end(); i++)
    {
      if (colidindo(*p, *i))
      {
        (**i) -= (*p)->getDano();
        (*p)->~Projetil();
        f->getEntidades()->remove(*p);
      }
    }
    if (colidindo(*p, jog))
    {
      *jog -= (*p)->getDano();
      (*p)->~Projetil();
      f->getEntidades()->remove(*p);
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
  }
  
  for (o = obst.begin(); o != obst.end(); o++)
  {
    // Obstaculo X Obstaculo: ambos voltam pra coordenada anterior na direcao da colisao
    for (o1 = o; o1 != obst.end(); o1++)
    {
      if (colidindo(*o1, *o))
      {
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
  }
}
