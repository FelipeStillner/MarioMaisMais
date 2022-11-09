#pragma once

#include "../Afix.h"



namespace Entidades
{
  class Entidade;
}

using namespace Entidades;

namespace ClassesAuxiliares
{

class Colisao
{
private:
  int x;
  int y;
  int width;
  int height;
public:
  Colisao(int x = 0, int y = 0, int w = 0, int h = 0);
  ~Colisao();
  void setWidth(const int n);
  const int getWidth() const;
  void setHeight(const int n);
  const int getHeight() const;
  void setX(const int n);
  const int getX() const;
  void setY(const int n);
  const int getY() const;
};

}

bool colidindo(Entidade *e1, Entidade *e2);
int direcaoColisao(Entidade *e1, Entidade *e2);

#define NAOCOLIDIU 0
#define BAIXO 1
#define CIMA -1
#define DIREITA 2
#define ESQUERDA -2
