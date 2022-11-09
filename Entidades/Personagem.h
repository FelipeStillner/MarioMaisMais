#pragma once

#include "Entidade.h"
#include "../ClassesAuxiliares/Animacao.h"

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
  Personagem(float x = 0, float y = 0, float w = 0, float h = 0, int t =0, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
  virtual ~Personagem();
  virtual void executar(float dt) = 0;
  virtual void imprimir() = 0;
  void setVida(const int n);
  void setAnimacao(Animacao a);
  const int getVida() const;
  const Animacao getAnimacao();
  void operator+=(int n);
  void operator-=(int n);
 
};

}

}

using namespace Personagens;
