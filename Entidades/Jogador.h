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
  Jogador(float x = 0, float y = 0, float w = 0, float h = 0, int t = 0, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
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
