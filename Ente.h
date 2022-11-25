#pragma once

#include "Afix.h"
#include "Gerenciadores/GerenciadorGrafico.h"

using namespace Gerenciadores;

class Ente
{
protected:
  int id;
  static int I;
  static GerenciadorGrafico * gG;
public:
  Ente();
  Ente(int i);
  virtual ~Ente();
  static void setgG(GerenciadorGrafico * pG);
  static  GerenciadorGrafico * getgG ();
  virtual void executar(float dt = 0) = 0;
  virtual void imprimir() = 0;
};
