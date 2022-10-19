#pragma once

#include "Entidade.h"

class Personagem : public Entidade
{
protected:
  int vida;
  Animacao anim;
public:
  Personagem(float x = 0, float y = 0, sf::Texture* t = NULL, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
  ~Personagem();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow *rw);
  void setAnimacao(Animacao a);
  const Animacao getAnimacao();
  void operator++();
  void operator--();
};
