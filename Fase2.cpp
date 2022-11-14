#include "Fase2.h"

Fase2::Fase2(Principal* prin) : Fase(prin)
{
  background = (*gG)[3];
  mltply = true;

  create(PLAYER, 1000.0, 200.0);
  create(PLAYER, 500.0, 200.0);
  create(ENEM1, 2000.0, 400.0);
  create(ENEM2, 2400.0, 300.0);
  create(ENEM3, 1400.0, 400.0);
  create(MOLA, 800.0, 0.0);
  create(TUBO, 1000.0, 600.0);
  create(SPIK, 0, 400);
  create(BAND, 2800.0, 0.0);
  create(TUBO, 1600.0, 600.0);
  create(TUBO, 2200.0, 600.0);
  create(CHAO, 0.0, 700.0);
  create(CHAO, 1800.0, 700.0);
}

Fase2::~Fase2()
{
}