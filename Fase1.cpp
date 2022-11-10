#include "Fase1.h"
#include "Principal.h"

Fase1::Fase1(Principal* prin) : Fase(prin)
{
  background = (*gG)[3];
  mltply = true;

  create(PLAYER, 400.0, 400.0);
  create(PLAYER, 500.0, 400.0);
  create(ENEM1, 1000.0, 600.0);
  create(TUBO, 1000.0, 800.0);
  create(CHAO, 0.0, 900.0);
}

Fase1::~Fase1()
{

}