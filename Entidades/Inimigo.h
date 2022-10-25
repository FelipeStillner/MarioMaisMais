#pragma once 

#include "Personagem.h"

class Inimigo : public Personagem
{
private:

public:
  Inimigo(float x = 0, float y = 0, float w = 0, float h = 0, sf::Texture* t = NULL, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
  ~Inimigo();
  virtual void executar(float dt);
};
