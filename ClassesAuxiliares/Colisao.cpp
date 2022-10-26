#include "Colisao.h"
#include "../Entidades/Entidade.h"

Colisao::Colisao(int x, int y, int w, int h)
{
  this->x = x;
  this->y = y;
  width = w;
  height = h;
}

Colisao::~Colisao()
{
}

void Colisao::setWidth(const int n)
{
  width = n;
}

const int Colisao::getWidth() const
{
  return width;
}

void Colisao::setHeight(const int n)
{
  height = n;
}

const int Colisao::getHeight() const
{
  return height;
}

void Colisao::setX(const int n)
{
  x = n;
}

const int Colisao::getX() const 
{
  return x;
}

void Colisao::setY(const int n)
{
  y = n;
}

const int Colisao::getY() const 
{
  return y;
}


// Ideia para calcular a direcao da colisao: distancia entre os centros dos retangulos de colisao
int colidindo(Entidade *e1, Entidade *e2)
{
  int x1 = e1->getX()+e1->getColisao().getX(), x2 = e2->getX()+e2->getColisao().getX(), y1 = e1->getY()+e1->getColisao().getY(), y2 = e2->getY()+e2->getColisao().getY(),
    w1 = e1->getColisao().getWidth(), w2 = e2->getColisao().getWidth(), 
    h1 = e1->getColisao().getHeight(), h2 = e2->getColisao().getHeight();
  int colisao = 0;
  if(x1 <= x2 && x1 + w1 >= x2)
  {
    if(y1 <= y2 && y1 + h1 >= y2)
    {
      colisao = 1;
    }
    else if(y1 <= y2 + h2 && y1+ h1 >= y2 + h2)
    {
      colisao = 1;
    }
  }
  else if(x1 <= x2 + w2 && x1 + w1 >= x2 + w2)
  {
    if(y1 <= y2 && y1 + h1 >= y2)
    {
      colisao = 1;
    }
    else if(y1 <= y2 + h2 && y1 + h1 >= y2 + h2)
    {
      colisao = 1;
    }
  }
  //return colisao;
  if (!colisao)
  {
    return 0;
  }
  float Dvx = x2 - e2->getX0() - (x1 - e1->getX0());
  float Dvy = y2 - e2->getY0() - (y1 - e1->getY0());


  if (Dvy > 0)// e1 embaixo de e2
  {
    return BAIXO;
  }
  else if (Dvy < 0)// e1 emcima de e2
  {
    return CIMA;
  }
  else if (Dvx > 0)
  {
    return 1;
  }
  else
  {
    return 1;
  }
}
