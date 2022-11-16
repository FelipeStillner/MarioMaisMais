#pragma once

#include "Fase.h"
#include "../Entidades/Personagens/Lancador.h"
#include "../Entidades/Personagens/Tartaruga.h"
#include "../Entidades/Obstaculos/Spike.h"
#include "../Entidades/Obstaculos/Mola.h"

namespace Fases
{

class Fase2 : public Fase
{
private:
public:
  virtual void gravaFase();
  virtual Fase* recFase();
  Lancador* createLancador(float x =0 , float y =0);
  Tartaruga* createTartaruga(float x =0 , float y =0);
  Mola* createMola(float x =0 , float y =0);
  Spike* createSpike(float x =0 , float y =0);
  Fase2();
  ~Fase2();
};

}
