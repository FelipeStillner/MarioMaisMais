#include "GerenciadorColisoes.h"
#include "../Fase.h"

GerenciadorColisoes::GerenciadorColisoes(Fase* f)
{
  jog = f->jog;
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
  for (p = proj.begin(); p != proj.end(); p++)
  {
    // Projetil X Obstaculo: Projetil eh eliminado
    for (o = obst.begin(); o != obst.end(); o++)
    {
      if (colidindo(*p, *o))
      {
        proj.remove(*p);
      }
    }
    // Projetil X Personagem: Inimigo leva dano
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

  // Inimigo X Jogador: jogador leva dano
  for (i = inim.begin(); i != inim.end(); i++)
  {
    if (colidindo(jog, *i))
    {
      
    }
  }

  for (o = obst.begin(); o != obst.end(); o++)
  {
    // Obstaculo X Obstaculo: ambos voltam pra coordenada anterior na direcao da colisao
    for (o1 = o; o1 != obst.end(); o1++)
    {
      if (colidindo(*o1, *o))
      {
        
      }
    }
    // Personagem X Obstaculo: Personagem volta pra coordenada anterior na direcao da colisao
    for (i = inim.begin(); i != inim.end(); i++)
    {
      if (colidindo(*p, *i))
      {
        
      }
    }
    if (colidindo(*p, jog))
    {
      
    }
  }
}

void GerenciadorColisoes::push(Projetil* p)
{
  proj.push_back(p);
}

void GerenciadorColisoes::push(Obstaculo* o)
{
  obst.push_back(o);
}

void GerenciadorColisoes::push(Inimigo* i)
{
  inim.push_back(i);
}
