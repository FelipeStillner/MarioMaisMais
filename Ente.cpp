#include "Ente.h"

int Ente::I = 0;

Ente::Ente()
{
  id = I;
  I++;
 
}

Ente::~Ente()
{
}

 void Ente::setgG(GerenciadorGrafico * pG)
{
  if(pG){gG= pG;}
}
 GerenciadorGrafico * Ente::getgG ()
{
  return (gG);
}
GerenciadorGrafico * Ente::gG = NULL;