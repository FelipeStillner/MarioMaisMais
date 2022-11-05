#pragma once

#include "Afix.h"
#include "Gerenciadores/GerenciadorGrafico.h"

class Ente
{
protected:
  int id;
  static int I;
  GerenciadorGrafico* gGraf;
public:
  Ente(GerenciadorGrafico* g);
  virtual ~Ente();
  virtual void executar(float dt = 0) = 0;
  virtual void imprimir() = 0;
};
