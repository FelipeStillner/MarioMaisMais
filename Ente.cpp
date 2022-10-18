#include "Ente.h"

int Ente::nEntes = 0;

Ente::Ente(int i)
{
  nEntes++;
  id = i;
}

Ente::~Ente()
{
}
