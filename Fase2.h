#pragma once

#include "Fase.h"
#include"Entidades/Lancador.h"
#include"Entidades/Tartaruga.h"
#include"Entidades/Spike.h"
#include"Entidades/Mola.h"
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
  Fase2(Principal* p =  NULL);
  ~Fase2();
};

