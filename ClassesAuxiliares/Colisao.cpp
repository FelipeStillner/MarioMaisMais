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

// Checa apenas se houve colisao
bool colidindo(Entidades::Entidade *e1, Entidades::Entidade *e2)
{
  int x1 = e1->getX()+e1->getColisao().getX(), x2 = e2->getX()+e2->getColisao().getX(), y1 = e1->getY()+e1->getColisao().getY(), y2 = e2->getY()+e2->getColisao().getY(),
    w1 = e1->getColisao().getWidth(), w2 = e2->getColisao().getWidth(), 
    h1 = e1->getColisao().getHeight(), h2 = e2->getColisao().getHeight();

  if(x1 < x2 + w2 && x1 + w1 > x2 && y1 < y2 + h2 && y1 + h1 > y2)
  {
    return true;
  }
  return false;  
}

// Retorna a direcao da colisao
int direcaoColisao(Entidades::Entidade *e1, Entidades::Entidade *e2)
{
  int x1 = e1->getX()+e1->getColisao().getX(), x2 = e2->getX()+e2->getColisao().getX(), y1 = e1->getY()+e1->getColisao().getY(), y2 = e2->getY()+e2->getColisao().getY(),
    w1 = e1->getColisao().getWidth(), w2 = e2->getColisao().getWidth(), 
    h1 = e1->getColisao().getHeight(), h2 = e2->getColisao().getHeight();
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
    return DIREITA;
  }
  else
  {
    return ESQUERDA;
  }
}