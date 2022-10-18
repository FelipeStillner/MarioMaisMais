#include "Colisao.h"
#include "../Entidades/Entidade.h"

Colisao::Colisao()
{
}

Colisao::Colisao(int x, int y)
{
  width = x;
  height = y;
}

Colisao::~Colisao()
{
}

void Colisao::setWidth(int n)
{
  width = n;
}

int Colisao::getWidth()
{
  return width;
}

void Colisao::setHeight(int n)
{
  height = n;
}

int Colisao::getHeight()
{
  return height;
}

int colidindo(Entidade *e1, Entidade *e2)
{
  if(e1->col == NULL)
  {
    std::cout << "NULL e1";
    return 0;
  }
  if(e1->col == NULL)
  {
    std::cout << "NULL e2";
    return 0;
  }
  int colisao = 0;
  if(e1->x <= e2->x && e1->x + e1->col->getWidth() >= e2->x)
  {
    if(e1->y <= e2->y && e1->y + e1->col->getHeight() >= e2->y)
    {
      colisao = 1;
    }
    else if(e1->y <= e2->y + e2->col->getHeight() && e1->y + e1->col->getHeight() >= e2->y + e2->col->getHeight())
    {
      colisao = 1;
    }
  }
  else if(e1->x <= e2->x + e2->col->getWidth() && e1->x + e1->col->getWidth() >= e2->x + e2->col->getWidth())
  {
    if(e1->y <= e2->y && e1->y + e1->col->getHeight() >= e2->y)
    {
      colisao = 1;
    }
    else if(e1->y <= e2->y + e2->col->getHeight() && e1->y + e1->col->getHeight() >= e2->y + e2->col->getHeight())
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
