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
  int colisao = 0;
  if(e1->getX() <= e2->getX() && e1->getX() + e1->getColisao().getWidth() >= e2->getX())
  {
    if(e1->getY() <= e2->getY() && e1->getY() + e1->getColisao().getHeight() >= e2->getY())
    {
      colisao = 1;
    }
    else if(e1->getY() <= e2->getY() + e2->getColisao().getHeight() && e1->getY()+ e1->getColisao().getHeight() >= e2->getY() + e2->getColisao().getHeight())
    {
      colisao = 1;
    }
  }
  else if(e1->getX() <= e2->getX() + e2->getColisao().getWidth() && e1->getX() + e1->getColisao().getWidth() >= e2->getX() + e2->getColisao().getWidth())
  {
    if(e1->getY() <= e2->getY() && e1->getY() + e1->getColisao().getHeight() >= e2->getY())
    {
      colisao = 1;
    }
    else if(e1->getY() <= e2->getY() + e2->getColisao().getHeight() && e1->getY() + e1->getColisao().getHeight() >= e2->getY() + e2->getColisao().getHeight())
    {
      colisao = 1;
    }
  }
  if (!colisao)
  {
    return 0;
  }
  int vx1 = e1->getX() - e1->getX0();
  int vy1 = e1->getY() - e1->getY0();
  int vx2 = e2->getX() - e2->getX0();
  int vy2 = e2->getY() - e2->getY0();
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
