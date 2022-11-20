#pragma once

#include "Fase.h"
#include "../Entidades/Personagens/Lancador.h"
#include "../Entidades/Personagens/Tartaruga.h"
#include "../Entidades/Obstaculos/Spike.h"
#include "../Entidades/Obstaculos/Mola.h"
#include "../Entidades/Personagens/Bowser.h"

namespace Fases
{

class Fase2 : public Fase
{
private:
public:
  Fase2();
  ~Fase2();
  virtual void gravaFase();
  virtual Fase* recFase();
  Bowser* createBowser(float x = 0 , float y = 0);
  Lancador* createLancador(float x = 0 , float y = 0);
  Tartaruga* createTartaruga(float x = 0 , float y = 0);
  Mola* createMola(float x = 0 , float y = 0);
  Spike* createSpike(float x = 0 , float y = 0);
  virtual int getTipo();
};

}
