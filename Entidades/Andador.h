#pragma once

#include "Inimigo.h"

class Andador : public Inimigo
{
private:
public:
  Andador(float x = 0, float y = 0, float w = 0, float h = 0,  int t = 0, Colisao c = Colisao(), int v = 0 ,Animacao a = Animacao());
  ~Andador();
  void executar(float dt);
};


