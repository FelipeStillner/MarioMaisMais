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
  Colisao(int x = 0, int y = 0);
  ~Colisao();
  void setWidth(const int n);
  const int getWidth() const;
  void setHeight(const int n);
  const int getHeight() const;
};

int colidindo(Entidade *e1, Entidade *e2);
