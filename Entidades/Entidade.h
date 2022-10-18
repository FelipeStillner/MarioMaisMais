#pragma once

#include "../Afix.h"
#include "../Ente.h"
#include "../ClassesAuxiliares/Animacao.h"
#include "../ClassesAuxiliares/Colisao.h"

class Entidade : public Ente
{
public:
  int x;
  int y;
  int vx;
  int vy;
  Animacao *anim;
  sf::Texture *text;
  Colisao* col;
public:
  Entidade();
  Entidade(int i);
  Entidade(int i, float x, float y);
  Entidade(int i, float x, float y, sf::Texture* t);
  Entidade(int i, float x, float y, sf::Texture* t, Animacao a);
  ~Entidade();
  void executar(float dt);
  void imprimir(sf::RenderWindow *rw);
};
