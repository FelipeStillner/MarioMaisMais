#pragma once

#include "Afix.h"
#include "Ente.h"
#include "ClassesAuxiliares/ListaEntidades.h"

class Fase : public Ente
{
private:
  ListaEntidades entidades;
public:
  Fase();
  virtual ~Fase();
  virtual void executar(float dt);
  void gerenciarColisoes();
};

Fase::Fase() : Ente()
{
}

Fase::~Fase()
{
}

void Fase::executar(float dt)
{

}

void Fase::gerenciarColisoes()
{

}
