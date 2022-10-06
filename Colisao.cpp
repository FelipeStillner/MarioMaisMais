#include "Colisao.h"
#include "Entidade.h"

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
  if(e1->x <= e2->x && e1->x + e1->col->getWidth() >= e2->x)
  {
    if(e1->y <= e2->y && e1->y + e1->col->getHeight() >= e2->y)
    {
      return BAIXO; // e2 colidio a embaixo de e1
    }
    if(e1->y <= e2->y + e2->col->getHeight() && e1->y + e1->col->getHeight() >= e2->y + e2->col->getHeight())
    {
      return CIMA; // e2 colidio a emcima de e1
    }

  }
  if(e1->x <= e2->x + e2->col->getWidth() && e1->x + e1->col->getWidth() >= e2->x + e2->col->getWidth())
  {
    if(e1->y <= e2->y && e1->y + e1->col->getHeight() >= e2->y)
    {
      return BAIXO; // e2 colidio a embaixo de e1
    }
    if(e1->y <= e2->y + e2->col->getHeight() && e1->y + e1->col->getHeight() >= e2->y + e2->col->getHeight())
    {
      return CIMA; // e2 colidio a emcima de e1
    }
  }
  
  return 0;
}
