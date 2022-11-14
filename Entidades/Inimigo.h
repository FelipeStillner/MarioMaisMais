#pragma once 

#include "Personagem.h"

namespace Entidades
{

namespace Personagens
{

class Inimigo : public Personagem
{
private:
  int danoColisao;
public:
  Inimigo(float x = 0, float y = 0, float w = 0, float h = 0, int v = 0, Colisao c = Colisao(), Animacao a = Animacao(), int d = 1);
  ~Inimigo();
  virtual void executar(float dt) = 0;
  virtual void imprimir() = 0;
  virtual int getTipo() = 0;
  virtual void levarDano(int d = 1);
  virtual void danar() = 0;
  int getDanoColisao();
  void setDanoColisao(int d);
};

}

}
