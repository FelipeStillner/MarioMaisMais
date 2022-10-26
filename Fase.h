#pragma once

#include "Afix.h"
#include "Ente.h"
#include "ClassesAuxiliares/ListaEntidades.h"

class Fase : public Ente
{
private:
  ListaEntidades entidades;
  sf::Texture* background;
public:
  Fase();
  virtual ~Fase();
  virtual void executar(float dt);
  void gerenciarColisoes();
};
