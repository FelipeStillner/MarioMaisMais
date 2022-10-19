#pragma once

#include "Entidade.h"

class Personagem : public Entidade
{
protected:
  int vida;
  Animacao *anim;
public:
  Personagem();
  ~Personagem();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow *rw);
  void setAnimacao(Animacao a);
  const Animacao* getAnimacao();
  void operator++();
  void operator--();
};
