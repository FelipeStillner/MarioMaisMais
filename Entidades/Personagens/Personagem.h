#pragma once

#include "../Entidade.h"
#include "../../ClassesAuxiliares/Animacao.h"

namespace Entidades
{

namespace Personagens
{

class Personagem : public Entidade
{
protected:
  int vida;
  Animacao anim;
public:
  Personagem(float x = 0, float y = 0, float w = 0, float h = 0, int v = 0, Colisao c = Colisao(), Animacao a = Animacao());
  virtual ~Personagem();
  virtual void executar(const float dt) = 0;
  virtual void imprimir() = 0;
  void operator+=(const int n);
  void operator-=(const int n);
  void setVida(const int n);
  void setAnimacao(const Animacao a);
  const int getVida() const;
  const Animacao getAnimacao() const;
};

}

}

using namespace Personagens;
