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
  std::list<Inimigo*> inim = f->entidades.getInimigos();
  std::list<Obstaculo*> obst = f->entidades.getObstaculos();
  std::list<Projetil*> proj = f->entidades.getProjeteis();
  Jogador* jog = f->entidades.getJogador();
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
        f->entidades.remove(*p);
      }
    }
    // Projetil X Personagem: Inimigo leva dano e projetil eh eliminado
    for (i = inim.begin(); i != inim.end(); i++)
    {
      if (colidindo(*p, *i))
      {
        (*i)->operator--();
      }
    }
    if (colidindo(*p, jog))
    {
      jog--;
    }
  }

  // Inimigo X Jogador: jogador leva dano e mudam posicao dependendo da direcao da colisao
  for (i = inim.begin(); i != inim.end(); i++)
  {
    if (colidindo(jog, *i))
    {
      int dir = direcaoColisao(jog, *i);

    }
  }

  for (o = obst.begin(); o != obst.end(); o++)
  {
    // Obstaculo X Obstaculo: ambos voltam pra coordenada anterior na direcao da colisao
    for (o1 = o; o1 != obst.end(); o1++)
    {
      if (colidindo(*o1, *o))
      {
        int dir = direcaoColisao(jog, *i);
        
      }
    }
    // Personagem X Obstaculo: Personagem volta pra coordenada anterior na direcao da colisao
    for (i = inim.begin(); i != inim.end(); i++)
    {
      if (colidindo(*p, *i))
      {
        int dir = direcaoColisao(jog, *i);

      }
    }
    if (colidindo(*p, jog))
    {
      int dir = direcaoColisao(jog, *i);
      
    }
  }
}
