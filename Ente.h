#pragma once

#include "Afix.h"
#include"Gerenciadores/GerenciadorGrafico.h"

using namespace Gerenciadores;

class Ente
{
protected:
  int id;
  static int I;
  static GerenciadorGrafico * gG;
public:
  Ente();
  static void setg(GerenciadorGrafico * pG);
  static  GerenciadorGrafico * getgG ();
  virtual ~Ente();
  virtual void executar(float dt = 0) = 0;
  virtual void imprimir() = 0;
};
