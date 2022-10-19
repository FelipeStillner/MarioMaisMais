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
