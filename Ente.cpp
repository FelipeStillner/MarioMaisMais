#include "Ente.h"

int Ente::I = 0;

Ente::Ente(GerenciadorGrafico* g)
{
  id = I;
  I++;
  gGraf = g;
}

Ente::~Ente()
{
}

 void Ente::setg(GerenciadorGrafico * pG)
{
  if(pG){gG= pG;}
}
 GerenciadorGrafico * Ente::getgG ()
{
  return (gG);
}
GerenciadorGrafico * Ente::gG = NULL;