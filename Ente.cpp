#include "Ente.h"

int Ente::nEntes = 0;

Ente::Ente()
{
  nEntes++;
}

Ente::Ente(int i)
{
  nEntes++;
  id = i;
}

Ente::~Ente()
{
  nEntes--;
}
