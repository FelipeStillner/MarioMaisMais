#pragma once

#include "Afix.h"
#include "Entidade.h"
#include "ListaEntes.h"

class Personagem : public Entidade
{
private:
  int vida;
public:
  Personagem();
  Personagem(int n, Entidade e);
  ~Personagem();
};
