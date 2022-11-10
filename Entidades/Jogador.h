#pragma once

#include "Personagem.h"

namespace Entidades
{

namespace Personagens
{

class Jogador : public Personagem
{
private:
  int estado;
public:
  Jogador(float x = 0, float y = 0, int v = 0);
  ~Jogador();
  virtual void executar(float dt);
  virtual void imprimir();
  void setEstado(const int est);
  const int getEstado() const;
  int getTipo();
};

}

}

using namespace Personagens;

#define IDLE 0
#define WALKR 1
#define WALKL 2
#define JUMP 3
