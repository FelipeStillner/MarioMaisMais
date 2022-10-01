#pragma once

#include "Afix.h"
#include "Ente.h"
#include "Animacao.h"

class Entidade : public Ente
{
public:
  int x;
  int y;
  Animacao anim;
  sf::Texture* text;
public:
  Entidade();
  Entidade(int i);
  Entidade(int i, float x, float y);
  Entidade(int i, float x, float y, sf::Texture* t);
  Entidade(int i, float x, float y, sf::Texture* t, Animacao a);
  ~Entidade();
  void executar(int dt);
  void imprimir(sf::RenderWindow *rw);
};
