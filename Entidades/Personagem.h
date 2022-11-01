#pragma once

#include "Entidade.h"
#include "../ClassesAuxiliares/Animacao.h"

class Personagem : public Entidade
{
protected:
  int vida;
  Animacao anim;
public:
  Personagem(float x = 0, float y = 0, float w = 0, float h = 0, sf::Texture* t = NULL, Colisao c = Colisao(), int v = 0, Animacao a = Animacao());
  virtual ~Personagem();
  virtual void executar(float dt);
  virtual void imprimir(sf::RenderWindow *rw);
  void setAnimacao(Animacao a);
  const Animacao getAnimacao();
  void operator+=(int n);
  void operator-=(int n);
};
