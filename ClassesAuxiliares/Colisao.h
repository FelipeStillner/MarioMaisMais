#pragma once

#define NAOCOLIDIU 0
#define BAIXO 1
#define CIMA 2
#define DIREITA 3
#define ESQUERDA 4

class Entidade;

class Colisao
{
private:
  int width;
  int height;
public:
  Colisao();
  Colisao(int x, int y);
  ~Colisao();
  void setWidth(int n);
  int getWidth();
  void setHeight(int n);
  int getHeight();
};

int colidindo(Entidade *e1, Entidade *e2);
