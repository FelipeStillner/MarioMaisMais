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
