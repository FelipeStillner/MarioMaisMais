#pragma once 

#include "Personagem.h"

class Inimigo : public Personagem
{
private:

public:
  Inimigo(float x = 0, float y = 0, float w = 0, float h = 0, int t = 0, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
  ~Inimigo();
  virtual void executar(float dt);
  virtual void imprimir();
  int getTipo();
};

