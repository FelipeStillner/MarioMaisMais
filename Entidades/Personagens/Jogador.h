#pragma once

#include "Personagem.h"

namespace Entidades
{

namespace Personagens
{

class Jogador : public Personagem
{
protected:
  int estado;
  float tProj;
  int pont;
public:
  Jogador(float x = 0, float y = 0, int v = 0);
  ~Jogador();
  virtual void executar(const float dt);
  virtual void imprimir();
  int const getTipo() const;
  virtual void setEstado(const int est);
  const int getEstado() const;
  const float getTproj() const;
  void setTproj(const float t = 0);
  void somaPont(const int p);
  const int getPont() const ;
};

}

}

using namespace Personagens;

#define IDLE 0
#define WALKR 1
#define WALKL 2
#define JUMP 3
