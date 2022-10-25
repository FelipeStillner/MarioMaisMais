#include "Colisao.h"
#include "../Entidades/Entidade.h"

Colisao::Colisao(int x, int y)
{
  width = x;
  height = y;
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

int colidindo(Entidade *e1, Entidade *e2)
{ 
  int x1 = e1->getX(), x2 = e2->getX(), y1 = e1->getY(), y2 = e2->getY(),
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
  return colisao;
  if (!colisao)
  {
    return 0;
  }
  int vx1 = x1 - e1->getX0();
  int vy1 = y1 - e1->getY0();
  int vx2 = x2 - e2->getX0();
  int vy2 = y2 - e2->getY0();
  if(vx1 - vx2 > 0)
  {
    
  }
  if(vx1 - vx2 < 0)
  {
    
  }
  if(vy1 - vy2 > 0)
  {
    
  }
  if(vy1 - vy2 < 0)
  {
    
  }
}
