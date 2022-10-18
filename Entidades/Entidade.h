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
  int x0;
  int y0;
  int vx;
  int vy;
  Animacao *anim;
  sf::Texture *text;
  Colisao* col;
public:
  Entidade(int i = nEntes, float x = 0, float y = 0, sf::Texture* t = NULL, Animacao* a = NULL, Colisao* c = NULL);
  ~Entidade();
  void executar(float dt);
  void imprimir(sf::RenderWindow *rw);
  void setAnimacao(Animacao a);
  void setColisao(Colisao c);
  void setTextura(sf::Texture* t);
  void setX(int x);
  void setY(int y);
  const Animacao* getAnimacao();
  const Colisao* getColisao();
  const sf::Texture* getTextura();
  const int getX();
  const int getY();
  const int getX0();
  const int getY0();
};
